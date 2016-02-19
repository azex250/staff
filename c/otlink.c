#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv) {
	if(argc<3) {
		printf("Usage: old_path new_path [new_path1...]\n");
		return 1;
	}

	int i;

	for(i=2; i<argc; ++i) {
		if(link(argv[1], argv[i])==-1) {
			perror(argv[i]);
		}		
	}

	return 0;
}