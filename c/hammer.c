#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main(void) {
	printf("start programm\n");
	int pid, chcode;
	pid = fork();
	if(!pid) {
		execlp("ls", "ls", "-al", NULL);
		printf("newer\n");
	}
	wait(&chcode);
	printf("Child return %i\n", chcode);
}