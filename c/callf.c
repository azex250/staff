#include <stdio.h>

void printme(int a) {
	printf("%d\n", a);
}

void callme(void (*f)(int)) {
	f(33);
}

int main(int argc, char const *argv[]) {
	callme(printme);
	return 0;
}