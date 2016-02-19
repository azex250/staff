#include <stdio.h>

int main(int argc, char** argv) {
	char a;
	int i;
	int k;
	int res = 0;
	
	if(argc!=2) {
		return 1;
	}
	for(char a,i=0; argv[1][i]!='\0'; i+=3) {
		for(int j=i,k=0; j<i+3;j++,k++) {
			if(argv[1][j]!='-') {
				res+=1<<k;
			}
		}
		printf("%i", res);
		res=0;
	}
	printf("\n");
	return 0;
}