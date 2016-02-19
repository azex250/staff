#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define BUFF_SIZE 500

int main(int argc, const char** argv) {
	int i;
	char buf[BUFF_SIZE];
	int nread;
	for(i=1; i<argc; ++i) {
		int fd =-1;
		if( (fd=open(argv[i], O_RDONLY))==-1 ) {
			perror(argv[i]);
			continue;
		}
		while( nread=read(fd,buf,BUFF_SIZE) ) {
			write(STDOUT_FILENO, buf, nread);
		}

		buf[0] = '\n';
		write(STDOUT_FILENO, buf, 1);

		close(fd);

	}
	return 0;
}