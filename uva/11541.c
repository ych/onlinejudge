#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 256

void decode(const char* str)
{
	unsigned int i, count = 0;
	char ch;

	for (i = 0; str[i]; ) {
		if (isalpha(str[i])) {
			ch = str[i++];
			while (isdigit(str[i])) {
				count = count * 10 + str[i++] - '0';
			}
			for ( ; count; count--) {
				putchar(ch);
			}
		} else {
			return;
		}
	}
}

int main(int argc, char *argv[])
{
	unsigned int caseNum, i;
	char buf[BUF_SIZE], *sptr;

	fgets(buf, BUF_SIZE, stdin);
	caseNum = atoi(buf);

	for (i = 1; i <= caseNum; i++) {

		fgets(buf, BUF_SIZE, stdin);

		printf("Case %u: ", i);
		decode(buf);
		printf("\n");
	}

	return 0;
}
