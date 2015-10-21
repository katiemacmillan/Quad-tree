#include <iostream>
#include <cstring>

using namespace std;

struct Qnode
{
	int data[4] = {-1, -1, -1, -1};
	Qnode* child[4] = {nullptr, nullptr, nullptr, nullptr};
	
/*	data[0]: start row
	data [1]: start column
	data[2]: size
	data[3]: intensity
*/
};

bool evaluateQuad ( int epsilon, Qnode* root, unsigned char** image );
int getRange ( unsigned char** image, Qnode* root );
int getMean ( unsigned char** image, Qnode* root);
bool divideQuad (Qnode* root);

