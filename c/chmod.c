#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

mode_t mod, new_mod  = 0;
enum ACTION {
	PLUS, MINUS, DEFINE
};

ACTION action = DEFINE;

mode_t get_mod(char* path) {
	mode_t res;
	struct stat a;
	stat(path, &a);
	if(action == PLUS) {
		return new_mod | a.st_mode;
	} else if(action == MINUS) {
		return ~new_mod & 0777 & a.st_mode;
	}
	return a.st_mode;
}

void parse_str_mod(char* str) {
	int i, len=strlen(str);

	mode_t tmp = 0;

	for(i=0; i<len; i++) {
		switch(str[i]) {
			case 'a':
				new_mod |= 0777;
				break;
			case 'o':
				new_mod |= 0007;
				break;
			case 'g':
				new_mod |= 0070;
				break;
			case 'u':
				new_mod |= 0700;
				break;
			case '+':
				action = PLUS;
				break;
			case '-':
				action = MINUS;
				break;
			case '=':
				action = DEFINE;
				break;
			case 'r':
				tmp |= S_IRUSR | S_IRGRP | S_IROTH;
				break;
			case  'w':
				tmp |= S_IWUSR | S_IWGRP | S_IWOTH;
				break;
			case 'x':
				tmp |= S_IXUSR | S_IXGRP | S_IXOTH;
				break;
		}
	}
	new_mod &= tmp;
	return;
}

void parse_oct_mod(char* str) {
	char* errptr;
	new_mod = strtol(str, &errptr, 8);
}


int main(int argc, char **argv) {
	mode_t mode_to_set = 0;
	int i;
	switch(argv[1][0]) {
		case 'a': case 'o': case 'u': case 'g':
			get_mod(argv[1]);
			parse_str_mod(argv[1]);
			break;
		default:
			parse_oct_mod(argv[1]);
			break;
	}

	for (i = 2; i < argc; ++i) {
		if(action!=DEFINE) {
			mode_to_set = get_mod(argv[i]);
		} else {
			mode_to_set = new_mod; 
		}
		chmod(argv[i], mode_to_set);
	}
	return 0;
}
