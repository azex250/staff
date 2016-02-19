#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
  #include <unistd.h>


#include <stdio.h>

/*
	r, w, rw, a, c
*/

int fileopen(const char* filename, const char* mode) {
	int flags = 0;
	for (int i = 0;i>=0; ++i) {		
		switch(mode[i]) {
			case 'r':
				if(mode[i+1]=='w') {
					printf("rw\n");
					flags = flags | O_RDWR;
					i++;
				} else {
					flags = flags | O_RDONLY;					
				}
				break;
			case 'w':
				flags = flags | O_WRONLY;
				break;
			case 'a':
				flags = flags | O_APPEND;
				break;
			case 'c':
				flags = flags | O_CREAT;
				break;
			case 't':
				flags = flags | O_TRUNC;
				break;
			default:
				i=-2;
				printf("%i\n", flags);
		}
	}
	return open(filename, flags);
}

int main(int argc, const char* argv[] ) {
	char buf[10] = {'1','1','1','1','1','1','1','1','1','\0'};

	int fd = fileopen(argv[1], argv[2]);
	if(fd==-1) {
		perror("error:");
	} else {
		write(fd, buf, 6);
		perror("while write");
		
		read(fd, buf, 1);
		perror("while read");
		printf("%s\n" ,buf);
	}
	return 0;
}