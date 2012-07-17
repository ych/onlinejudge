#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 32

unsigned int parse_month(const char* str)
{
	switch (str[0]) {
		case 'A':
			switch (str[1]) {
				case 'p':
					return 4;
				case 'u':
					return 8;
			}
		case 'D':
			return 12;
		case 'F':
			return 2;
		case 'J':
			switch (str[3]) {
				case 'e':
					return 6;
				case 'u':
					return 1;
				case 'y':
					return 7;
			}
		case 'M':
			switch (str[2]) {
				case 'r':
					return 3;
				case 'y':
					return 5;
			}
		case 'N':
			return 11;
		case 'O':
			return 10;
		case 'S':
			return 9;
	}
}

unsigned int is_leap_year(unsigned int year)
{
	if (year % 4 || (year % 100 == 0 && year % 400)) {
		return 0;
	}
	else {
		return 1;
	}
}

unsigned int is_before_229(unsigned int month, unsigned int day)
{
	if (month <= 2 && !(2 == month && 29 == day)) {
		return 1;
	}
	else {
		return 0;
	}
}

unsigned int is_after_229(unsigned int month, unsigned int day)
{
	if (month >= 3) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(int argc, char *argv[])
{
	unsigned int caseNum, i, ans;
	unsigned int startYear, startMonth, startDay, endYear, endMonth, endDay;
	char buf[BUF_SIZE], *sptr;

	fgets(buf, BUF_SIZE, stdin);
	caseNum = atoi(buf);

	for (i = 1; i <= caseNum; i++) {

		fgets(buf, BUF_SIZE, stdin);
		sptr = strtok(buf, " ");
		startMonth = parse_month(sptr);
		sptr = strtok(NULL, " ,");
		startDay = atoi(sptr);
		sptr = strtok(NULL, " ");
		startYear = atoi(sptr);

		fgets(buf, BUF_SIZE, stdin);
		sptr = strtok(buf, " ");
		endMonth = parse_month(sptr);
		sptr = strtok(NULL, " ,");
		endDay = atoi(sptr);
		sptr = strtok(NULL, " ");
		endYear = atoi(sptr);

		ans = endYear/4 - (startYear-1)/4 + (startYear-1)/100 - endYear/100 + endYear/400 - (startYear-1)/400;

		if ( is_leap_year(startYear) ) {
			ans -= is_after_229(startMonth, startDay);
		}

		if ( is_leap_year(endYear) ) {
			ans -= is_before_229(endMonth, endDay);
		}

		printf("Case %u: %u\n", i, ans);
	}

	return 0;
}
