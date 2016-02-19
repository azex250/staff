#include <stdio.h>
#include <string.h>
#include "dbapi.h"

int DBSIZE = sizeof(task)*7*FIELDS;

void open(task week[][FIELDS]) {
	FILE *fp;
	if( (fp = fopen(DB, "rb")) == NULL ) {
		perror(DB);
	} else {
		fread(week, DBSIZE,1, fp);
	}

	fclose(fp);
	return;
}

void close(task week[][FIELDS]) {
	FILE *fp;
	if( (fp = fopen(DB, "wb")) == NULL ) {
		perror(DB);
	} else {
		fwrite(week, DBSIZE,1, fp);
	}
	fclose(fp);
	return;
}

int findTask(const char* name,  task week[]) {
	int i;
	for(i=0;i<FIELDS; ++i) {
		if(strcmp(name, week[i].name) == 0) {
			return i;
		}
	}
	return -1;
}

int addTask(const char* name, double duration, task week[]) {
	if(findTask(name, week) != -1) {
		return -1;
	}

	int i = 0;

	for(i=0;i<FIELDS; ++i) {
		if(week[i].duration == 0) {
			week[i].duration = duration;
			strcpy(week[i].name, name);
			return 0;
		}
	}
}

int deleteTask(const char* name, task week[]) {
	int res = findTask(name, week);
	if(res!=-1) {
		strcpy(week[res].name, "\0");
		week[res].duration = 0;
	}
	return res;
}

int updateTask(const char* name, double duration, task week[]) {
	int res = findTask(name, week);
	if(res!=-1) {
		week[res].duration = duration;
	}
	return res;
}
