#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
	int pid = getpid();
	char name[100];
	sprintf(name, "%i_temp_%s", pid, argv[1]);
	printf("%s\n", name);

	if (argc < 2) {
		printf("miss argv\n");
		exit(1);
	}

	if (!access(name, F_OK)) {
		printf("file_exists\n");
		exit(1);
	}

	open(name, O_CREAT);

	return 0;
}