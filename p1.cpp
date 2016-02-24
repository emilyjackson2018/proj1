/* 
 * Name: Emily Jackson (811878298) and Paige Marogil (811081799)
 * Assignment: p0 (CSCI 2720)
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
//#include <Queue.h>
//#include <Stack.h>
//#include <Order.h>

using namespace std;

/**
  @param const int arg c
  @param const char * argv[]
  The purpose of this function is to take in an input textfile, read the integers on each
  line and store them in an array. The program will not store the value if it is a
  duplicate. Then the size of the array is outputted and an output file is made with
  the values of the array in reverse order.
  */
int main (const int argc, const char * argv []) {

	ifstream in(argv[1]);
	stringstream buffer;
	buffer << in.rdbuf();
	string test = buffer.str();
	cout << test << endl << endl;

	//create variables that will act as "cursors". we'll take everything between them.
	size_t pos1 = 0;
	size_t pos2;

	//create the array to store the strings.
	string str[256];

	for (int x = 0; x <= 3; x++){
		pos2 = test.find(",", pos1); //search for the bar "|". pos2 will be where the bar was found.
		str[x] = test.substr(pos1, (pos2-pos1)); //make a substring, wich is nothing more 
		//than a copy of a fragment of the big string.
		cout << str[x] << endl;
		cout << "pos1:" << pos1 << ", pos2:" << pos2 << endl;
		pos1 = pos2+1; // sets pos1 to the next character after pos2. 
		//so, it can start searching the next bar |.

		ofstream outputFile;
		outputFile.open("output.txt"); //creates text file for outfile

		outputFile << str[x] << endl;

		outputFile.close();

	}

	if (argv[1] == NULL) 
		cout << "Unable to open file." << endl; //user entered wrong input

	return 0;
}
