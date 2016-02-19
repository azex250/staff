#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

const char* filename = "test";
int fd;

int main(void) {
	if(0 > (fd=open(filename, O_TRUNC, S_IRWXU))) {
		perror("cannot open");
	}
	return 0;
}