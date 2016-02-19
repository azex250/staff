#include <unistd.h>

#define BUFFSIZE 500

int main(void) {
	int nread;
	char buff[BUFFSIZE];
	while(nread=read(STDIN_FILENO, buff, BUFFSIZE)) {
		write(STDOUT_FILENO, buff, nread);
	}
}
