#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
	
#define R_FILE "test"
#define W_FILE "test1"
#define BUFF_SIZE 2

int main(void) {
	int r_fd = -1;
	int w_fd = -1;
	int offset = -1;
	char buff[BUFF_SIZE];

	if( (r_fd=open(R_FILE, O_RDONLY))==-1 ) {
		perror("cannot open file to read");
		return 1;
	}

	if( (w_fd=open(W_FILE, O_WRONLY|O_CREAT|O_TRUNC, 0666))==-1 ) {
		perror("cannot open file to write");
		return 2;
	}

	if( (offset=lseek(r_fd, 0, SEEK_END))==-1 ) {
		perror("cannot set offset");
		return 3;
	}

	for(;;) {
		if(offset>BUFF_SIZE) {
			offset=(lseek(r_fd, (offset-BUFF_SIZE), SEEK_SET));
			read(r_fd, buff, BUFF_SIZE);
			write(w_fd, buff, BUFF_SIZE);
		} else {
			lseek(r_fd, 0, SEEK_SET);
			read(r_fd, buff, offset);
			write(w_fd, buff, offset);
			close(r_fd);
			close(w_fd);
			return 0;
		}
	}

	return 0;
}

