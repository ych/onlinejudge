#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 8

void print_one_or_two(const char *str)
{
	unsigned int score = 0;

	if ('o' == str[0]) {
		score++;
	}
	if ('n' == str[1]) {
		score++;
	}
	if ('e' == str[2]) {
		score++;
	}
	
	if (score >= 2) {
		puts("1");
	} else {
		puts("2");
	}
}

int main(int argc, char *argv[])
{
	char buf[BUF_SIZE];

	fgets(buf, BUF_SIZE, stdin);

	while (fgets(buf, BUF_SIZE, stdin)) {

		if (buf[3] == '\n') {
			print_one_or_two(buf);
		} else {
			puts("3");
		}
	}

	return 0;
}
