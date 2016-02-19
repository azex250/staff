#include <sys/statvfs.h>
#include <stdio.h>

struct statvfs buf;

int main(void) {
	statvfs("/", &buf);
	printf("%lu\n", buf.f_bsize);
	printf("%lu\n", buf.f_flag);
	return 0;
}