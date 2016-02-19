#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "db_api.h"

char buf[NAMELENGTH];
int fd = -1;

void clearbuf() {
	int i;
	for(i=0; i<NAMELENGTH-1; i++) {
		buf[i] = ' ';
	}
	buf[NAMELENGTH-1] = '\n';
}

bool setbuf(const char* nameo) {
	clearbuf();
	int i;
	for(i=0;i<NAMELENGTH;i++) {
		if(i==NAMELENGTH || nameo[i]=='\0') {
			break;
		}
		buf[i] = *(nameo+i);
	}
	buf[NAMELENGTH-1] = '\n';
	return true;
}

bool setroom(int roomno) {
	int offset;
	off_t nread;

	if(fd == -1 && ((fd = open(DB_NAME, O_RDWR)) == -1)) {
		perror("cannot open file");
		return false;
	} 
	
	nread = (roomno-1) * NAMELENGTH;

	if(offset = lseek(fd, nread, SEEK_SET) == -1) {
		perror("cannot set position");
		return false;
	}

	return true;
}



char* getoccuper(int apartment) {
	off_t nread;

	if(!setroom(apartment)) {
		return NULL;
	} 

	if((nread = read(fd, buf, NAMELENGTH)) <= 0) {
		perror("cannot read from file");
		return NULL;
	}

	buf[nread-1] = '\0';
	return buf;	
}

bool isfree(int roomno) {
	getoccuper(roomno);
	int i;
	for(i=0;i<NAMELENGTH;i++) {
		if(buf[i]!=' ' && buf[i]!='\t' && buf[i]!='\0') {
			return false;
		}
	}

	return true;
}

int findfree() {
	int i;
	for(i=1; i<11; i++) {
		if(isfree(i)) {
			return i;
		} 	
	}	
	return -1;
}

bool freedom(int roomno) {
	if(!setroom(roomno)) {
		return false;
	}

	clearbuf();

	if(write(fd, buf, NAMELENGTH) < 0) {
		perror("cannot write");
		return false;
	}

	return true;
}

bool setocupper(int roomno, const char* nameo) {
	if(!setroom(roomno)) {
		return false;
	}

	if(!setbuf(nameo)) {
		return false;
	}

	if(write(fd, buf, NAMELENGTH) < 0) {
		perror("cannot write");
		return false;
	}

	return true;
}