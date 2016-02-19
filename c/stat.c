#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


#define DB "db"

int ltime;
struct stat buff;
int dbfd = -1;
const int seektime = 60;
char str[30];

int init(int argc, const char** argv) {

	if(argc!=2) {
		printf("only one file may seek\n");
		return -1;
	}

	if( (dbfd = open(DB, O_TRUNC|O_CREAT|O_WRONLY)) ==-1 ) {
		perror(DB);
		return -1;
	}

	if(stat(argv[1], &buff)==-1) {
		perror(argv[1]);
		return -1;
	} else {
		ltime = buff.st_mtime;
	}

	sprintf(str, "%i %ld\n", ltime, buff.st_size);
	write(dbfd, str, strlen(str));
	return 0;
}

int cmp(const char** argv) {
	if(stat(argv[1], &buff)==-1) {
		perror(argv[1]);
		return -1;
	}

	if(buff.st_mtime!=ltime) {
		ltime = buff.st_mtime;
		sprintf(str, "%i %ld\n", ltime, buff.st_size);
		write(dbfd, str, strlen(str));
	}
	return 0;

}

int main(int argc, const char** argv) {
	int i;
	if(init(argc, argv)==-1) {
		return 1;
	}

	for (i = 0; i < seektime; ++i) {
		cmp(argv);
		sleep(60);
	}

	close(dbfd);

	return 0;
}