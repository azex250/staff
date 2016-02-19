#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 1024

/*
char* tsh_read_line() {
	int bufsize = BUFFSIZE;
	int position = 0;
	int c;
	char* buffer = (char*) malloc(sizeof(char) * bufsize);

	if (!buffer) {
		fprintf(stderr, "tch: allocation error!\n");
		exit(1);
	}

	for (int position = 0 ;; position++) {
		c = getchar();

		if (c == '\n' || c == EOF) {
			buffer[position] = '\0';
			return buffer;
		} else {
			buffer[position] = c;
		}

		if (position == bufsize - 1) {
			char* bf = (char*) malloc(sizeof(char) * bufsize);
			bufsize *= 2;
			
			if (!bf) {
				fprintf(stderr, "tch: allocation error!\n");
				exit(1);
			}

			strcpy(bf, buffer);
			free(buffer);
			buffer = bf;
		}
	}
}
*/

char* tsh_read_line() {
	char *buffer = NULL;
	size_t bufsize = 0;
	getline(&buffer, &bufsize, stdin);
	return buffer;		
} 

char** tsh_split_line(char* line) {
	char** tokens = (char**) malloc(sizeof(char*) * 64);
	char* token;
	int pos;
	token = strtok(line, " \n\r\a\t");
	for(pos = 0; token != NULL; pos++) {	
		tokens[pos] = token;
		token = strtok(NULL, " \n\r\a\t");
	}

	tokens[pos] = NULL;
	return tokens;
}

int tsh_execute(char** args) {
	int pid = fork();
	if(!pid) {
		execvp(args[0], args);
	} else {
		wait();
	}
	return 0;
}

void tsh_loop() {
	char *line;
	char **args;
  	int status;

	do {
		printf("> ");
		line = tsh_read_line();
		printf("%s\n", line);
		args = tsh_split_line(line);
		status = tsh_execute(args);
		free(line);
		free(args);

	} while (true);
}

int main(void) {
	tsh_loop();
	return 0;
}