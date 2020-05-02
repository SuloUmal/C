/*
	Name:           Umalatov Suleyman
	Student Number: 135476182
	Email:          sumalatov@myseneca.ca
	Section:        SMM
	Workshop:       3 (in-lab)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUMS 4
int main(void) {
	int high, low, i = 0, dayl, dayh, thehighest = -40, thelowest = 40;
	float meanlow = 0, meanhigh = 0, mean = 0;
	printf("---=== IPC Temperature Analyzer ===---");
	do {
		i++;
		printf("\nEnter the high value for day %d: ", i);
		scanf("%d", &high);
		printf("\nEnter the low value for day %d: ", i);
		scanf("%d", &low);
		meanhigh = meanhigh + high;
		meanlow = meanlow + low;
		if (thelowest > low) {
			thelowest = low;
			dayl = i;
		}
		if (thehighest < high) {
			thehighest = high;
			dayh = i;
		}
		if (high > 40 || low < -40 || low > high) {
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			meanhigh = meanhigh - high;
			meanlow = meanlow - low;
			i--;
		}
	} while (i < NUMS);
	printf("\nThe average (mean) LOW temperature was: %.2f", meanlow / NUMS);
	printf("\nThe average (mean) HIGH temperature was: %.2f", meanhigh / NUMS);
	mean = (meanhigh + meanlow) / 2;
	printf("\nThe average (mean) temperature was: %.2f", mean / NUMS);
	printf("\nThe highest temperature was %d, on day %d", thehighest, dayh);
	printf("\nThe lowest temperature was %d, on day %d\n", thelowest, dayl);
	return 0;
}
