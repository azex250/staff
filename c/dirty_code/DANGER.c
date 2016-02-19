#include <unistd.h>
#include <stdio.h>

int main() {
	while (!fork()) {
		printf("hello I'm: %i\n", getpid());
	}
	return 0;	
}

