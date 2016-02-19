#include <stdio.h>

FILE* f;
char a;
int wcount=0;
int lcount=0;

int main(int argc, char const *argv[]) {
	if((f=fopen(argv[1], "r"))==NULL) {
		perror("cannot open file");
		return 1;
	}
	while((a=fgetc(f))!=EOF) {
		printf("%c", a);
		if (a==' ' || a=='\t') wcount++;
		if (a=='\n') {wcount++; lcount++;}
	}
	printf("\nwords:%i,lines:%i\n", wcount, lcount);
	return 0;
}