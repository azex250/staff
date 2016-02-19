#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
	int r;
	char b;
	if(argc!=2) return 1;

	for(int i=0; i<3; i++) {
		b = argv[1][i];
		r = atoi(&b);
		
		if(r&4) printf("%c", 'r');
		else 	printf("%c", '-');
		if(r&2) printf("%c", 'w');
		else 	printf("%c", '-');
		if(r&1) printf("%c", 'x');
		else 	printf("%c", '-');
	}
	printf("\n");
	return 0;
}