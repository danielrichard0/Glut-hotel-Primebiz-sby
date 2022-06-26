#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

int is_depth;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
}

void tampil(void){
    double i,j;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLineWidth(1.0);
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    //alas hotel
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3d(0, -20, -65);
    glVertex3d(0, -20, 300);
    glVertex3d(150, -20, 300);
    glVertex3d(150, -20, -65);
    glEnd();

    // tembok depan
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(20, -20, 230);
    glVertex3d(20, 30, 230);
    glVertex3d(125, 30, 230);
    glVertex3d(125, -20, 230);
    glEnd();
    //frame tembok depan
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(20.1, -20.1, 230.1);
    glVertex3f(20.1, 30.1, 230.1);
    glVertex3f(125.1, 30.1, 230.1);
    glVertex3f(125.1, -20.1, 230.1);
    glEnd();

    //tembok samping
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(125, -20, 230);
    glVertex3d(125, 30, 230);
    glVertex3d(125, 30, 130);
    glVertex3d(125, -20, 130);
    glEnd();

    //frame tembok samping
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(125.1, -20.1, 230.1);
    glVertex3d(125.1, 30.1, 230.1);
    glVertex3d(125.1, 30.1, 130.1);
    glVertex3d(125.1, -20.1, 130.1);
    glEnd();

    //tembok samping kanan section 1
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(125, -20, 130);
    glVertex3d(125, 30, 130);
    glVertex3d(130, 30, 130);
    glVertex3d(130, -20, 130);
    glEnd();

    //frame tembok samping kanan section 1
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3d(125.1, -20.1, 130.1);
    glVertex3d(125.1, 30.1, 130.1);
    glVertex3d(130.1, 30.1, 130.1);
    glVertex3d(130.1, -20.1, 130.1);
    glEnd();

    //tembok samping kanan section 2
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(130, -20, 130);
    glVertex3d(130, 30, 130);
    glVertex3d(130, 30, 75);
    glVertex3d(130, -20, 75);
    glEnd();
    //tembok samping kanan section 3
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(130, 25, 130);
    glVertex3d(130, 30, 130);
    glVertex3d(130, 30, -45);
    glVertex3d(130, 25, -45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(130, 25, -45);
    glVertex3d(115, 25, -45);
    glVertex3d(115, 30, -45);
    glVertex3d(130, 30, -45);
    glEnd();

     //frametembok samping kanan section 2
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3d(130.1, 30.1, 130.1);
    glVertex3d(130.1, -20.1, 130.1);
    glVertex3d(130.1, -20.1, 75.1);
    glVertex3d(130.1, 25.1, 75.1);
    glVertex3d(130.1, 25.1, -44.9);
    glVertex3d(130.1, 30.1, -44.9);
    glEnd();
    glBegin(GL_LINES);

    //ruang basement belakang
    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(25, -20, -45);
    glVertex3d(25, 30, -45);
    glVertex3d(115, 30, -45);
    glVertex3d(115, -20, -45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(25, -20, -45);
    glVertex3d(25, 30, -45);
    glVertex3d(25, 30, -15);
    glVertex3d(25, -20, -15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(115, -20, -45);
    glVertex3d(115, 30, -45);
    glVertex3d(115, 30, -15);
    glVertex3d(115, -20, -15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(25, -20, -15);
    glVertex3d(25, 30, -15);
    glVertex3d(115, 30, -15);
    glVertex3d(115, -20, -15);
    glEnd();

    //frame bangunan belakang
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(25.1, -19.9, -14.9);
    glVertex3d(25.1, 25.1, -14.9);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(115.1, 30.1, -14.9);
    glVertex3d(115.1, -19.9, -14.9);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(25.1, 30.1, -14.9);
    glVertex3d(115.1, 30.1, -14.9);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3d(25.1, -19.9, -44.9);
    glVertex3d(25.1, 30.1, -44.9);
    glVertex3d(115.1, 30.1, -44.9);
    glVertex3d(115.1, -19.9, -44.9);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(25.1, 30.1, -14.9);
    glVertex3f(25.1, 30.1, -44.9);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(115.1, 30.1, -14.9);
    glVertex3f(115.1, 30.1, -44.9);
    glEnd();

    //tembok lt 1 samping kiri
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(20, -20, 230);
    glVertex3d(20, 30, 230);
    glVertex3d(20, 30, 130);
    glVertex3d(20, -20, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(20, -20, 130);
    glVertex3d(20, 30, 130);
    glVertex3d(25, 30, 130);
    glVertex3d(25, -20, 130);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(20, 30, 230);
    glVertex3d(20, 30, 130);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(20, 30, 130);
    glVertex3d(20, -20, 130);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(20, 30, 130);
    glVertex3d(25, 30, 130);
    glEnd();
    //tembok lt 1 samping kiri section 2
    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(25, -20, 130);
    glVertex3d(25, 30, 130);
    glVertex3d(25, 30, 75);
    glVertex3d(25, -20, 75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(25, 25, -45);
    glVertex3d(25, 30, -45);
    glVertex3d(25, 30, 130);
    glVertex3d(25, 25, 130);
    glEnd();
    //frame tembok lt 1 samping kiri section 2
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(25, 30, -45);
    glVertex3d(25, 30, 130);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(25, 25, -15);
    glVertex3d(25, 25, 75);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(25, 25, 75);
    glVertex3d(25, -20, 75);
    glEnd();
    //tembok sekat basement - lobby
    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(25, -20, 75);
    glVertex3d(25, 30, 75);
    glVertex3d(130, 30, 75);
    glVertex3d(130, -20, 75);
    glEnd();
    //frame
    //tembok sekat basement - lobby
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(25, 30, 75);
    glVertex3d(130, 30, 75);
    glEnd();

    //kaca lantai 1 (x+3, z+3)
    glBegin(GL_QUADS);
    glColor3ub(42, 47, 54);
    glVertex3d(50, -20, 233);
    glVertex3d(50, 20, 233);
    glVertex3d(128, 20, 233);
    glVertex3d(128, -20, 233);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(42, 47, 54);
    glVertex3d(50, -20, 233);
    glVertex3d(50, 20, 233);
    glVertex3d(50, 20, 230);
    glVertex3d(50, -20, 230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(42, 47, 54);
    glVertex3d(128, -20, 233);
    glVertex3d(128, 20, 233);
    glVertex3d(128, 20, 130);
    glVertex3d(128, -20, 130);
    glEnd();

    //slab kaca lantai1
    // kanan
    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(129, 20, 233);
    glVertex3d(125, 20, 233);
    glVertex3d(125, 20, 130);
    glVertex3d(129, 20, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(129, 20, 234);
    glVertex3d(129, 22, 234);
    glVertex3d(129, 22, 130);
    glVertex3d(129, 20, 130);
    glEnd();
    //frame code diatas
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3d(129, 20, 234);
    glVertex3d(129, 22, 234);
    glVertex3d(129, 22, 130);
    glVertex3d(129, 20, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(129, 22, 233);
    glVertex3d(125, 22, 233);
    glVertex3d(125, 22, 130);
    glVertex3d(129, 22, 130);
    glEnd();
    //segmen kaca samping
    for (i=130; i<230; i=i+12.5)
    {
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex3d(129, 20, i);
        glVertex3d(129, -20, i);
        glEnd();
    }
    //depan
    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(50, 20, 230);
    glVertex3d(50, 20, 234);
    glVertex3d(129, 20, 234);
    glVertex3d(129, 20, 230);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(50, 20, 234);
    glVertex3d(50, 22, 234);
    glVertex3d(129, 22, 234);
    glVertex3d(129, 20, 234);
    glEnd();
    //frame code diatas
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3d(50, 20, 234);
    glVertex3d(50, 22, 234);
    glVertex3d(129, 22, 234);
    glVertex3d(129, 20, 234);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(50, 22, 230);
    glVertex3d(50, 22, 234);
    glVertex3d(129, 22, 234);
    glVertex3d(129, 22, 230);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(50, 22, 230);
    glVertex3d(50, 20, 230);
    glVertex3d(50, 20, 234);
    glVertex3d(50, 22, 234);
    glEnd();
    //frame code diatas
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3d(50, 22, 230);
    glVertex3d(50, 20, 230);
    glVertex3d(50, 20, 234);
    glVertex3d(50, 22, 234);
    glEnd();
    for (i=50; i<= 128; i=i+12.5)
    {
        if(i==125)
            i=i+3;
        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex3f(i, 20, 234);
        glVertex3f(i, -20, 234);
        glEnd();

    }


    glPopMatrix();
    glutSwapBuffers();
    glFlush();
    //segmen kaca depan


}

void keyboard(unsigned char key, int x, int y) {

    switch (key){
        case 'w' :
        case 'W' :
        glTranslatef(0.0, 0.0, 3.0);
        break;
        case 'd' :
        case 'D' :
        glTranslatef(3.0, 0.0, 00);
        break;
        case 's' :
        case 'S' :
        glTranslatef(0.0, 0.0, -3.0);
        break;
        case 'a' :
        case 'A' :
        glTranslatef(-3.0, 0.0, 0.0);
        break;
        case 'q' :
        case 'Q' :
        glTranslatef(0.0, 3.0, 0.0);
        break;
        case 'e' :
        case 'E' :
        glTranslatef(0.0, -3.0, 0.0);
        break;
        case 'k' :
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
        case 'i' :
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
        case 'l' :
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
        case 'j' :
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
        case 'u' :
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
        case 'o' :
        glRotatef(-2.0, 1.0, 0.0, 1.0);
        break;
    }
    tampil();
}
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    } else {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi){

    if(tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -400.0);
    glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("3D");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutMainLoop();
    return 0;
}
