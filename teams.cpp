#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// *You* are not allowed to use global variables
//  but for just the output portion *we* will. ;>
int combo = 1;

// @brief Prints a single combination of teams
//
// @param[in] team1 Array containing the names of team 1
// @param[in] team2 Array containing the names of team 2
// @param[in] len Size of each array
void printSolution(const string* team1, 
		   const string* team2,
		   int len)
{

  cout << "\nCombination " << combo++ << endl;
  cout << "T1: ";
  for(int i=0; i < len; i++){
    cout << team1[i] << " ";
  }
  cout << endl;
  cout << "T2: ";
  for(int i=0; i < len; i++){
    cout << team2[i] << " ";
  }

  cout << endl;
  mash(team2,team1,len);
}

// You may add additional functions here
void mash (const string* team1, 
		   const string* team2,
		   int len){


	int l= team1.len();
	for(int i=l; i >=len ; i--){
	 	string a; 
	 	*a = &team1[i];
	 	team1[i] = &team2[i];
		team2[i] -> a;
	 	}
	printSolution(team2,team1,len-1);
}






int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide a file of names" << endl;
    return 1;
  }

  ifstream ifile(argv[1]);
  if(ifile.fail()){
    cerr << "Unable to open input  file" << endl;
    return 1;
  }


  int number=0;
  string s;
  int b=0;
  int c=0;
  int d=0;
  getline(ifile, s);
  istringstream num(s);
  num >> number;
  //cout << number << endl;

  string *ss1 = new string[number];
  string *ss2 = new string[number];
  while(getline(ifile, s)){
    istringstream abc(s);
    string a;
    while(abc >> a){
    	/*
    	ss[c] =a;
    	c++;
    	*/
    	if (b%2==0){
    		ss1[c] = a;
    		c++;
    	}
    	else {
    		ss2[d] = a;
    		d++;
    	}
    	b++;
    }

  }
  
  printSolution(ss1,ss2,number);





 
  // Complete the rest of main
  ifile.close();

  for (int i=0; i<number-1; i++){
    delete &ss1[i];
    delete &ss2[i];
  }
  delete [] ss1;
  delete [] ss2;


  return 0;
}
