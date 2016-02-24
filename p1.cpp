/* 
 * Name: Emily Jackson (811878298) and Paige Marogil (811081799)
 * Assignment: p0 (CSCI 2720)
 */

#include <iostream>
#include <fstream>
#include <string.h>

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
	string line;
	ifstream myfile (argv[1]);
	string str = ""; 

	string myArray[256];
	int c = 0;
	int temp;

	if (myfile.is_open())
	{
		while (getline (myfile,line))
		{
			temp = c;
			for (int i = 0; i < temp; i++) {
				if (i == temp - 1){
					myArray[c] = line;
					c++;
				}
			}
			if (temp == 0){ //sets first value of array
				myArray[c] = line;
				c++;
			}
		}	

		cout << "Array size: " << c << endl;//prints array size

		myfile.close();


		ofstream outputFile;
		outputFile.open("output.txt"); //creates text file for outfile
		

		for (int i = 0; i <= c; i++){
			outputFile << myArray[i] << endl;
		}

		outputFile.close();

	}
	else cout << "Unable to open file." << endl; //user entered wrong input

	return 0;
} //main


