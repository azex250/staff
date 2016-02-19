#include <dirent.h> 
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/syscall.h>

#define BUF_SIZE 1024

struct linux_dirent {
	long           d_ino;
	off_t          d_off;
	unsigned short d_reclen;
	char           d_name[];
};

struct linux_dirent* dp;
char buff[BUF_SIZE];
int nread, fd, offset = 0;


int main(int argc, char *argv[]) {
   	fd = open("ALALALA", O_RDONLY | O_DIRECTORY);
   	if(fd==-1)
		perror("open:");

	for(;;) {
		nread = syscall(SYS_getdents, fd, buff, BUF_SIZE);
		if(nread == -1){
			perror("nread:");
			break;
		}
		if(nread==0)
			break;

		while(offset<nread) {
			dp = (struct linux_dirent * ) (buff + offset);
			offset += dp->d_reclen;
			printf("%-15s ::: %li\n", dp->d_name, dp->d_ino);
		}
	}
	return 0;
}
