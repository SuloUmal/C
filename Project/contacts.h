/* -------------------------------------------
Name: Suleyman Umalatov
Student number: 135476182
Email: sumalatov@myseneca.ca
Section: SMM
Date: 26/03/2019
----------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------- */

#ifndef CONTACTS_H_
#define CONTACTS_H_


// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #1 here...

struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};


// Structure type Numbers declaration
// Place your code from Milestone #1 here...

struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//-------------------------------- 
// Function Prototypes 
//-------------------------------- 


void getName(struct Name *);
void getAddress(struct Address *);
void getNumbers(struct Numbers *);
void getContact(struct Contact *);

// Get and store from standard input the values for Name 
// Place your code here... 

// Get and store from standard input the values for Address 
// Place your code here... 

// Get and store from standard input the values for Numbers 
// Place your code here... 

// Get and store from standard input the values for a Contact (NOT: Contacts) 
// NOTE:  Make sure the structure Contact does not have an 's' on the end! 
// Put function prototype below: 

#endif // !CONTACTS_H_
