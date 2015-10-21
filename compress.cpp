#include "compress.h"


// void evaluateQuad ( int epsilon, Qnode* root, unsigned char** image )
// {
// 	int range = getRange (image, root);
// 	if (range > 2*epsilon)
// 	{
// 		divideQuad(root);
// 		for(int i = 0; i < 4; i++)
// 			evaluateQuad(epsilon, root->child[i], image);
// 	}
// 	else
// 	{
// 		//find median
// 		//root->intensity = median;
// 	}

// }

int getRange ( unsigned char** image, Qnode* root )
{
	unsigned char max = image[0][0];
	unsigned char min = image[0][0];
	int size = root->data[2];

	for (int x = root->data[0]; x < root->data[0]+size; x++)
	{
		for (int y = root->data[1]; y < root->data[1]+size; y++)
		{
			if ( (int)image[x][y] < (int)min )
				min = image[x][y];
			else if ((int)image[x][y] > (int)max)
				max = image[x][y];
		}
	}
	return max-min;
}

// void divideQuad (Qnode* root)
// {

// }
//Go through pixels to get range
int getMean ( unsigned char** image, Qnode* root)
{
	unsigned char mean;
	int sum = 0;
	int count = 0;
	int size = root->data[2];

	for (int x = root->data[0]; x < root->data[0]+size; x++)
	{
		for (int y = root->data[1]; y < root->data[1]+size; y++)
		{
			sum += image[x][y];
		}
	}

	return sum/(size*size);
}