#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
	int status, pid = fork();

	if (pid) {
		printf("wait %i\n", pid);
		waitpid(pid, &status, 0);
		printf("end %i\n", pid);
	} else {
		pid = fork();
		printf("pid %i start\n", getpid());
		
		if(pid) {
			sleep(4);
		} else {
			sleep(2);
		}
		printf("pid %i stop\n", getpid());
	}
	return 0;
}