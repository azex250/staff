#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 500
#define DELAY 5
#define FILENAME "test"

int main() {
	int nread;
	char buf[BUFF_SIZE];
	int fd = open(FILENAME, O_RDONLY);
	while(true) {
		if(nread=read(fd,buf,BUFF_SIZE)) {
			write(STDOUT_FILENO, buf, nread);
		} else {
			nread = lseek(fd, 0, SEEK_END);
			sleep(DELAY);
			fd = open(FILENAME, O_RDONLY);
			lseek(fd, nread, SEEK_SET);
		}
	}	
}