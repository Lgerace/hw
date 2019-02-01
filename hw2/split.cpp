/*
CSCI 104: Homework 2 Problem 6

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;



/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
	Node* temp = in;
	if (in == NULL){
		cout << "List is empty" << endl;
		return;
	}
	Node* head = in->next;
	//Even 
	if(head->value%2 == 0){
		evens = head;
		evens->value = head->value;
		evens = head->next;
		split(head, odds, evens);

	}

	//Odd
	else if (head->value%2 == 1){
		odds = head;
		odds->value = head->value;
		odds = in->next;
		split(in, odds, evens);

	}

	temp = NULL;
	return;

}


/* If you needed a helper function, write it here */
