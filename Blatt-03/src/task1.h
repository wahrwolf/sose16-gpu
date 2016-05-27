#include <iostream>


using namespace std;

//Konstanten
static const int KEY_ESCAPE=27;

//Prototypen
double listValidTripel(int);

void task1(int argc, char **argv)
{
	int c;
	cout << "Enter c:" << endl  << "$";
	cin >> c;
	cout << "Solved in " << listValidTripel(c) << " steps";
	
}


bool isValid(int x, int y, int z, int c)
{
	
	return (z >= 0 && (x+y+z) == c );
}

double listValidTripel(int c)
{
	int z;
	double steps = 0;
	for(int x = 0; x <= c/2 + (c%2); x++)
	{
		
		for(int y =0; y <= c-x ; y++)
		{
			z = c-(x+y);
			if(isValid(x, y, z, c))
			{
				cout << "[" << x << ", " << y << ", " << z << "]" << endl;
			}
			steps ++;
		}
	}
	return steps;
}
