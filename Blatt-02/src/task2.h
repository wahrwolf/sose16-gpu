#include <iostream>
#include <GL/freeglut.h>
#include <math.h>
#include <vector>


using namespace std;

//Konstanten
static const int KEY_ESCAPE=27;

//Prototypen

void renderSceneCB();
void initializeGlutCallbacks();
void keyPressed(unsigned char, int ,int);

class Sanduhr;

void task2(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("Sanduhr");
	
	initializeGlutCallbacks();
//	glutDisplayFunc(drawTriangle);
	glutKeyboardUpFunc(keyPressed);
	glutMainLoop();
}


// glut-Callback und Render
void renderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void initializeGlutCallbacks()
{
    glutDisplayFunc(renderSceneCB);
}

// Keyboard stuff
void keyPressed(unsigned char key, int x, int y)
{
	
	if(key == KEY_ESCAPE)
	{
		glutDestroyWindow(glutGetWindow());
	}else{
		switch(key)
		{
		case 'c':
			//komischer mist ... grml
			Sanduhr clock = new Sanduhr();
			glutDisplayFunc(clock.draw);
			break;
		default:
			
			cout << "--> Pressed Key[" << key << "]" ;
			cout << " Press ESC to quit <--"; 
			cout << '\r';
			cout << flush;
		}
	}
}




//utils

	//math stuff

vector<double> rotate2DVector(vector<double> v, double rad)
{	
	double x = v[0];
	double y = v[1];

	v[0] = cos(rad) * x + -sin(rad) * y;
	v[1] = sin(rad) * x + cos(rad) * y;
	return v;
}


	//calc stuff

	

//Class section

class Pyramide
{
	public:

	Pyramide(){}	
	Pyramide(int iniNEdges, double iniR, double iniHeigth)
	{
		nEdges = iniNEdges;
		radius = iniR;
		heigth = iniHeigth;
	}

	void  calc()
	{
		vector<double> cord;

		cord.push_back(0.0);
		cord.push_back(radius);

		for(int i=0; i < nEdges; i++)
		{

			cord.push_back(heigth);
			vVerlauf.push_back(cord);
		
			cout << cord[0] << ", "<< cord[1] <<endl;
			cord.pop_back();

			cord = rotate2DVector(cord, (2*M_PI/nEdges));
		}
	}

	vector<double> init()
	{
		calc();
		vCopy = vVerlauf;
		vector<double> puffer = vCopy.back();
		vCopy.pop_back();
		return puffer;
	}
	
	vector<double> pop()
	{
		vector<double> puffer = vCopy.back();
		vCopy.pop_back();
		return puffer;
	}
	bool isEmpty()
	{
		return vCopy.empty();
	}


	private:

	double nEdges, radius, heigth;
	vector<vector<double>> vVerlauf;
	vector<vector<double>> vCopy;


};

class Sanduhr
{
 	private:
	Pyramide pyramide;
	
	double nEdges, radius, heigth;


	public:
	int const MAX_EDGES = 50;
	int const MIN_EDGES = 3;

	Sanduhr()
	{
		nEdges = 3;
		heigth = 20;
		radius = 10;

	Pyramide pyramide = Pyramide( nEdges, heigth/2, radius);
	pyramide.calc();

	}
		
	void draw()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POLYGON);
			for(vector<double> vCord = pyramide.init(); !pyramide.isEmpty(); vCord = pyramide.pop())
			{
				glVertex3d(vCord[0], vCord[1], vCord[2]);
			}
		glEnd();
		glFlush();
	}

	void changeEdge(bool addEdge)
	{
		if(addEdge && (nEdges < MAX_EDGES)){
			nEdges ++;
		}else if(!addEdge && (nEdges > MIN_EDGES)){
			nEdges--;}
		pyramide.calc();
	}
};


void drawTriangle(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glVertex2i(0,0);
		glVertex2i(200,200);
		glVertex2i(20,200);
	glEnd();
	glFlush();
}


