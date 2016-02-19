#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define DIRNAME "math"

DIR * mydir; 
struct dirent * dep; 
int i = 0;

int main(void) {
	mydir = opendir(DIRNAME);
	if(mydir == NULL) {
		perror("fail:");
		exit(1);
	}

	for(;;) {
		dep = readdir(mydir);
		if(dep == NULL) {
			if(i>0) {
				break;
			}					
			if(errno==0) {
				i++;
				rewinddir(mydir);	
				continue;
				perror("sd");
				//break;
			} else {
				perror("fail:");
				exit(2);
			}
		}
		printf("%s %ld\n", dep->d_name, dep->d_ino);
	}
	
	return 0;
}