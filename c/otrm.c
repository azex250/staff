#include <unistd.h>
#include <stdio.h>

bool answer() {
	char answer;
	printf("Are you sure? y/n\n");
	while(true) {
		answer = getchar();

		if(answer=='y' || answer=='Y') {
			return true;
		}

		if(answer=='n' || answer=='N') {
			return false;
		}
	}
}

int main(int argc, char const *argv[]) {
	if(argc<2) {
		return 1;
	}

	int i;


	for(i=1; i<argc; ++i) {
		if(access(argv[i], F_OK)==-1) {
			perror(argv[i]);
			continue;
		}

		if( (access(argv[i], W_OK)==-1) && !answer() ) {
			continue;
		}

		unlink(argv[i]);
	}
	return 0;
}