#include <stdio.h>
#include <stdlib.h>
#include "db_api.h"

int i;

int getroom(void) {
	getchar();
	printf("%s\n", "type room number");
	char buf[10];
	for (i = 0; i < 10; ++i) {
		buf[i]=getchar();
		if(buf[i] == '\n') {
			buf[i]='\0';
			return atoi(buf);
		}	
	}
	return -1;
}

const char* getoccupername(void) {
	static char* buf;
	buf = (char*)malloc(sizeof(char)*NAMELENGTH);
	printf("%s\n", "type Name");
	for(i=0;i<NAMELENGTH;i++) {
		buf[i] = getchar();
		if(buf[i] == '\n') {
			buf[i] = '\0';
			return buf;
		} 
	}
	printf("%s\n", "Max name len = 42");
	return NULL;
}

int main(void) {
	char answer;
	int roomno;
	
	for(;;) {
		printf("%s\n", "1 to add ocupper\n2 to delete occuper\n3 to watch occuper\nq to exit");
		answer = getchar();
		if(answer=='\n') {
			continue;
		}
		switch(answer) {
			case '1':
				roomno = getroom();
				if(roomno>11) {
					continue;
				}
				if(isfree(roomno)) {
					setocupper(roomno, getoccupername());
				} else {
					printf("%i%s\n", roomno, " room is engaged");
				}
				break;
			case '2':
				roomno = getroom();
				if(roomno>11) {
					continue;
				}
				if(freedom(roomno)) {
					printf("%s%i%s\n", "ocupper ", roomno, " deleted");
				} else {
					printf("%s%i\n", "error while delete ocupper", roomno);
				}
				break;
			case '3':
				roomno = getroom();
				if(roomno>11) {
					continue;
				}
				if(isfree(roomno)) {
					printf("%s%i%s\n","room ", roomno," is free");
				} else {
					printf("%s\n",getoccuper(roomno));					
				}
				break;
			case 'q':
				printf("%s\n", "goodbye");
				return 0;
			default:
				getchar();
				printf("%s\n", "wrong choice");
		}
	}
	return 0;
}