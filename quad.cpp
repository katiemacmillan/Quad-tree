#include <iostream>
#include <string>
#include <cstring>
#include "functions.h"
#include "compress.h"
#include <fstream>

using namespace std;
// prototypes
void printQuad (Qnode* root);

int main (int argc, char**argv)
{

	char* input = argv[1];
	int epsilon = atoi(argv[2]);
//	std::string temp = "cat.bmp";
//	char* input = new char [argv[1].size];
//	std::strcpy(input, temp.c_str());
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

	evaluateQuad (epsilon, root, imgPtr);
//	printQuad (root);

//    cout << "rows: " << rows << endl;
//    cout << "cols: " << cols << endl;
	cout << "DONE" << endl;

	return 0;
}


// void printQuad (Qnode* root)
// {
// 	if (root->child[0] == NULL)
// 	{
// 		cout << "intensity" << root->data[3] << endl;
// 		return;
// 	}	
// 	for(int i = 0; i < 4; i++)
// 	{
// 		printQuad(root->child[i]);
// 	}
// 	return;
// }