#include <stdio.h>
#include <stdlib.h>
#include "stringlist.h"
#include "bst.h"
#include <string.h>

/*
 * Main.c
 * The main driver of the student management program
 * Allows the user to Add/Remove students from a Binary Search Tree
 * Allows the user to Enrol/Un-Enrol a student into a course
 * Allows the user to output the number of students enrolled in a given course
 * Allows the user to output an ordered list of students enrolled into a course
 * Allows the user to list the courses a student is currently enrolled in
 */




 /* Print the BST in pre-order format
  * Recursively iterates through the BST printing nodes
  */

void print_pre_order_bst_node(BSTNodePtr self) {
	if (self != NULL) {
		printf(" %d", self->data);
		print_pre_order_bst_node(self->left);
		print_pre_order_bst_node(self->right);
	}
}

/* Wrapper functin for print_pre_order_bst_node */

void print_pre_order_bst(BST *self) {
	print_pre_order_bst_node(self->root);
}


/* Traverse function for options 5 & 6 */
void traverse_bst_node(BSTNodePtr self) {
	if (self) {
		if (self->left) {
			traverse_bst_node(self->left);
		}
		else if (self->right) {
			traverse_bst_node(self->right);
		}
	}
	return;
}

/* Traverse Wrapper Function */

void traverse_bst(BST* self) {
	traverse_bst_node(self->root);
}

/* Print function for students enrolled in a given course*/

void print_in_order_students(BSTNodePtr self, char* courseName) {
	
	ListNodePtr current = self->courses.head; // New list pointer to increment 

	if (!self) {
		return;
		}

	if (self->left) {
		print_in_order_students(self->left, courseName); // Recursive search

		while (current != NULL) { // List search
			if (strcmp(current->data, courseName) == 0) { // String compare on the given course and students courses
				printf("%d\n", self->data); // Output students who are enrolled
				return;
			}
			current = current->next; // Incremement List Pointer
		}
	}
	else if (self->right) {
		print_in_order_students(self->right, courseName);
		}
}

void print_in_order_students_bst(BST* self, char* courseName) {
	print_in_order_students(self->root, courseName);
}

/* Main menu driver function 
 * All the program functionality happens here
*/

int menu(){
	char courseName[101];
	char course[101];
	int sID;
	int option;
	BST students = new_bst();
	
	/* do-while loop that controls the menu by;
	* repeatedly looping it until quit is selected 
	*/

	do{
		printf("1: Add a student\n");
		printf("2: Remove a student\n");
		printf("3: Enrol student in a course\n");
		printf("4: Un-enrol a student from a course\n");
		printf("5: Print a summary of courses and the number of students enrolled in each course\n");
		printf("6: Print an ordered list of students enrolled in a course\n");
		printf("7: Print a list of courses that a given student is enrolled in\n");
		printf("0: Quit\n\n");
		printf("Please Enter an Option: ");
		
		scanf_s("%d", &option); // Prompts the user to choose an option

		/* switch statement that controls the menu functions */

		switch (option){

			/* Add a student */
			case 1: 
				printf("You've selected 1!\n");
				printf("Please Enter a Student ID: ");
				scanf("%d", &sID);  // Read the student number
				insert_bst(&students, sID); // Insert Student into the BST
				printf("\n\n");
				break;

			/* Remove a student */
			case 2: 
				printf("You've selected 2!\n");
				printf("Please Enter a Student ID: ");
				scanf("%d", &sID); // Read the student number
				delete_bst(&students, sID); // Delete the student from the BST
				printf("\n\n");
				break;

			/* Enrol a student into a course */
			case 3: printf("You've selected 3!\n");
				char newCourse[101]; // Create a new course buffer 
				
				if (students.root != NULL) { // Check the tree for contents
					printf("Please enter the student you wish to add to a course: ");
					scanf("%d", &sID); // Read the student numer

					BSTNodePtr x = find_bst(&students, sID); // find the student that matches the previously entered number

					if (x != NULL) { // Check to see if the student exists
						printf("Please enter a course to enroll the student in: ");
						scanf("%s", course); // Read in course name

						int sLength = strlen(course);  // Obtain the length of the courses 

						char *newCourse = malloc(sizeof(char) *(sLength + 1)); // dynamically allocate memory for the string size

						strcpy(newCourse, course); 	//strcpy into a new variable

		
						insert_at_front(&x->courses, newCourse); //insert into Students linked list
					}
					else {
						printf("No student found!\n"); // Output a message if the student does not exist 
					}
				}
				else {
					printf("There is currently no students in the database\n"); // Output a message if the database is empty
				}
				printf("\n\n"); // Tidying program IO
				break;

			/* Un-Enrol a stuent from a course */
			case 4: printf("You have selected 4!\n");

				if (students.root != NULL) {  // Check if database has contents
					printf("Please enter the students ID: ");
					scanf("%d", &sID); // Read in student number

					BSTNodePtr x = find_bst(&students, sID); // Find that student

					if (x != NULL) { // Check to see if the student exists
						printf("Please specify the course: ");
						scanf("%s", course); // Read in course name
						delete_list(&x->courses, course); // Delete from students linked list
					}
					else {
						printf("No student found!\n"); // If there are no students matching, alert the user
					}
				}
				else {
					printf("There is currently no students in the database\n"); // If the database is empty, alert the user
				}
				printf("\n\n");
				break;

			case 5: printf("You've selected 5!\n");
				

				if (students.root != NULL) {

					traverse_bst(&students);

				
				}
				else {
					printf("No students in the database\n");
				}
				//strcmp the courses in each list

				//increment a counter 

				//display this somehow 
				printf("\n\n");
				break;
				
			case 6: printf("You've selected option 6\n");

				if (students.root != NULL){
				printf("Please enter a course: ");
				scanf("%s", courseName);
				print_in_order_students_bst(&students, courseName);
				}
				else {
					printf("There are no students in the database\n");
				}
				printf("\n\n");
				break;

			/* List courses a student is currently enrolled in */
			case 7: printf("You've selected 7!\n");

				if (students.root != NULL) {

					printf("Please input a student ID: ");
					scanf("%d", &sID); // Read student number


					BSTNodePtr x = find_bst(&students, sID); // Attempt to find that student
					if (x != NULL) { // Check to see if the student exists
						printf("%d\n", sID);
						printf("--------------------\n"); // Prettying up IO 
						print_list(&x->courses); // Print that students current enrolments

					}
					else {
						printf("No student found\n"); // Alert the user if the string does not exist
					}

					printf("\n\n");
					break;
				}
				else {
					printf("Nothing in the database\n"); // If nothing exists, alert the user
				}
			}
		} while (option != 0);
}

/* Main */

int main(List *self, BST students){
	printf("\t\t\t\t\t\tSTUDENT MANAGEMENT DATABASE\n"); // Prettying up IO
	printf("\t\t\t\t\t\t***************************");
	printf("\n");
	printf("\n");
	menu(); // Run menu
}
