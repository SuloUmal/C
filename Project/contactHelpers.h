/* -------------------------------------------
Name: Suleyman Umalatov
Student number: 135476182
Email: sumalatov@myseneca.ca
Section: SMM
Date: 26/03/2019
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
			 help reduce redundant coding for common repetitive tasks.
---------------------------------------------------------------------*/

// HINT: 
// You will most likely want to include this header file
// in other files of the project since it provides general 
// helper functions that can be used throughout.

#include "contacts.h"

//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);

// getInt:
// Put function prototype below:
int getInt(void);

// getIntInRange:
// Put function prototype below:
int getIntInRange(int min, int max);

// yes:
// Put function prototype below:
int yes(void);

// menu:
// Put function prototype below:
int menu(void);

// contactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);


void getTenDigitPhone(char phoneNum[]);


int findContactIndex(const struct Contact contacts[], int size,
	const char cellNum[]);

void displayContactHeader(void);

void displayContactFooter(int);

void displayContact(const struct Contact *contact);

void displayContacts(const struct Contact contacts[], int size);

void searchContacts(const struct Contact contacts[], int size);

void addContact(struct Contact contacts[], int size);

void updateContact(struct Contact contacts[], int size);

void deleteContact(struct Contact contacts[], int size);

void sortContacts(struct Contact contacts[], int size);

