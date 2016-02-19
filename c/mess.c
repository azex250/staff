#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int fd = open("mess.dat", O_CREAT | O_TRUNC | O_WRONLY); 

int main(void) {
	int pid = fork();


	if(pid) {
		write(fd, "somerandomstaff\n", sizeof(char) * 16);
		close(fd);
	} else {
		write(fd, "SOMERANDOMSTAFF\n", sizeof(char) * 16);
	}

	return 0;
}