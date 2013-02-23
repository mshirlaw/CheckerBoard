/**************************************************************************************************
This program creates a black and white checkerboard effect using OpenGL
It was initially written as a test to help in learning OpenGL
 
On linux, compile with gcc checker_board.c -o checker_board -lGL -lGLU -lglut
On OSX, gcc checker_board.c -o checker_board -framework Carbon -framework OpenGL -framework GLUT
 
Author: mshirlaw
**************************************************************************************************/

/*OSX*/
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

/*Linux
 #include <GL/glut.h>
 #include <stdio.h>
 */

/*
 Initialises the coordinate system
 Clears the background colour
 */
void init(void)
{
    //clear backgound colour
    glClearColor (0.0, 0.0, 0.0, 0.0);
    
    //set (0,0,0) to bottom left corner
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 50.0, 0.0, 50.0, -1.0, 1.0);
    
}

/*
 Draws a checker board pattern to the screen 
 */
void draw(void)
{
    //clear all pixels
    glClear (GL_COLOR_BUFFER_BIT);
    
    //set colour of square to white
    glColor3f (1.0, 1.0, 1.0);
    
    GLfloat height = 5.0;
    GLfloat width = 5.0;
    GLfloat side = 5.0;
    
    int j=0;
    int k=1;
    
    while(j<10)
    {
        //col 1
        glBegin(GL_QUADS);
            glVertex3f (0.0, 0.0+j*side,0.0f);
            glVertex3f (side,0.0+j*side,0.0f);
            glVertex3f (side,side+j*side,0.0f);
            glVertex3f (0.0,side+j*side,0.0f);
        glEnd();
            
        //col 2
        glBegin(GL_QUADS);
            glVertex3f (0.0+side,0.0+k*side,0.0f);
            glVertex3f (side+side,0.0+k*side,0.0f);
            glVertex3f (side+side,side+k*side,0.0f);
            glVertex3f (0.0+side,side+k*side,0.0f);
        glEnd();
        
        
        //col 3
        glBegin(GL_QUADS);
        glVertex3f (0.0+2*side, 0.0+j*side,0.0f);
        glVertex3f (side+2*side,0.0+j*side,0.0f);
        glVertex3f (side+2*side,side+j*side,0.0f);
        glVertex3f (0.0+2*side,side+j*side,0.0f);
        glEnd();
    
        
        //col 4
        glBegin(GL_QUADS);
            glVertex3f (0.0+3*side,0.0+k*side,0.0f);
            glVertex3f (side+3*side,0.0+k*side,0.0f);
            glVertex3f (side+3*side,side+k*side,0.0f);
            glVertex3f (0.0+3*side,side+k*side,0.0f);
        glEnd();

        
        //col 5
        glBegin(GL_QUADS);
        glVertex3f (0.0+4*side, 0.0+j*side,0.0f);
        glVertex3f (side+4*side,0.0+j*side,0.0f);
        glVertex3f (side+4*side,side+j*side,0.0f);
        glVertex3f (0.0+4*side,side+j*side,0.0f);
        glEnd();


        //col 6
        glBegin(GL_QUADS);
            glVertex3f (0.0+5*side,0.0+k*side,0.0f);
            glVertex3f (side+5*side,0.0+k*side,0.0f);
            glVertex3f (side+5*side,side+k*side,0.0f);
            glVertex3f (0.0+5*side,side+k*side,0.0f);
        glEnd();
        
        
        j = j+2;
        k = k+2;

    }

    
    /*
    //bottom right
    glBegin(GL_QUADS);
        glVertex3f (0.0+2*width, 0.0, 0.0f);
        glVertex3f (side+2*width,0.0,0.0f);
        glVertex3f (side+2*width,side,0.0f);
        glVertex3f (0.0+2*width,side,0.0f);
    glEnd();

    
    
    //top right
    glBegin(GL_QUADS);
        glVertex3f (0.0+2*height, 0.0+2*width, 0.0f);
        glVertex3f (side+2*height,0.0+2*width,0.0f);
        glVertex3f (side+2*height,side+2*width,0.0f);
        glVertex3f (0.0+2*height,side+2*width,0.0f);
    glEnd();
    
    */
    
    glFlush();
    
}

/*
 Declares the intitial window size and 
 opens the window with the Black Window string as the 
 title
 */
int main(int argc, char *argv[])
{
    //initialise glut
    glutInit(&argc, argv);
    
    //set up the window position and size
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowPosition(200,200);
    glutInitWindowSize(500,500);
    glutCreateWindow("CheckerBoard Window");
    
    //initialise the coordinate system
    init();
    
    //call the draw function to draw to the screen
    glutDisplayFunc(draw);
    
    /*
     Other Functions that may be used:
     
     glutReshapeFunc(void (*func)(int w, int h)) 
     indicates what action should be taken when the window is resized. 
     
     glutKeyboardFunc(void (*func)(unsigned char key, int x, int y)) and 
     glutMouseFunc(void (*func)(int button, int state, int x, int y)) 
     allow you to link a keyboard key or a mouse button with a routine 
     that's invoked when the key or mouse button is pressed or released. 
     
     glutMotionFunc(void (*func)(int x, int y)) registers a routine to 
     call back when the mouse is moved while a mouse button is also pressed.
     
     */
    
    glutMainLoop();
    
    return 0;
}
