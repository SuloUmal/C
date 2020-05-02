/* -------------------------------------------
Name: Suleyman Umalatov
Student number: 135476182
Email: sumalatov@myseneca.ca
Section: SMM
Date: 26/03/2019
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name *name) {
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]s", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	int option = yes();
	if (option == 0) {
		name->middleInitial[0] = '\0';
	}
	else {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]s", name->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]35s", name->lastName);
	clearKeyboard();

}


// getAddress:
void getAddress(struct Address *address) {
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	if (address->streetNumber < 0) {
		do
		{
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
			address->streetNumber = getInt();
		} while (address->streetNumber < 0);
	}
	printf("Please enter the contact's street name: ");
	scanf(" %35[^\n]s", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	int option = yes();
	if (option == 0) {
		address->apartmentNumber = 0;
	}
	else {
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		if (address->apartmentNumber < 0) {
			do
			{
				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
				address->apartmentNumber = getInt();
			} while (address->apartmentNumber < 0);
		}
	}
		printf("Please enter the contact's postal code: ");
		scanf(" %7[^\n]s", address->postalCode);
		clearKeyboard();

		printf("Please enter the contact's city: ");
		scanf(" %40[^\n]s", address->city);
		clearKeyboard();
}


// getNumbers:
int option;
void getNumbers(struct Numbers *numbers) {
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);
	

	printf("Do you want to enter a home phone number? (y or n): ");
	option = yes();

	if (option == 0) {
		strcpy(numbers->home, "");
	}

	else {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	option = yes();


	if (option == 0) {
		strcpy(numbers->business, "");
	}

	else {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}

}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:

void getContact(struct Contact *contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);

}