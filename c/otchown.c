#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int uidByName(const char* uname) {
	struct passwd* pw;
	int res = -1;

	while(pw = getpwent()) {
		if (strcmp(pw->pw_name,uname) == 0) {
			res = (int)pw->pw_uid;
			break;
		}
	}

	if(res == -1) {
		printf("Username not found\n");		
	}

	endpwent();
	return res;
}

int main(int argc, char const *argv[]) {
	int uid, i;

	if(argc<3) {
		printf("Usage: otchown user file [files...] \n");
		return 1;
	} else {
		uid = uidByName(argv[1]);		
	}


	for (i = 2; i < argc; ++i) {
		if( chown(argv[i], uid, -1) == -1) {
			perror(argv[i]);
		}	
	}


	return 0;
}