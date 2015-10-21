#include <iostream>
#include <string>
#include <cstring>
#include "functions.h"
#include "compress.h"
#include <fstream>

using namespace std;
// prototypes

int main (int argc, char**argv)
{

	std::string temp = "cat.bmp";
	char* input = new char [temp.length()+1];
	std::strcpy(input, temp.c_str());
	int rows;
	int cols;
	unsigned char** imgPtr;

	if (!LoadBmpFile(input, rows, cols, imgPtr))
		cout << "Unable to load BMP!" << endl;
	else
		cout << "SUCCESS!" << endl;

	Qnode* root = new Qnode;
	root->data[0] = 0;
	root->data[1] = 0;
	root->data[2] = rows;

	cout << "X: " << root->data[0] << endl;
	cout << "Y: " << root->data[1] << endl;
	cout << "Size: " << root->data[2] << endl;

	cout << "range: " << getRange ( imgPtr, root ) << endl;;

	cout << "mean: " << getMean (imgPtr, root) << endl;
	int count = 0;


    // for ( int i = 0; i < rows; i++ )
    // {
    //     for ( int j = 0; j < cols; j++ )
    //     {
    //         cout << imgPtr[i][j] << "  ";		// Grayscale Image
    //         count++;
    //     }
    // }

    cout << "rows: " << rows << endl;
    cout << "cols: " << cols << endl;
    cout << "pixel values: " << count << endl;


	return 0;
}
