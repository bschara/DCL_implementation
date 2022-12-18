/*
Title : Project1
Course : CSIS216 Fall 22-23
Date : 30 Oct  2022
Author: Bchara Abou Jaffal   A2111752

-- DCListTester.cpp------------------------------------------------------------

   This file is a program for testing class DCList.

-------------------------------------------------------------------------*/





#include "DCList.h"

//include menu prototype
int menu();


int main() {
	DCList myTestList; //empty list 

	int position; //position to be used
	ElementType data; //data to be inserted
	int choice = NULL; //choice to be picked by the user
	
      do {
		choice = menu(); //call menu method to get user choice
		switch (choice) {
		case 1:
			cout << " pick value" << endl;
			cin >> data;
			myTestList.insertAtBeginning(data);
			cout << endl;
			myTestList.display(cout);
			cout << endl;
			break;

		case 2:
			cout << " pick value" << endl;
			cin >> data;
			myTestList.insertAtEnd(data);
			cout << endl;
			myTestList.display(cout);
			cout << endl;
			break;

		case 3: 
			cout << " pick value" << endl;
			cin >> data;
			cout << " pick index" << endl;
			cin >> position;
			myTestList.insertAtPosition(data, position);
			cout << endl;
			myTestList.display(cout);
			cout << endl;
			break;

		case 4: 
			cout << " enter position" << endl;
			cin >> position;
			myTestList.deleteAtPosition(position);
			cout << endl;
			myTestList.display(cout);
			cout << endl;
			break;

		case 5: 
			cout << " enter value you want to delete before " << endl;
			cin >> data;
			myTestList.deleteBeforeAnElement(data);
			cout << endl;
			myTestList.display(cout);
			cout << endl;
			break;

		case 6: 
			cout << " enter element you want to search" << endl;
			cin >> data;
			if (myTestList.search(data) == true) {
				cout << endl;
				cout << "element is in the list" << endl;
			}
			else {
				cout << endl;
				cout << "element isnt in the list" << endl;
			}
			myTestList.display(cout);
			cout << endl;
			break;

		case 7: 
			cout << " enter element you wanna delete" << endl;
			cin >> data;
			myTestList.findAndDelete(data);
			cout << endl;
			myTestList.display(cout);
			cout << endl;
			break;

		case 8: 
			myTestList.removeFirst();
			cout << endl;
			myTestList.display(cout);
			cout << endl;
			break;

		case 9: 
			myTestList.removeLast();
			cout << endl;
			myTestList.display(cout);
			cout << endl;
			break;

		case 10: 
			myTestList.deleteDuplicates();
			cout << endl;
			myTestList.display(cout);
			cout << endl;
			break;

		case 11: cout << "\n Exiting list" << endl;
			break;

		default: cout << "\n Invalid selection";
			break;

		}
		cout << "\n";
	} while (choice != 11); //keep showing menu if choice is not to exit
}

int menu() {
	int selection; //user selection
	do {
		cout << "Welcome to Doubly-Circular Linked List Test program.\n"
			 << "An Empty DCList of integers has been created for you.\n"
			 << "Please choose one of the following options : \n";
		cout << "\n 1 - insert at beginning\n";
		cout << "\n 2 - insert at end\n";
		cout << "\n 3 - insert at position \n";
		cout << "\n 4 - delete at position\n";
		cout << "\n 5 - delete before an element\n";
		cout << "\n 6 - search element\n";
		cout << "\n 7 - find and delete\n";
		cout << "\n 8 - remove first\n";
		cout << "\n 9 - remove last\n";
		cout << "\n 10 - delete duplicates\n";
		cout << "\n 11 - exit\n";
		cout << endl;
		cin >> selection;
	} while (selection < 1 || selection > 11); //keep showing menu if choice is not valid

	return selection; //return choice
}
