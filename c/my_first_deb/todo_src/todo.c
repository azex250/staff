#include "dbapi.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


task week[7][FIELDS];
const char* DAY_OF_WEEK[] = {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};

void printWeek(int weekDay, task week[][FIELDS]) {
	int i = 0;
	printf("\t\t\t\t*** %s ***\n", DAY_OF_WEEK[weekDay]);
	for (i = 0; i < FIELDS; ++i) {
		if(week[weekDay][i].duration != 0) {
			printf(
				"Task: %-40s duration: %.2fh\n", 
				week[weekDay][i].name, week[weekDay][i].duration
			);
		}
	}
}

int weekToInt(const char* weekDay) {
	const char* weekDays[] = {"m", "t", "w", "th", "f", "s", "su"}; 
	int i;
	for (i = 0; i < 7; ++i) {
		if(strcmp(weekDay, weekDays[i])==0) 
			return i;
	}
	return 0;
}

int main(int argc, char** argv) {
	open(week);

		if(argc==1) {
			int i;
			printf("add/del/list/up\n");
			for(i=0;i<7;++i) {
				printWeek(i, week);
			}
		} else if(argc == 2) {
			printWeek(weekToInt(argv[1]), week);
		} else if(strcmp(argv[1],"add") == 0) {
			addTask(argv[3], atof(argv[4]), week[weekToInt(argv[2])]);
		} else if(strcmp(argv[1],"rm") == 0) {
			deleteTask(argv[3], week[weekToInt(argv[2])]);
		} else if(strcmp(argv[1],"up") == 0) {
			updateTask(argv[3], atof(argv[4]), week[weekToInt(argv[2])]);
		} 

	close(week);
	return 0;	
}