#ifndef DBAPI_H
#define DBAPI_H

#define DB "/var/todo/db"
#define FIELDS 10

typedef struct {
	char name[30];
	double duration;
} task;

extern int DBSIZE;

void open(task[][FIELDS]);
void close(task[][FIELDS]);
int findTask(const char*,  task[]);
int deleteTask(const char*, task[]);
int addTask(const char*, double, task[]);
int updateTask(const char*, double, task[]);

#endif