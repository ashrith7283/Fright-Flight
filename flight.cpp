#include<stdlib.h>
#include<GL/glut.h>
#include<Windows.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>

void display();
void drawc();
float i,f=0,l=0,g=0;
void idle();
void drawborder();
void drawCircle();
void drawString(int x,int y,const char *st)
{
	int l,i;
	l=strlen(st);
	glRasterPos2i(x,y);
	
	for(i=0;i<l;i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,st[i]);
	}
	
}

void idle()
{
	
	glColor3f(1.0,1.0,1.0);
	drawString(100,100,"Controls:");
	drawString(150,100,"Slow -> S");
	drawString(200,100,"Medium -> M");
	drawString(260,100,"Fast -> F");
	drawString(310,100,"Very Fast -> V");
	drawString(370,100,"Exit -> E");
	  
}

void drawTraingles()
{
	
	if(f==0)
	glColor3f(1.0,0.0,0.0); //red
	glBegin(GL_TRIANGLES);
	glVertex2f(250,250);
	glVertex2f(350,250);
	glVertex2f(312.384552,328.154785);	
	glEnd();


	if(f==0)
	glColor3f(1.0,0.5,0.0); 
	//orange
	glBegin(GL_TRIANGLES);
	glVertex2f(250,250);
	glVertex2f(312.384552,328.154785);
	glVertex2f(227.836639,347.51300);	
	glEnd();
	
	if(f==0)
	glColor3f(1.0,1.0,0.0); //yellow
	glBegin(GL_TRIANGLES);
	glVertex2f(250,250);
	glVertex2f(227.836639,347.51300);
	glVertex2f(159.962433,293.511322);
	glEnd();

	if(f==0)
	glColor3f(0.0,1.0,0.0); //green
	glBegin(GL_TRIANGLES);
	glVertex2f(250,250);
	glVertex2f(159.962433,293.511322);
	glVertex2f(159.824295,206.775681);
	glEnd();

	if(f==0)
	glColor3f(0 ,0.74902 ,1.0); //blue
	glBegin(GL_TRIANGLES);
	glVertex2f(250,250);
	glVertex2f(159.824295,206.775681);
	glVertex2f(227.526154,152.558090);
	glEnd();

	if(f==0)
	glColor3f(0.0,0.0,1.0); //indigo
	glBegin(GL_TRIANGLES);
	glVertex2f(250,250);
	glVertex2f(227.526154,152.558090);
	glVertex2f(312.135315,171.646912);
	glEnd();

	if(f==0)
	glColor3f(0.309804 ,0.184314,0.309804); //voilet
	glBegin(GL_TRIANGLES);
	glVertex2f(250,250);
	glVertex2f(312.135315,171.646912);
	glVertex2f(349.999512,249.681488);
	glEnd();
	glFlush();
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 40; //# of triangles used to draw circle
	glColor3f(0 ,0.0 ,0.0);

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.14;
	glLineWidth(8);
	glBegin(GL_LINE_LOOP);
	
		//glVertex2f(x,y); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
			
		}
	glEnd();
	
	glFlush();
}


void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);;
	glLoadIdentity();


}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1010,730);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Flight");
	glEnable(GL_DEPTH_TEST);
	
	glutFullScreen();
	//glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	glutMainLoop();
	
	return 0;
}
void SpinnerMotion(int speed)
{
     
	 //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	 glPushMatrix();

	 glTranslatef(250,250,0.0); // 3. Translate to the object's position.
     glRotatef(-i,0.0,0.0,1.0); // 2. Rotate the object.
     glTranslatef(-250,-250,0.0); // 1. Translate to the origin.

     // Draw the object
     drawc();
	 i+=speed;
	 
	 	 glutPostRedisplay();
		 if(g==1&&i>50000)
		 f=1;
		
	 glPopMatrix();
	 //glutSwapBuffers();
}

void drawc()
{
	
	drawFilledCircle(250,250,90);
	drawFilledCircle(250,250,91);
	drawFilledCircle(250,250,92);
	drawFilledCircle(250,250,93);
	drawFilledCircle(250,250,94);
	drawFilledCircle(250,250,95);
	drawFilledCircle(250,250,96);
	drawFilledCircle(250,250,97);
	drawFilledCircle(250,250,98);
	drawFilledCircle(250,250,99);
	drawFilledCircle(250,250,100);
	glColor3f(1.0,1.0,1.0);
	drawTraingles();
}
void keys(unsigned char key, int x, int y)
{
	if(key=='s'||key=='S')
	{
		f=0; 
		g=0;
		l=1;
	}
	else if(key=='m'||key=='M')
	{
		f=0;
		g=0;
		l=2;
	}
	else if(key=='f'||key=='F')
	{
		f=0;
		g=0;
		l=3;
	}
	else if(key=='v'||key=='V')
	{
		
		i=0;
		g=1;
		l=4;
		
	}
	else if(key=='x'||key=='X')
	{
		l=0;
	}
	else if(key=='e'||key=='E')
	{
		exit(0);
	}
	
		
}
void drawCircle(float x,float y,float r)
{
	float t;
	glBegin(GL_POLYGON);
	for(t=0;t<360;t=t+0.2)
		glVertex2f(x+r*cos(t),y+r*sin(t));
	glEnd();
	
}

void drawborder()
{
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(10,0);
	glVertex2f(10,500);
	glVertex2f(0,500);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,10);
	glVertex2f(500,10);
	glVertex2f(500,0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(500,0);
	glVertex2f(500,500);
	glVertex2f(490,500);
	glVertex2f(490,0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0,500);
	glVertex2f(500,500);
	glVertex2f(500,490);
	glVertex2f(0,490);
	glEnd();

	for(int z=10;z<500;z+=15)
		drawCircle(z,10,10);

	for(int z=10;z<500;z+=19)
		drawCircle(10,z,10);

	for(int z=10;z<500;z+=15)
		drawCircle(z,490,10);

	for(int z=10;z<500;z+=19)
		drawCircle(490,z,10);
}



void display()
{
	glClearColor(0 ,0.0 ,0.0,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	
	
	if(l==0)
	drawc();
	else if(l==1)
	SpinnerMotion(5);
	else if(l==2)
		SpinnerMotion(8);
	else if(l==3)
		SpinnerMotion(10);
	else if(l==4)
		SpinnerMotion(15);

	
	glutKeyboardFunc(keys);
	glutSwapBuffers();
	
	glutPostRedisplay();
	
	
}












