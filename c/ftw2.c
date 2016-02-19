#include <ftw.h>
#include <sys/stat.h>
#include <stdio.h>

int printname(const char* name, const struct stat *st, int hz) {
	printf("%i\n", name);
	return 0;
}

int main(void) {
	ftw(".", printname, 1);
	return 0;
}




