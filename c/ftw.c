#include <ftw.h>
#include <stdio.h>
int list(const char *patch, const struct stat* statp, int type) {
	if (type==FTW_D) {
		printf("*%-10s  %o\n", patch, statp->st_mode & 0777 );
	} else {		
		printf("%-10s  %o\n", patch, statp->st_mode & 0777 );
	}
	return 0;
}

int main(void) {
 	ftw(".",list,1);
	return 0;
}