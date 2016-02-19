#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
	gcc otchmod.c  -lm -o otchmod
*/

int convert(const char* a) {
	int i,j;
	int res = 0;
	char buf;
	for(i=0,j=2; i<3; ++i,--j) {
		buf = a[i];
		res += (atoi(&buf)*(pow(8,j)));
	}
	return res;
}

int main(int argc, char const *argv[]) {
	int i;
	if(argc < 3) {
		return 1;
	}
	mode_t mod = convert(argv[1]);
	for(i=2; i<argc; ++i) {
		if(chmod(argv[i], mod)) {
			perror("cannot change mod");
		}
	}
	return 0;
}