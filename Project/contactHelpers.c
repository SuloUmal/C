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

#include <stdio.h>
#include <string.h>
#define MAXCONTACTS 5
#include <ctype.h>

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt: Empty function definition goes here:
int getInt(void)
{
	int value;
	char NL = 'x';
	while (NL != '\n') {
		scanf(" %d%c", &value, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} return value;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
	int inRange = getInt();
	while ((min > inRange) || (inRange > max)) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ",
			min, max);
		inRange = getInt();
	}
	return inRange;
}

// yes: Empty function definition goes here:
int yes(void)
{
	char YorN = 'a';
	char NL = 'a';
	int back = -1;

	scanf(" %c%c", &YorN, &NL);

	while (!(NL == '\n' && (YorN == 'Y' || YorN == 'N' || YorN == 'y' || YorN == 'n')))
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &YorN, &NL);
	}
	if ((YorN == 'Y') || (YorN == 'y')) {
		back = 1;
	}
	else if ((YorN == 'N') || (YorN == 'n')) {
		back = 0;
	}
	return back;
}

// menu: Empty function definition goes here:
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	return getIntInRange(0, 6);
	printf("\n");
}

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void) {
	struct Contact contacts[MAXCONTACTS] = { { { "Rick",{ '\0' },"Grimes" } ,{ 11,"Trailer Park",0, "A7A 2J2", "King City" } ,{ "4161112222", "4162223333", "4163334444" } } ,
	{ { "Maggie","R.", "Greene" } ,{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" } ,{ "9051112222", "9052223333", "9053334444" } } ,
	{ { "Morgan", "A.", "Jones" } ,{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" } ,{ "7051112222", "7052223333", "7053334444" } } ,
	{ { "Sasha",{ '\0' }, "Williams" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9052223333", "9052223333", "9054445555" } }, };
	int option = 0, selection;
	do {
		selection = menu();
		printf("\n");
		if (selection == 1) {
			displayContacts(contacts, MAXCONTACTS);
			pause();
		}
		else if (selection == 2) {
			addContact(contacts, MAXCONTACTS);
			pause();
		}
		else if (selection == 3) {
			updateContact(contacts, MAXCONTACTS);
			pause();
		}
		else if (selection == 4) {
			deleteContact(contacts, MAXCONTACTS);
			pause();
		}
		else if (selection == 5) {
			searchContacts(contacts, MAXCONTACTS);
			pause();
		}
		else if (selection == 6) {
			sortContacts(contacts, MAXCONTACTS);
			pause();
		}
		else if (selection == 0) {
			printf("Exit the program? (Y)es/(N)o: ");
			option = yes();

			if (option == 1)
				printf("\nContact Management System: terminated\n");
		}
		printf("\n");
	} while (option != 1);
}

void getTenDigitPhone(char phoneNum[]) {
	int needInput = 1, i;
	while (needInput == 1) {
		scanf("%10s", phoneNum);
		clearKeyboard();
		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10) {

			needInput = 0;
			for (i = 0; i < 10; i++) {
				if (!isdigit(phoneNum[i]))
					needInput = 1;
			}
		}
		if (needInput == 1)
			printf("Enter a 10-digit phone number: ");
	}
}
// findContactIndex:

int findContactIndex(const struct Contact contacts[], int size, const char cellNumber[])
{
	int i = 0;
	int result = -1;
	for (i = 0; i < size; i++) {
		if (strcmp(contacts[i].numbers.cell, cellNumber) == 0)
			result = i;
	}
	return result;
}

void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

void displayContact(const struct Contact *contacts) {
	if ((*contacts).name.middleInitial[0] == '\0')
		printf(" %s %s\n", (*contacts).name.firstName, (*contacts).name.lastName);
	else
		printf(" %s %s %s\n", (*contacts).name.firstName, (*contacts).name.middleInitial, (*contacts).name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", (*contacts).numbers.cell, (*contacts).numbers.home, (*contacts).numbers.business);
	if ((*contacts).address.apartmentNumber > 0)
		printf("       %d %s, Apt# %d, %s, %s\n", (*contacts).address.streetNumber, (*contacts).address.street, (*contacts).address.apartmentNumber, (*contacts).address.city, (*contacts).address.postalCode);
	else
		printf("       %d %s, %s, %s\n", (*contacts).address.streetNumber, (*contacts).address.street, (*contacts).address.city, (*contacts).address.postalCode);
}

void displayContactFooter(int counter) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", counter);
}


void displayContacts(const struct Contact contacts[], int size) {
	int i, counter = 0;
	displayContactHeader();
	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) > 0) {
			displayContact(&contacts[i]);
			counter++;
		}
	}
	displayContactFooter(counter);
}

void searchContacts(const struct Contact contacts[], int size) {
	char cellNumber[11];
	int position;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);
	position = findContactIndex(contacts, size, cellNumber);
	if (position != -1) {
		printf("\n");
		displayContact(&contacts[position]);
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n\n");
}

void addContact(struct Contact contacts[], int size) {
	int i = 0;
	int conNum = -1;
	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) == 0)
			conNum = i;
	}
	if (conNum != -1) {
		getContact(&contacts[conNum]);
		printf("--- New contact added! ---\n\n");
	}
	else
		printf("*** ERROR: The contact list is full! ***\n\n");
}

void updateContact(struct Contact contacts[], int size) {
	int correct, option;
	char cellNumber[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);
	correct = findContactIndex(contacts, size, cellNumber);
	if (correct == -1)
		printf("*** Contact NOT FOUND ***\n\n");
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[correct]);
		printf("\nDo you want to update the name? (y or n): ");
		option = yes();
		if (option == 1)
			getName(&contacts[correct].name);

		printf("Do you want to update the address? (y or n): ");
		option = yes();
		if (option == 1)
			getAddress(&contacts[correct].address);

		printf("Do you want to update the numbers? (y or n): ");
		option = yes();
		if (option == 1)
			getNumbers(&contacts[correct].numbers);
		printf("--- Contact Updated! ---\n\n");
	}
}

void deleteContact(struct Contact contacts[], int size) {
	char cellNumber[11];
	int delNumber;
	int option;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);
	delNumber = findContactIndex(contacts, size, cellNumber);
	if (delNumber == -1) printf("*** Contact NOT FOUND ***\n");
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[delNumber]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		option = yes();
		if (option == 1) 
		{
			contacts[delNumber].numbers.business[0] = '\0';
			contacts[delNumber].numbers.cell[0] = '\0';
			contacts[delNumber].numbers.home[0] = '\0';
			printf("--- Contact deleted! ---\n\n");
		} else {printf("\n");}		
	}
}

void sortContacts(struct Contact contacts[], int size) {
	int i;
	int j;
	struct Contact temp;
	for (i = 0; i < size-1; i++)
	{
		for (j = i+1; j  < size; j ++)
		{
			if (strlen(contacts[i].numbers.cell) != 0 && strlen(contacts[j].numbers.cell) != 0) {
				if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0) {
					temp = contacts[i];
					contacts[i] = contacts[j];
					contacts[j] = temp;
				}
			}
		}
	}
	printf("--- Contacts sorted! ---\n\n");
}