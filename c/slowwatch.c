#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

struct stat buff;
int ltime;
int fd = -1;
int nread;
char strbuff[500];
int i;



int main(int argc, const char** argv ) {
	if(argc!=2) {
		return 1;
	}

	for(i=0; i<30; ++i) {
		if(stat(argv[1], &buff) ==-1) {
			perror(argv[1]);
			return 2;
		}

		if(buff.st_mtime!=ltime) {
			ltime=buff.st_mtime;

			if( (fd=open(argv[1], O_RDONLY)) == -1) {
				perror(argv[1]);
				return 3;
			}

			while(nread=read(fd, strbuff, 500)) {
				write(STDOUT_FILENO, strbuff, nread);
			}
			close(fd);
			fd = -1;
		} 

		sleep(30);
	}

	return 0;

}
