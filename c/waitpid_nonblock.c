#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
	int status, pid = fork();

	if (pid) {
		while(!waitpid(pid, &status, 0 | WNOHANG)) {
			printf("wait %i\n", pid);
			sleep(1);
		}
	} else {
		printf("start %i\n", getpid());
		sleep(4);
		printf("end %i\n", getpid());
	}
	return 0;
}