#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int filesize(int fd) {
	int curr=lseek(fd, off_t(0), SEEK_CUR);
	if(curr==-1) _exit(1);

	int size=lseek(fd, off_t(0), SEEK_END);
	if(size==-1) _exit(1);

	lseek(fd, off_t(curr), SEEK_SET);
	return size;
}

int main(int argc, const char** argv) {
	int fd;
 	if((fd = open(argv[1], O_WRONLY))<0) {
 		perror("can't open file");
 	}
	int size = filesize(fd);
	printf("%ib\n", size);
	return 0;
}