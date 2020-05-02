/*
	Name:           Umalatov Suleyman
	Student Number: 135476182
	Email:          sumalatov@myseneca.ca
	Section:        SMM
	Workshop:       2 (at-home)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int QuarterCoin, LoonieCoin, DimeCoin, NickelCoin, PennyCoin, Rounder;
	double GST, BalanceOwing, left;


	printf("Please enter the amount to be paid: $");
	scanf(" %lf", &BalanceOwing);
	//GST
	GST = BalanceOwing * .13 + 0.005;
	Rounder = GST * 100;
	GST = Rounder * 0.01;
	printf("GST: %.2lf\n", GST);
	//Balance
	BalanceOwing = BalanceOwing + GST;
	Rounder = BalanceOwing * 100;
	BalanceOwing = Rounder * 0.01;
	printf("Balance owing: $%.2lf\n", BalanceOwing);
	//Loonies
	LoonieCoin = BalanceOwing;
	left = BalanceOwing - LoonieCoin;
	printf("Loonies required: %d, balance owing $%.2lf\n", LoonieCoin, left);
	//Quarters
	left = left * 100;
	QuarterCoin = (int)left / 25;
	left = left + 0.005;
	left = (int)left % 25;
	left = left / 100;
	printf("Quarters required: %d, balance owing $%.2lf\n", QuarterCoin, left);
	//Dimes
	left = left * 100;
	DimeCoin = (int)left / 10;
	left = left + 0.005;
	left = (int)left % 10;
	left = left / 100;
	printf("Dimes required: %d, balance owing $%.2lf\n", DimeCoin, left);
	//Nickel
	left = left * 100;
	NickelCoin = (int)left / 5;
	left = left + 0.005;
	left = (int)left % 5;
	left = left / 100;
	printf("Nickels required: %d, balance owing $%.2lf\n", NickelCoin, left);
	//Pennies
	left = left * 100;
	PennyCoin = (int)left;
	left = left + 0.005;
	left = (int)left - PennyCoin;
	left = left / 100;
	printf("Pennies required: %d, balance owing $%.2lf\n", PennyCoin, left);
	return 0;
}


