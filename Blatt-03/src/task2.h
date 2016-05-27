#include <iostream>
#include "bitmap_image.hpp"
#include <vector>
#include <math.h>


using namespace std;

//Protoype
void initBitmap(int, int);

//global Variables
bitmap_image bitmap;

int task2()
{
	initBitmap(800,600);

	bitmap.save_image("foobar.bmp");

	return 0;
}

void initBitmap(int sizeX, int sizeY)
{
	char randP;
	bitmap = bitmap_image(sizeX, sizeY);

	for(int x = 0; x <sizeX; x++)
	{
		for(int y = 0; y < sizeY; y++)
		{
			randP = (char) rand()%2;
			bitmap.set_pixel(x, y, randP, randP, randP); 
		}
	}
}

// Vektor stuff

double absVector(vector<double> v)
{
	double puffer = -1;
	for(int i = 0; i < v.size(); i++)
	{
		puffer += pow(v[1],2);
	}
	return sqrt(puffer);
}
