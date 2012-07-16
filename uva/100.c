#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_NUM 1000000
#define BUF_SIZE 32

unsigned short cache[CACHE_NUM] = {0};

unsigned short length(unsigned int x)
{
	if (x < CACHE_NUM) {
		if (0 == cache[x]) {
			if (0 == x % 2) {
				cache[x] = length( x/2 ) + 1;
			} else {
				cache[x] = length( 3*x+1 ) + 1;
			}   
		}
		return cache[x];
	}
	else {
		if (0 == x % 2) {
			return length( x/2 ) + 1;
		} else {
			return length( 3*x+1 ) + 1;
		}
	}
}

int main(int argc, char *argv[])
{
	unsigned int x, y, start, end, i;
	unsigned short max, tmp;
	char buf[BUF_SIZE], *sptr;

	cache[1] = 1;

	while (fgets(buf, BUF_SIZE, stdin)) {

		sptr = strtok(buf, " ");
		x = atoi(sptr);
		sptr = strtok(NULL, " ");
		y = atoi(sptr);

		if (x < y) {
			start = x;
			end = y;
		} else {
			start = y;
			end = x;
		}   

		max = 0;

		for (i = start; i <= end; i++) {

			tmp = length(i);

			if (tmp > max) {
				max = tmp;
			}   
		}   

		printf("%u %u %hu\n", x, y, max);
	}   

	return 0;
}
