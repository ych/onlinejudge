#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ANS 2703663
#define SQRT_MAX_ANS (int)sqrt(MAX_ANS)
#define SQRT_SQRT_MAX_ANS (int)sqrt(SQRT_MAX_ANS)
#define MIN_PRIME 2

short int *primeTable = NULL;
int *primeFactorNumTable= NULL;
int primeNum = 0;

void set_prime(void)
{
	int i, j;

	for ( i = MIN_PRIME; i <= SQRT_SQRT_MAX_ANS; i++) {
		if ( primeTable[i] ) {
			for ( j = i * i; j <= SQRT_MAX_ANS; j += i) {
				primeTable[j] = 0;
			}   
		}
	}

	j = 0;
	for ( i = MIN_PRIME; i <= SQRT_MAX_ANS; i++) {
		if ( primeTable[i] ) {
			primeTable[j++] = i;
		}
	}
	primeNum = j;
}

int main(int argc, char *argv[])
{
	int i, j, tmp, caseNum = 0, primeFactorNum = 0;
	int max, min, ans, input;

	primeTable = malloc((SQRT_MAX_ANS+1) * sizeof(short int));
	for ( i = 0; i <= SQRT_MAX_ANS; i++) {
		primeTable[i] = i;
	}
	set_prime();

	primeFactorNumTable = malloc((MAX_ANS+1) * sizeof(int));
	primeFactorNumTable[0] = primeFactorNumTable[1] = 0;

	for ( i = MIN_PRIME; i <= MAX_ANS; i++) {
		tmp = i;
		for ( j = 0; j < primeNum; j++) {
			if ( 0 == tmp % primeTable[j] ) {
				primeFactorNum++;
				tmp /= primeTable[j];
				if ( 1 != tmp ) {
					primeFactorNum += (primeFactorNumTable[tmp] - primeFactorNumTable[tmp-1]);
					tmp = 1;
				}
				break;
			}
		}

		if ( 1 != tmp ) {
			primeFactorNum++;
		}

		primeFactorNumTable[i] = primeFactorNum;
	}

	while ( scanf("%d", &input) && (input >= 0) ){
		if ( 0 == input ) {
			ans = 0;
		} else {
			max = MAX_ANS;
			min = MIN_PRIME;
			ans = (max+min)/2;
		}

		while (input != primeFactorNumTable[ans]) {
			if ( input > primeFactorNumTable[ans] ) {
				min = ans + 1;
			} else {
				max = ans - 1;
			}
			ans = (max+min)/2;
			if ( max - min < 3 ) {
				break;
			}
		}

		caseNum++;
		if ( input == primeFactorNumTable[ans] ) {
			printf("Case %d: %d!\n", caseNum, ans);
		} else if ( input == primeFactorNumTable[max] ) {
			printf("Case %d: %d!\n", caseNum, max);
		} else if ( input == primeFactorNumTable[min] ) {
			printf("Case %d: %d!\n", caseNum, min);
		} else {
			printf("Case %d: Not possible.\n", caseNum);
		}
	}

	free(primeTable);
	free(primeFactorNumTable);

	return 0;
}
