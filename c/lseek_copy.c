#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



const char* FILENAME_R = "test";
const char* FILENAME_W = "test1";

const char* ERRMODE = "bad mode\n\tuse 0 to copy last 10 chars\n\tuse 1 to copy last 10 words\n\tuse 2 to copy last 10 lines\n\t3 for full copy\n";
const char* ERROPEN_R = "cannot open file to read";
const char* ERROPEN_W = "cannot open file to write";


int fd_r = -1;
int fd_w = -1;
/**
*   
*   \param mode 0 - last 10 chars, 1 - last 10 words, 2 - last 10 lines
*
**/
void lseekcopy(int mode) {
	int counter = 0;
	if(mode==1) counter--;
	char buf[1];

	if(mode < 0 || mode > 3) {
		write(STDERR_FILENO, ERRMODE, strlen(ERRMODE));
		_exit(1);
	}

	if(fd_r == -1 && (fd_r = open(FILENAME_R, O_RDONLY)) == -1) {
		perror(ERROPEN_R);
		_exit(1);
	}

	if(fd_w == -1 && (fd_w = open(FILENAME_W, O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1) {
		perror(ERROPEN_W);
		_exit(1);
	}

	lseek(fd_r, -1, SEEK_END);


	while(read(fd_r,buf,1)) {

		write(fd_w,buf,1);
		switch(mode) {
			case 0:
				counter++;
				break;
			case 1:
				if(*buf==' ' || *buf == '\t' || *buf == '\n') counter++;
				break;
			case 2:
				if(*buf == '\n') counter++;
				break;
		}

		if(counter==10)  break; 
		if(0>lseek(fd_r, -2, SEEK_CUR)) break;
	}
	
}

int main(int argc, const char* argv[]) {
	lseekcopy(atoi(argv[1]));
	return 0;
}