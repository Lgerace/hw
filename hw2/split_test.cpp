#include "split.h"
#include "split.cpp"
#include <cstddef>
#include <iostream>
using namespace std;

int main(){
	Node head =  Node(0, NULL);
	Node a = head;
	Node evenHead = Node(0, NULL);
	Node oddHead = Node(0, NULL);

	for (int i=0; i<5; i++){
		head->next = Node(i, NULL);
		head = head->next;
	}

	split(a, oddHead, evenHead);

}