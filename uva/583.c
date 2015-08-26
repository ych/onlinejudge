#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 2147483647
#define SQRT_MAX_NUM (int)sqrt(MAX_NUM)
#define SQRT_SQRT_MAX_NUM (int)sqrt(SQRT_MAX_NUM)
#define MIN_PRIME 2
#define PRIME_CNT 4792

char isPrimeNum[SQRT_MAX_NUM+1];
int PrimeNum[PRIME_CNT];

void set_prime(void)
{
	int i, j, cnt = 0;
	for ( i = MIN_PRIME; i <= SQRT_SQRT_MAX_NUM; i++) {
		if ( isPrimeNum[i] ) {
			PrimeNum[cnt++] = i;
			for ( j = i * i; j <= SQRT_MAX_NUM; j += i) {
				isPrimeNum[j] = 0;
			}
		}
	}
	while ( i <= SQRT_MAX_NUM ) {
		if ( isPrimeNum[i] )
			PrimeNum[cnt++] = i;
		i++;
	}
}

void print_factor(int num, int nowPrime)
{
	int i;

	for ( i = nowPrime; i < PRIME_CNT; i++) {
		while ( 0 == num % PrimeNum[i] ) {
			num /= PrimeNum[i];
			if ( 1 == num ) {
				printf(" x %d\n", PrimeNum[i]);
				return;
			} else if ( PrimeNum[i] > num ) {
				printf(" x %d x %d\n", PrimeNum[i], num);
				return;
			} else {
				printf(" x %d", PrimeNum[i]);
			}
		}
	}
	printf(" x %d\n", num);
}

int main(int argc, char *argv[])
{
	int input;
	int i;

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
			for ( i = 0; i < PRIME_CNT; i++) {
				if ( 0 == input % PrimeNum[i] ) {
					printf("%d = %d", input, PrimeNum[i]);
					print_factor(input/PrimeNum[i], i);
					break;
				}
			}
			if ( i == PRIME_CNT ) {
				printf("%d = %d\n", input, input);
			}
		}
	}

	return 0;
}
