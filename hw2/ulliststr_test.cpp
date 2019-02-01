/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
	ULListStr* item =new ULListStr();

	//checks if empty evaluates to true when it is empty 
	if (item->empty()){
		cout << "Correct it is empty" << endl;
	}
	else {
		cout << "Incorrect, returns it is not empty" << endl;
	}


	//Tests non-edge case of push_front fxn 
	//that is when list is empty add 5 integers to the array
	string a = "apples";
	string b = "bananas";
	string c = "cat";
	string d = "dog";
	string e = "e";
	string f = "f";
	string g = "g";
	string h = "h";
	string i = "i";
	string j = "j";
	string k = "k";
	string l = "lemons";

	item->push_front(a);

	//checks if empty evaluates to true when it is empty 
	if (item->empty()){
		cout << "Incorrect, it is empty" << endl;
	}
	else {
		cout << "Correct, it is not empty" << endl;
	}

	item->push_back(b);
	item->push_back(c);
	item->push_back(d);
	item->push_back(e);
	item->push_back(f);
	item->push_back(g);
	item->push_back(h);
	item->push_back(i);
	
	
	cout << 9 << endl;
	item->push_back(j);
	cout << 10 << endl;
	item->push_back(k);
	cout << 11 << endl;
	item->push_back(l);
	cout << 12 << endl;
	
	item->getValAtLoc(1);
	item->getValAtLoc(2);
	item->getValAtLoc(3);
	item->getValAtLoc(4);
	item->getValAtLoc(5);
	item->getValAtLoc(6);
	item->getValAtLoc(7);
	item->getValAtLoc(8);
	item->getValAtLoc(9);
	item->getValAtLoc(10);




	item->clear();
	delete item;
	return 0;
}
