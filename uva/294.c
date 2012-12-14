#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 1000000000
#define SQRT_MAX_NUM (int)sqrt(MAX_NUM)
#define SQRT_SQRT_MAX_NUM (int)sqrt(SQRT_MAX_NUM)
#define MIN_PRIME 2

char *primeTable = NULL;

void set_prime(void)
{
	int i, j;
	for ( i = MIN_PRIME; i <= SQRT_SQRT_MAX_NUM; i++) {
		if ( primeTable[i] ) {
			for ( j = i * i; j <= SQRT_MAX_NUM; j += i) {
				primeTable[j] = 0;
			}
		}
			
	}
}

int main(int argc, char *argv[])
{
	int caseNum, lowbound, upbound, i, j;
	int maxDivisorsKey, maxDivisorsValue, divisorsPerPrime, divisorsAll;
	int sqrtUpbound, tmp;

	primeTable = malloc((SQRT_MAX_NUM+1) * sizeof(char));
	memset(primeTable, 1, (SQRT_MAX_NUM+1) * sizeof(char));
	set_prime();

	scanf("%d", &caseNum);

	while( caseNum-- ) {
		scanf("%d %d", &lowbound, &upbound);
		sqrtUpbound = (int)sqrt(upbound);
		maxDivisorsKey = 0;
		maxDivisorsValue = 0;

		for ( i = lowbound; i <= upbound; i++) {
			divisorsPerPrime = 1;
			divisorsAll = 1;
			tmp = i;
			for ( j = MIN_PRIME; j <= sqrtUpbound; j++) {
				if ( primeTable[j] && 0 == tmp % j ) {
					while (0 == tmp % j){
						divisorsPerPrime++;
						tmp /= j;
					}
					divisorsAll *= divisorsPerPrime;
					divisorsPerPrime = 1;
				}
			}
			if (tmp != 1)
				divisorsAll *= 2;
			if ( divisorsAll > maxDivisorsValue ) {
				maxDivisorsValue = divisorsAll;
				maxDivisorsKey = i;
			}
		}

		printf("Between %d and %d, %d has a maximum of %d divisors.\n", lowbound, upbound, maxDivisorsKey, maxDivisorsValue);
	}

	free(primeTable);

	return 0;
}
