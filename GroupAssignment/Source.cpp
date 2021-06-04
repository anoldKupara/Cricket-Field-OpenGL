//if #include <glut.h> does not work then replace it with #include <GL/glut.h>
#include <GL/glut.h>
void pitch()
{
	glPushMatrix();
	glColor3f(1, 1, 1); glTranslated(0, -3, 0); glScaled(12, 1, 9); glutSolidCube(1);
	glColor3f(0, 0, 0); glutWireCube(1);
	glPopMatrix();
}
void wickets()
{
	glPushMatrix(); //wickets on right side
	glColor3f(0, 0, 0); glTranslated(5.9, -2, 0); glScaled(0.1, 1.3, 9); glutSolidCube(1);
	glColor3f(0, 0, 0); glutWireCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1, 0, 0); glTranslated(5.9, -2.2, 0); glScaled(0.1, 1.3, 9); glutSolidCube(1);
	glColor3f(0, 0, 0); glutWireCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0, 1); glTranslated(5.8, -2.5, 0); glScaled(0.1, 1.3, 9); glutSolidCube(1);
	glColor3f(0, 0, 0); glutWireCube(1);
	glPopMatrix();
	glPushMatrix(); //wickets on right side
	glColor3f(0, 0, 0); glTranslated(-5.9, -2, 0); glScaled(0.1, 1.3, 9); glutSolidCube(1);
	glColor3f(0, 0, 0); glutWireCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1, 0, 0); glTranslated(-5.9, -2.2, 0); glScaled(0.1, 1.3, 9); glutSolidCube(1);
	glColor3f(0, 0, 0); glutWireCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0, 1); glTranslated(-5.8, -2.5, 0); glScaled(0.1, 1.3, 9); glutSolidCube(1);
	glColor3f(0, 0, 0); glutWireCube(1);
	glPopMatrix();
}
void boundary()
{
	glPushMatrix();
	glColor3f(1, 1, 1); glTranslated(0, 3.5, 0); glScaled(20, 0.5, 9); glutSolidCube(1);
	glColor3f(0, 0, 0); glutWireCube(1);
	glPopMatrix();
}
void background()
{
	glColor3f(0, 1, 0.372549); glRecti(-3, -2, 3, 1); //ground
	glColor3f(0.22, 0.69, 0.87); glRecti(-3, 1, 3, 2); //sky
	glPushMatrix();
	glTranslated(0, 0, 0); glScaled(0.3, 0.3, 0.1); pitch(); wickets(); boundary();
	glPopMatrix();
}
void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION); glLoadIdentity();
	glOrtho(-3, 3, -2, 2, -4, 4); background();
	glutSwapBuffers();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Cricket Pitch");
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glClearColor(1, 1, 1, 1);
	glutMainLoop();
	return 0;
	

}
