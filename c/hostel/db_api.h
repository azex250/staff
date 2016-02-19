#ifndef DB_API_H
#define DB_API_H 

#include <stdbool.h>

#define NAMELENGTH 41
#define DB_NAME "residents"

extern char buf[NAMELENGTH];
extern int fd;

bool isfree(int);
bool freedom(int);
bool setocupper(int, const char*);
int findfree(void);
char* getoccuper(int);

#endif