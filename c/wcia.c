#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	printf("which character is above?\n");
	printf("\tto exit press 'q' then 'enter'\n\tto get new pair press 'enter'\n\n");
	srand(time(NULL));

	char q;
	int i,j;
	const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	for(;;) {
		i = (rand()%26);
		j = (rand()%26);
		while(i==j) 
			{ j = (rand()%26); }
		
		printf("%c   %c", alphabet[i],alphabet[j]);
		q = getchar();
		if(i<j) 
			{ printf("  --> %c\n",alphabet[i]); }
		else 
			{ printf("  --> %c\n",alphabet[j]); }
		if(q=='q') { 
			printf("goodbye!\n");
			return 0; 
		}
	}
}