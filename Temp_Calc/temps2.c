//-------------------------------------------------- 
// Name:           Umalatov Suleyman
// Student Number: 135476182
// Email:          sumalatov@myseneca.ca 
// Section:        SMM 
// Workshop:       4 (at-home) 
//-------------------------------------------------- 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float average = 0, answer = 0;
	int days, high[10], low[10], i = 0;
	int thehighest = -50, thelowest = 50, dayl, dayh, num = 0;
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	printf("\n");
	//condition 
	while (days > 10 || days < 3) {
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
	}
	//get data
	printf("\n");
	for (i = 1; i <= days; i++) {
		printf("Day %d - High: ", i);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i);
		scanf("%d", &low[i]);
	}
	//printing
	printf("\nDay  Hi  Low\n");
	for (i = 1; i <= days; i++) {
		printf("%-4d %-4d %d\n", i, high[i], low[i]);
		if (thelowest > low[i]) {
			thelowest = low[i];
			dayl = i;
		}
		if (thehighest < high[i]) {
			thehighest = high[i];
			dayh = i;
		}

	}
	printf("\nThe highest temperature was %d, on day %d", thehighest, dayh);
	printf("\nThe lowest temperature was %d, on day %d\n", thelowest, dayl);

	do {
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
		scanf("%d", &num);
	while (num > days || num == 0) {	 
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", days);
			scanf("%d", &num);
		} 
    

		if (num > 0) {
			for (i = 1; i <= num; i++)
			{
				average = high[i] + low[i];
				answer += average;
			}
			answer = answer / (num * 2);
			printf("\nThe average temperature up to day %d is: %.2f\n", num, answer);
			average = 0;
			answer = 0;
		}
		else (num = -1);
	} while (num > 0);
	printf("\nGoodbye!\n");
	return 0;
}