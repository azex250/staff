#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main(void) {
	char a[10];
	int bytes;
	int fd = open("test.log", O_RDONLY);
	for(;;) {
		while(bytes=read(fd, a, 10)) {
			write(1, a, bytes);
		}
		sleep(5);
	}
}