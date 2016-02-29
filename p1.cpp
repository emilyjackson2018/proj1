#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include "Queue.h"
#include "LinkedList.h"
#include "SuperMarket.h"
#include "Stack.h"

using namespace std;

int main (const int argc, const char * argv[]) {
	string words[100];
	int i = 0;

	ifstream tempfile (argv[1]);
	ifstream myfile (argv[1]);
	int size = 0;
	int count=0;
	char ch;

	tempfile >> ch; // find first non-space char

	// after first non-space found, do not skip spaces
	tempfile.unsetf(ios::skipws);

	while(!tempfile.eof()) {
		tempfile >> ch;
		if(isspace(ch)) {
			count++;
			while(isspace(ch) && !tempfile.eof()) 
				tempfile >> ch; // find next word
		}
	}

	size = count;
	cout << "Word count: " << size << endl;

	if (myfile.is_open())
	{
		for (int i = 0; i < 100; i++)
		{
			getline(myfile, words[i]);
		}
		myfile.close();
	}

	else {
		cout << "Unable to open file" << endl; 
		exit(-1);	
	}
	
	
	ofstream outputFile;
	outputFile.open("output.txt");	

	for(i = 0; i < size; ++i) {
		outputFile << words[i] << endl;
		if ((strncmp(words[i].c_str(), "CATEGORIES", 10)) == 0) {
			cout << "\"Categories\" found!" << endl;
			cout << words[i] << endl;
		}
		else if (strncmp(words[i].c_str(), "ORDERS", 6) == 0) {
			cout << "\"Orders\" found!" << endl;
			cout << words[i] << endl;
		}
		else if (strncmp(words[i].c_str(), "DISPATCH", 7) == 0) {
			cout << "\"Dispatch\" found!" << endl;
			cout << words[i] << endl;
		}
	}
	return 0;
}
