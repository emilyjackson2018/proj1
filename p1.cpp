#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int main (const int argc, const char * argv[]) {
	char line[100];
	string words[100];
	int i = 0;
	
	/*int begin, end, size;
	ifstream tempfile (argv[1]);
	begin = tempfile.tellg();
	tempfile.seekg (0, ios::end);
	end = tempfile.tellg();
	tempfile.close();
	size = end - begin;*/

	int size = 100;

	ifstream myfile (argv[1]);
	if (myfile.is_open())
	{
		for(i = 0; i < size; ++i) {
			myfile.getline(line, size);
			words[i]=line;
			strcpy(line, "");
		}
		myfile.close();
	}

	else cout << "Unable to open file"; 

	ofstream outputFile;
	outputFile.open("output.txt");	

	for(i = 0; i < size; ++i)
		outputFile << words[i] << endl;

	return 0;
}
