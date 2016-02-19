extern int pop();
extern void push(int);

int calc(char line[], int len) {
	int i, arg1, arg2;
	for (i = 0; i < len; i++) {
		switch(line[i]) {
			case '-':
				arg1 = pop();
				arg2 = pop();
				push(arg2 - arg1);
				break;
			case '+':
				arg1 = pop();
				arg2 = pop();
				push(arg1 + arg2);
				break;
			case '*':
				arg1 = pop();
				arg2 = pop();
				push(arg1 * arg2);
				break;
			case '/':
				arg1 = pop();
				arg2 = pop();
				push(arg2 / arg1);
				break;
			case '\n':
				printf("%d\n", pop());
				break;
			default:
				push(line[i] - '0');
		}
	}
}