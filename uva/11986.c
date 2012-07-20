#include<stdio.h>

#define BUF_SIZE 32

unsigned long long int diff[17] = {48, 528, 5328, 53328, 533328, 5333328, 53333328, 533333328, 5333333328, 53333333328, 533333333328, 5333333333328, 53333333333328, 533333333333328, 5333333333333328, 53333333333333328, 533333333333333328};

int main(int argc, char *argv[])
{
	unsigned int caseNum = 1;
	unsigned long long num;
	char buf[BUF_SIZE], *sptr;

	fgets(buf, BUF_SIZE, stdin);

	while (fgets(buf, BUF_SIZE, stdin)) {

		sptr = buf;
		num = *(sptr++);

		while (*sptr != '\n') {
			num = num * 10 + *(sptr++);
		}

		num -= diff[sptr-buf-1];

		if (num) {
			printf("Case %u: %d\n", caseNum++, 64-__builtin_clzll(num));
		} else {
			printf("Case %u: 0\n", caseNum++);
		}

	}

	return 0;
}
