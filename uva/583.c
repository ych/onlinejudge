#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 2147483647
#define SQRT_MAX_NUM (int)sqrt(MAX_NUM)
#define SQRT_SQRT_MAX_NUM (int)sqrt(SQRT_MAX_NUM)
#define MIN_PRIME 2

char *isPrimeNum = NULL;

void set_prime(void)
{
	int i, j;
	for ( i = MIN_PRIME; i <= SQRT_SQRT_MAX_NUM; i++) {
		if ( isPrimeNum[i] ) {
			for ( j = i * i; j <= SQRT_MAX_NUM; j += i) {
				isPrimeNum[j] = 0;
			}
		}
	}
}

void print_factor(int num, int nowPrime)
{
	int i;

	for ( i = nowPrime; i <= SQRT_MAX_NUM; i++) {
		if ( !isPrimeNum[i] )
			continue;
		while ( 0 == num % i ) {
			num /= i;
			if ( 1 == num ) {
				printf(" x %d\n", i);
				return;
			} else {
				printf(" x %d", i);
			}
		}
	}

	printf(" x %d\n", num);
}

int main(int argc, char *argv[])
{
	int input;
	int i;

	isPrimeNum = malloc((SQRT_MAX_NUM+1) * sizeof(char));
	memset(isPrimeNum, 1, (SQRT_MAX_NUM+1) * sizeof(char));
	set_prime();

	while ( scanf("%d", &input) ) {
		if ( 0 == input ) {
			break;
		}

		if ( input < 0 ) {
			printf("%d = -1", input);
			print_factor(-input, MIN_PRIME);
		} else if ( 1 == input ) {
			printf("1 = 1\n");
		} else if ( input < SQRT_MAX_NUM+1 && isPrimeNum[input] ) {
			printf("%d = %d\n", input, input);
		} else {
			for ( i = MIN_PRIME; i <= SQRT_MAX_NUM; i++) {
				if ( !isPrimeNum[i] ) {
					continue;
				}

				if ( 0 == input % i ) {
					printf("%d = %d", input, i);
					print_factor(input/i, i);
					break;
				}
			}
			if ( i > SQRT_MAX_NUM ) {
				printf("%d = %d\n", input, input);
			}
		}
	}

	return 0;
}
