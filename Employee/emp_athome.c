//--------------------------------------------------
// Name:           Suleyman Umalatov
// Student Number: 135476182
// Email:          sumalatov@myseneca.ca
// Section:        SMM
// Workshop:       5 (in-lab)
//--------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
struct Employee {

	int id;
	int Age;
	double salary;
};

#define SIZE 4



int main(void) {

	int option = 0, IDsearch, counter, counter_emp = 0, flag = 0, check = 0, num = -1;

	printf("---=== EMPLOYEE DATA ===---\n\n");
	struct Employee emp[SIZE] = { { 0 } };
	IDsearch = num;
	do {

		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");


		scanf("%d", &option);
		printf("\n");

		switch (option) {

		case 0:
			break;

		case 1:
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (counter = 0; counter < SIZE; counter++) {
				if (emp[counter].id > 0) {
					printf("%6d%9d%11.2lf\n", emp[counter].id, emp[counter].Age, emp[counter].salary);
				}
			}
			printf("\n");
			break;

		case 2:
			printf("Adding Employee\n");
			printf("===============\n");


			if (counter_emp < SIZE) {
				for (counter = 0; counter < SIZE; counter++) {

					if (emp[counter].id == 0) {
						printf("Enter Employee ID: ");
						scanf("%d", &emp[counter].id);

						printf("Enter Employee Age: ");
						scanf("%d", &emp[counter].Age);
	
						printf("Enter Employee Salary: ");
						scanf("%lf", &emp[counter].salary);
						
						printf("\n");
						counter_emp++;
						counter = SIZE;
					}
				}
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			break;


		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &IDsearch);
				for (counter = 0; counter < SIZE; counter++) {
					if (emp[counter].id == IDsearch) {
						printf("The current salary is %.2f\n", emp[counter].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[counter].salary);
          					  check = counter;
						counter = SIZE;
         				   flag = 1;
					printf("\n");
            				 
					}
				}
				if (IDsearch != emp[check].id)
					printf("*** ERROR: Employee ID not found! ***\n");
			} while (flag != 1);
      			flag = 0;
			num = -1;
			break;

		case 4:
			printf("Remove Employee\n");
			printf("===============\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &IDsearch);
				for (counter = 0; counter < SIZE; counter++) {
					if (IDsearch == emp[counter].id) {
						num = counter;
						printf("Employee %d will be removed\n\n", IDsearch);
						emp[counter].id = 0;
						counter_emp--;
            check = counter;
						counter = SIZE;
            flag = 1;
           
					}
				}
				if (emp[check].id != 0)
					printf("*** ERROR: Employee ID not found! ***\n");
			} while (flag != 1);
      flag = 0;
			num = -1;
			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}
	} while (option != 0);
	printf("Exiting Employee Data Program. Good Bye!!!\n");

	return 0;
}