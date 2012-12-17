#include <stdio.h>
#include <stdlib.h>

#define CARRY_BASE 10000000000000000ULL
#define MAX_BASE_LEN 16
#define MAX_LEN 2568
#define ARRAY_LEN (MAX_LEN/MAX_BASE_LEN+1)

unsigned long long answer[1001][ARRAY_LEN];
unsigned short answerLen[1001];

int main(int argc, char *argv[])
{
	int i, j, input;
	unsigned long long tmp, carry;

	answer[0][0] = answer[1][0] = 1;
	answerLen[0] = answerLen[1] = 1;

	for ( i = 2; i < 1001; i++ ) {
		for ( j = 0; j < answerLen[i-1]; j++ ) {
			tmp = answer[i-1][j] * i + answer[i][j];
			carry = tmp / CARRY_BASE;
			answer[i][j] = tmp % CARRY_BASE;
			answer[i][j+1] += carry;
		}
		if ( answer[i][answerLen[i-1]] != 0 ) {
			answerLen[i] = answerLen[i-1] + 1;
		} else {
			answerLen[i] = answerLen[i-1];
		}
	}

	while( 1 == scanf("%d", &input) ){
		printf("%d!\n%llu", input, answer[input][answerLen[input]-1]);
		for ( i = answerLen[input]-2; i > -1; i--) {
			printf("%016llu", answer[input][i]);
		}
		printf("\n");
	}

	return 0;
}
