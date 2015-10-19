#include <iostream>
#include <string>
#include <cstring>
#include "functions.h"
#include <fstream>

using namespace std;
// prototypes

int main (int argc, char**argv)
{

	std::string temp = "image.bmp";
	char* input = new char [temp.length()+1];
	std::strcpy(input, temp.c_str());
	int rows;
	int cols;
	unsigned char* imgPtr;

	if (!LoadBmpFile(input, rows, cols, imgPtr))
		cout << "Unable to load BMP!" << endl;
	else
		cout << "SUCCESS!" << endl;

	return 0;
}
