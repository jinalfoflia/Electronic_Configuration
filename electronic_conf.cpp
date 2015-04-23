#include <GL/glut.h>  
#include <stdio.h>    
#include <math.h>     
#include<string.h>
int state;
GLfloat LightAmbient[]= { .5f, .5f, 0.5f, 1.0f };
GLfloat LightDiffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightPosition[]= { 5.0f, 25.0f, 15.0f, 1.0f };
GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
static int view_state = 0, light_state = 0;
int spin;
int st;
void Sprint( int x, int y,int z,char *st)
{
	int l,i;
	l=strlen( st );
	glRasterPos3i( x,y,z); 
	for( i=0; i < l; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
	}
}
static void TimeEvent(int te)
{
	spin++;  
	if (spin > 360) spin = 0; 
		glutPostRedisplay();  
	glutTimerFunc( 100, TimeEvent, 1);
}

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);  
   glShadeModel (GL_SMOOTH);  
   glEnable(GL_DEPTH_TEST);  
   glLightfv(GL_LIGHT1 ,GL_AMBIENT, LightAmbient);
   glLightfv(GL_LIGHT1 ,GL_DIFFUSE, LightDiffuse);
   glLightfv(GL_LIGHT1 ,GL_POSITION, LightPosition);
   glEnable(GL_LIGHTING);  
   glEnable(GL_LIGHT1);    
}


void Draw_atom_He(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)
{
	glColor3f(1.0,.0,5.0);
	Sprint(-22,25,2,"HELIUM");
	Sprint(20, 25,2,"  1st : 2");
	glRotatef( 60, 1.0, 0.0, 0.0); 
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 8);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 10, 16, 32);
	
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, -10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void Draw_atom_Ne(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)
{
	int i;
	glColor3f(1.0,0.0,5.0);
	Sprint(-22,25,2,"NEON");
	Sprint(20, 25,2,"  1st : 2");
	Sprint(20, 22,2,"  2nd : 8");
	glRotatef( 60, 1.0, 0.0, 0.0); 
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 8);
	
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 10, 16, 32);
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0);
	glRotatef(360 - orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 15, 16, 32);
	for ( i=0; i < 8; i++)
    {
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 15, 0);
		glColor3f(0.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
    }
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void Draw_atom_Ar(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)
{
	int i;
	glColor3f(1.0,.0,5.0);
	Sprint(-22,25,2,"ARGON");
	Sprint(20, 25,2,"  1st : 2");
	Sprint(20, 22,2,"  2nd : 8");
	Sprint(20, 19,2,"  3rd : 8");
	glRotatef( 60, 1.0, 0.0, 0.0); 
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 8);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 10, 16, 32);
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0);
	glRotatef(360 - orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 15, 16, 32);
	for ( i=0; i < 8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 15, 0);
		glColor3f(0.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 0.0, 1.0);
	glRotatef(270 - orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 20, 16, 32);
	for ( i=0; i < 8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 20, 0);
		glColor3f(0.9, .5, .1);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void Draw_atom_Kr(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)
{
	int i;
	glColor3f(1.0,.0,5.0);
	Sprint(-22,25,2,"KRYPTON");
	Sprint(20, 25,2,"  1st : 2");
	Sprint(20, 22,2,"  2nd : 8");
	Sprint(20, 19,2,"  3rd : 18");
	Sprint(20, 16,2,"  4th : 8");
	glRotatef( 60, 1.0, 0.0, 0.0); 
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 8);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 10, 16, 32);
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 15, 16, 32);
	for ( i=0; i <8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 15, 0);
		glColor3f(0.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 0.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 20, 16, 32);
	for ( i=0; i < 18; i++)
	{
		glPushMatrix();
		glRotatef((360/18) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 20, 0);
		glColor3f(0.9, .5, 1.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 1.0, 1.0);
	glRotatef(360 - orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 25, 16, 32);
	for ( i=0; i < 8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 25, 0);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void Draw_atom_Xe(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)
{
	int i;
	glColor3f(1.0,.0,5.0);
	Sprint(-22,25,2,"XENON");
	Sprint(20, 25,2,"  1st : 2");
	Sprint(20, 22,2,"  2nd : 8");
	Sprint(20, 19,2,"  3rd : 18");
	Sprint(20, 16,2,"  4th : 18");
	Sprint(20, 13,2,"  5th : 8");
	glRotatef( 60, 1.0, 0.0, 0.0); 
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 8);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 10, 16, 32);
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.1, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -10, 0);
	glColor3f(0.0, 0.1, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 15, 16, 32);
	for ( i=0; i <8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 15, 0);
		glColor3f(0.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 0.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 20, 16, 32);
	for ( i=0; i < 18; i++)
	{
		glPushMatrix();
		glRotatef((360/18) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 20, 0);
		glColor3f(0.0, .8, 1.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(60, 0.5, 0.0, 1.0);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 25, 16, 32);
	for ( i=0; i < 18; i++)
	{
		glPushMatrix();
		glRotatef((360/18) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 25, 0);
		glColor3f(.9, 0.5, 0.3);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(75, .5, .8, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 30, 16, 32);
	for ( i=0; i < 8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 30, 0);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void Draw_atom_Ra(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)
{
	int i;
	glColor3f(1.0,0.0,5.0);
	Sprint(-22,25,2,"RADON");
	Sprint(22, 25,2,"  1st : 2");
	Sprint(22, 22,2,"  2nd : 8");
	Sprint(22, 19,2,"  3rd : 18");
	Sprint(22, 16,2,"  4th : 32");
	Sprint(22, 13,2,"  5th : 18");
	Sprint(22, 10,2,"  6th : 8");
	glRotatef( 60, 1.0, 0.0, 0.0); 
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 8);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 8, 16, 32);
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -8, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 12, 16, 32);
	for ( i=0; i <8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 12, 0);
		glColor3f(0.0, 1.0, 1.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 0.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 16, 16, 32);
	for ( i=0; i < 18; i++)
	{
		glPushMatrix();
		glRotatef((360/18) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 16, 0);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(60, 0.5, 0.0, 1.0);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 20, 16, 32);
	for ( i=0; i <32; i++)
	{
		glPushMatrix();
		glRotatef((360/32) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 20, 0);
		glColor3f(.9, .5, 1.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 24, 16, 32);
	for ( i=0; i < 18; i++)
	{
		glPushMatrix();
		glRotatef((360/18) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 24, 0);
		glColor3f(.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(120, 0.5, 0.0, 0.5);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 28, 16, 32);
	for ( i=0; i <8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 28, 0);
		glColor3f(.9, 0.5, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}
void invalid()
{
	glColor3f(1.0,0,5.0);
	Sprint(-10,0,2,"Please Press a KEY from 1 to 6 !");
}
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	glMatrixMode (GL_PROJECTION);  
	glLoadIdentity();  
	glOrtho(-30.0, 30.0, -30.0, 30.0, -100.0, 100.0);  
	glMatrixMode(GL_MODELVIEW);  
	glLoadIdentity(); 
	if (view_state == 1)
	{
		glColor3f( 1.0, 1.0, 1.0);
		Sprint(-8, 25,-10,"Perspective view");
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(65, 1, 1, 70);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt( 0, 0, 50, 0, 0, 0, 0, 1, 0);
	}
	else
	{
		glColor3f( 1.0, 1.0, 1.0);
		Sprint(-8, 25,-10,"Ortho view");
	}
	if (light_state == 1)
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);
	}
	else
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
	}
	
	glColor3f(1.0,0.0,0.0);
	Sprint(-30, 25,2,"1-Helium");
	Sprint(-30, 22,2,"2-Neon");
	Sprint(-30, 19,2,"3-Aron");
	Sprint(-30, 16,2,"4-Krypton");
	Sprint(-30, 13,2,"5-Xenon");
	Sprint(-30, 10,2,"6-Radon");
	Sprint(-30, 7,2,"ESC-exit");
	Sprint(-30,-25,2,"v-view ortho/perspective");
	Sprint(-30,-28,2,"l-lighting on/off");
	Sprint(-30, 7,2,"ESC-exit");
	glColor3f(0.0,1.0,0.0);
	Sprint(-17, 28,2,"ELECTRONIC CONFIGURATION OF NOBLE GASES");
	Sprint(-30, 28,2,"Keyboard Input");
	Sprint(20, 28,2,"orbit : electrons");
	
	if(state== 1)
	{
	Draw_atom_He( 0,0,0,1, spin++);
	}
	if(state == 2)
	{
	Draw_atom_Ne( 0,0,0,1, spin++);
	}
	if(state== 3)
	{
	Draw_atom_Ar( 0,0,0,1, spin++);
	}
	if(state== 4)
	{
	Draw_atom_Kr( 0,0,0,1, spin++);
	}
	if(state== 5)
	{
	Draw_atom_Xe( 0,0,0,1, spin++);
	}
	if(state== 6)
	{
	Draw_atom_Ra( 0,0,0,1, spin++);
	}
	if(state== 7)
	{
		invalid();
	}
	glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
}
void keyboard (unsigned char key, int x, int y)
{
   switch (key)
   {
   case '1': state=1;
	   break;
   case '2':state=2;
	   break;
   case '3':state=3;
	   break;
   case '4':state=4;
	   break;
   case '5':state=5;
	   break;
   case '6':state=6;
	   break;
   case 'v':
   case 'V':view_state = abs(view_state -1);
		break;
   case 'l':
   case 'L':light_state = abs(light_state -1);
		break;
   case 27:exit(0); 
         break;
      default:state=7; 
         break;
   }
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize (1200, 700);
    glutInitWindowPosition (10, 10);
    glutCreateWindow (argv[0]);
    glutSetWindowTitle("GlutWindow");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc( 10, TimeEvent, 1);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
