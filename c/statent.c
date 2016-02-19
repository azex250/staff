#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>


#define PATH(x) strcat(strcat(strcpy(path, DIRNAME),"/"),x)

#define DIRNAME "src"
#define FLAG true

DIR * dp = NULL;

char path[50];
struct dirent * de;
struct stat buf;

int main(void) {
	dp = opendir(DIRNAME);
	if(dp == NULL) {
		exit(2);
	}
	while(de = readdir(dp)) {
		if(!de->d_ino) 
			{ exit(1); }
		if(de->d_name[0]=='.' && FLAG) 
			{ continue; }

		if(0 > stat(PATH(de->d_name), &buf)) 
			{ exit(3); }

		if(S_ISDIR(buf.st_mode)) {
			printf("*%s\n", de->d_name);
		} else {
			printf("%s\n", de->d_name);
		}

		
	}
	return 0;
}