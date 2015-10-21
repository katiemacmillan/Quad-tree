#include "compress.h"


bool evaluateQuad ( int epsilon, Qnode* root, unsigned char** image )
{
	int range = getRange (image, root);
//	cout << "range: " << range << endl;
//	cout << "epsilon: " << epsilon << endl;
//	cout << "count: "<< count <<endl;
	if (range > 2*epsilon)
	{
		if (!divideQuad(root))
		{
			cout << "Could not divide root"<< endl;
			return false;
		}
		for(int i = 0; i < 4; i++)
		{
//			cout <<"Xstart: " << root->data[0] << endl;
			evaluateQuad(epsilon, root->child[i], image);
		}
	}
	else
	{
		root->data[3] = getMean(image, root);
	}
//	cout << "yes!\n";
	return true;

}

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

bool divideQuad (Qnode* root)
{
//	cout << "divide"<<endl;
	int xstart = root->data[0];
	int ystart = root->data[1];
	int size = root->data[2]/2;
	for (int i = 0; i < 4; i++)
	{
//		cout << "newchild"<< endl;
		Qnode* newchild = new Qnode;
		if(!newchild)
			{return false;}
		switch (i){
			case 0 :
				newchild->data[0] = xstart;
				newchild->data[1] = ystart;
				break;
			case 1 :
				newchild->data[0] = xstart;
				newchild->data[1] = ystart+size;
				break;
			case 2:
				newchild->data[0] = xstart+size;
				newchild->data[1] = ystart;
				break;
			case 3:
				newchild->data[0] = xstart+size;
				newchild->data[1] = ystart+size;
				break;
		}
		newchild->data[2] = size;
		root->child[i]=newchild;
	}
	return true;
}
int getMean ( unsigned char** image, Qnode* root)
{
//	cout << "Mean"<<endl;
	int sum = 0;
	int size = root->data[2];

	for (int x = root->data[0]; x < root->data[0]+size; x++)
	{
		for (int y = root->data[1]; y < root->data[1]+size; y++)
		{
//			cout << "X: " << x << "\nY: "<< y << endl;
			sum += (int)image[x][y];
//			cout <<"pixel: "<< (int)image[x][y] << endl;
		}
	}
	if(size == 0)
		return sum;

	return (int)sum/(size*size);
}