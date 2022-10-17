#include<windows.h>
#include <GL/glut.h>
using namespace std;
bool pause=false;
int posx = 0;
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Set display window colour to white

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	gluOrtho2D(0.0, 65.0, 0.0, 82.0);

}

void line_drawing(float a, float b, float c, float d)
{
    // Draw an outlined triangle
	glBegin(GL_LINES);

		glVertex2f(a, b);
		glVertex2f(c, d);


	glEnd();
}

void quads(float a, float b, float c, float d, float e, float f, float g, float h){

    glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//Trapezoid
	glVertex2f(a, b);
	glVertex2f(c,d);
	glVertex2f(e, f);
	glVertex2f(g, h);

	glEnd(); //End quadrilateral coordinates


}

void triangle(float a, float b, float c, float d, float e, float f){
   glBegin(GL_TRIANGLES);
   //Triangle
	glVertex2f(a, b);
	glVertex2f(c, d);
	glVertex2f(e, f);

	glEnd();//End triangle coordinates

}

void pentagon(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r)
{
    glBegin(GL_TRIANGLES); //Begin triangle coordinates

	//Pentagon
	glVertex2i(a, b);
	glVertex2i(c, d);
	glVertex2i(e, f);

	glVertex2i(g, h);
	glVertex2i(i, j);
	glVertex2i(k, l);

	glVertex2i(m, n);
	glVertex2i(o, p);
	glVertex2i(q, r);

	glEnd();//End triangle coordinates
}



///river
void river()
{
    glColor3f(0.0352941176470588, 0.5098039215686275, 0.9568627450980392);
    glBegin(GL_POLYGON);

    glVertex3i(14, 0, 0);
    glVertex3i(12, 12, 0);
    glVertex3i(50, 12, 0);
    glVertex3i(49, 0, 0);


glEnd();



}

void boat()
{
   quads(18.0,20.0,18.0,24.0,20.0,24.0,20.0,20.0);
   quads(16.4,16.0,16.4,24.0,18.0,24.0,18.0,16.0);
   glColor3f(0,0,0);
   quads(17.5,24.0,17.5,28.0,19.0,28.0,19.0,24.0);
   glColor3f(1,0,1);
   quads(20.5,20.0,20.5,22.0,26.0,22.0,26.0,20.0);


    glColor3f(0,0,0);
    glBegin(GL_POLYGON);


    glVertex3i(19,12,0);
    glVertex3i(16,16,0);
    glVertex3i(30,16,0);
    glVertex3i(26,12,0);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);


    glVertex3i(18,16,0);
    glVertex3i(18,20,0);
    glVertex3i(28,20,0);
    glVertex3i(28,16,0);
    glEnd();
    glColor3f(1,0.7,0);
   glBegin(GL_TRIANGLES);

    glVertex3i(28,16,0);
    glVertex3i(28,20,0);
    glVertex3i(30,16,0);

    glEnd();




}
void update(int value) {

    if(pause==false){
    if(posx>=22)
    {
        posx=0;
    }
    else{
        posx++;
    }}
    glutPostRedisplay();
	glutTimerFunc(250, update, 0);
}
void tree()
{
    ///tree1
    glColor3f(0.6156863,0,0);

    glBegin(GL_POLYGON);

    glVertex3i(5, 12, 0);
    glVertex3i(7, 12, 0);


    glVertex3i(7, 30, 0);
    glVertex3i(5, 30, 0);

    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(1, 30, 0);
    glVertex3i(11, 30, 0);


    glVertex3i(6, 40, 0);

    glEnd();
    glBegin(GL_POLYGON);


    glVertex3i(1, 35, 0);
    glVertex3i(10, 35, 0);


    glVertex3i(6, 45, 0);



glEnd();

}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

   // glColor3f(0.0f, 0.1f, 0.0f);//Forest Green
    glColor3f(0.0f, 1.0f, 0.0f);//Green



   quads(0.0,0.0,0.0,13.0,90.0,13.0,90.0,0.0); //


   glColor3f(0.0f, 1.0f, 1.0f);
   //sky
   glColor3f(0.0,0.9,0.9);
   quads(0.0,12.0,0.0,85.0,85.0,85.0,85.0,12.0);

   //glColor3f(0.0f, 1.0f, 0.0f);//Green
   //quads(4,11.0,4.0,32.0,6.0,32.0,6.0,11.0);

	//Set colour to black
	glColor3f(0.0, 0.0, 0.0);
	//Adjust the point size
	glPointSize(5.0);

	//Set colour to red

    //tr

   // glColor3f(0.0, 0.60, 1.0);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red







    glColor3f(1.0f, 1.89f, 0.89f);
    triangle(55.0,25.0,58.0,35.0,61.0,25.0);
    glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);

    quads(55.0,12.0,55.0,25.0,61.0,25.0,61.0,12.0);

    tree();
    river();
   // pentagon();

        glPushMatrix();
        glTranslatef(posx,-1,-1);
        boat();
        glPopMatrix();



	glFlush();	// Process all OpenGL routines
}

void keyPressed(unsigned char key, int x, int y)
{
	//keyStates[key] = true;
	if(key=='p')
    {
        pause=true;
    }
    if(key=='r')
    {
        pause=false;
    }
	glutPostRedisplay();
}




int main(int argc, char* argv[])
{
	glutInit(&argc, argv);						     // Initalise GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	     // Set display mode

	glutInitWindowPosition(50, 100);				// Set window position
	glutInitWindowSize(600, 600);					// Set window size
	glutCreateWindow("Village View");	// Create display window

	init();							// Execute initialisation procedure
	glutDisplayFunc(drawShapes);
	glutTimerFunc(0, update, 0);		// Send graphics to display window
	glutKeyboardFunc(keyPressed);

	glutMainLoop();					// Display everything and wait

	return 0;
}
