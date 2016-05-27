#include <iostream>
#include <GL/freeglut.h>


using namespace std;

//Konstanten
static const int KEY_ESCAPE=27;

//Prototypen
void renderSceneCB();
void initializeGlutCallbacks();
void keyPressed(unsigned char, int, int);

void task1(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Hello Glut");
	
	initializeGlutCallbacks();

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
			case GLUT_KEY_LEFT:
				key = '<';
				break;
			case GLUT_KEY_RIGHT:
				key = '>';
				break;
			case GLUT_KEY_UP:
				key = '^';
				break;
			case GLUT_KEY_DOWN:
				key = 'V';
				break;
		}
			cout << "--> Pressed Key[" << key << "]" ;
			cout << " Press ESC to quit <--"; 
			cout << '\r';
			cout << flush;
	
	}
}

