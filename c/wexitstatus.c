#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc, char const *argv[]) {
	int stat;
	int pid = fork();

	if (pid < 0) {
		perror("Fork error");
		return 10;
	}

	if (pid) {
		int b = wait(&stat);
		return b > 0 ? WEXITSTATUS(stat) : -1;  
	} else {
		return 11;
	}
}