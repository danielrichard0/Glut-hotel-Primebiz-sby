#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>

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
    
    //////// Adit ////////
    
     //alas hotel
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3d(-40, -25, -90);
    glVertex3d(-40, -25, 370);
    glVertex3d(180, -25, 370);
    glVertex3d(180, -25, -90);
    glEnd();
    // tembok batas daerah hotel kiri

    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(-39, -25, 345);
    glVertex3d(-39, 30, 345);
    glVertex3d(-39, 30, -65);
    glVertex3d(-39, -25, -65);
    glEnd();

     glBegin(GL_QUADS); // line kuning
    glColor3f(245, 224, 0.0);
    glVertex3d(-39, -24, -65);
    glVertex3d(-39, -24, 370);
    glVertex3d(-36, -24, 370);
    glVertex3d(-36, -24, -65);
    glEnd();
     // tembok belakang
    glBegin(GL_QUADS);
    glColor3ub(177, 188, 186);
    glVertex3d(-40, -25, -65);
    glVertex3d(-40, 30, -65);
    glVertex3d(180, 30, -65);
    glVertex3d(180, -25, -65);
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
    
    // kotak depan hotel
    glBegin(GL_QUADS);
    glColor3ub(177, 188, 186);
    glVertex3d(30, -25, 345);
    glVertex3d(30, -10, 345);
    glVertex3d(112, -10, 345);
    glVertex3d(112, -25, 345);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(177, 188, 186);
    glVertex3d(30, -25, 340);
    glVertex3d(30, -10, 340);
    glVertex3d(112, -10, 340);
    glVertex3d(112, -25, 340);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(177, 188, 186);
    glVertex3d(30, -25, 345);
    glVertex3d(30, -10, 345);
    glVertex3d(30, -10, 340);
    glVertex3d(30, -25, 340);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177, 188, 186);
    glVertex3d(112, -25, 345);
    glVertex3d(112, -10, 345);
    glVertex3d(112, -10, 340);
    glVertex3d(112, -25, 340);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(30, -10, 340);
    glVertex3d(30, -10, 345);
    glVertex3d(112, -10, 345);
    glVertex3d(112, -10, 340);
    glEnd();
    // garis parkir
    glBegin(GL_QUADS);// 1
    glColor3f(245, 224, 0.0);
    glVertex3d(25, -24, 305);
    glVertex3d(30, -24, 340);
    glVertex3d(32, -24, 340);
    glVertex3d(27, -24, 305);
    glEnd();
     glBegin(GL_QUADS);// 2
    glColor3f(245, 224, 0.0);
    glVertex3d(45, -24, 305);
    glVertex3d(50, -24, 340);
    glVertex3d(52, -24, 340);
    glVertex3d(47, -24, 305);
    glEnd();

    glBegin(GL_QUADS);// 3
    glColor3f(245, 224, 0.0);
    glVertex3d(65, -24, 305);
    glVertex3d(70, -24, 340);
    glVertex3d(72, -24, 340);
    glVertex3d(67, -24, 305);
    glEnd();
    glBegin(GL_QUADS);// 4
    glColor3f(245, 224, 0.0);
    glVertex3d(85, -24, 305);
    glVertex3d(90, -24, 340);
    glVertex3d(92, -24, 340);
    glVertex3d(87, -24, 305);
    glEnd();
    glBegin(GL_QUADS);// 5
    glColor3f(245, 224, 0.0);
    glVertex3d(105, -24, 305);
    glVertex3d(110, -24, 340);
    glVertex3d(112, -24, 340);
    glVertex3d(107, -24, 305);
    glEnd();
     glBegin(GL_QUADS); // line kuning
    glColor3f(245, 224, 0.0);
    glVertex3d(29, -24, 345);
    glVertex3d(29, -24, 370);
    glVertex3d(30, -24, 370);
    glVertex3d(30, -24, 345);
    glEnd();
    glBegin(GL_QUADS); // line kuning
    glColor3f(245, 224, 0.0);
    glVertex3d(112, -24, 345);
    glVertex3d(112, -24, 370);
    glVertex3d(113, -24, 370);
    glVertex3d(113, -24, 345);
    glEnd();
    
    ///// Daniel ///// 
   
    //alas hotel
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3d(0, -25, -65);
    glVertex3d(0, -25, 300);
    glVertex3d(150, -25, 300);
    glVertex3d(150, -25, -65);
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
    //ornamen bagian depan //ornamen bagian depan //ornamen bagian depan
    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(20, -20, 235);
    glVertex3d(20, 35, 235);
    glVertex3d(25, 35, 235);
    glVertex3d(25, -20, 235);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(25, 30, 235);
    glVertex3d(25, 35, 235);
    glVertex3d(125, 35, 235);
    glVertex3d(125, 30, 235);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(20, 35, 235);
    glVertex3d(20, 35, 230);
    glVertex3d(125, 35, 230);
    glVertex3d(125, 35, 235);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(20, 30, 235);
    glVertex3d(20, 30, 230);
    glVertex3d(125, 30, 230);
    glVertex3d(125, 30, 235);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(20, -20, 235);
    glVertex3d(20, -20, 230);
    glVertex3d(20, 35, 230);
    glVertex3d(20, 35, 235);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 254, 255);
    glVertex3d(125, 30, 235);
    glVertex3d(125, 30, 230);
    glVertex3d(125, 35, 230);
    glVertex3d(125, 35, 235);
    glEnd();
    //frame ornamen
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(20, 35, 235);
    glVertex3d(20, -20, 235);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(25, 30, 235);
    glVertex3d(25, -20, 235);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(20, 35, 235);
    glVertex3d(125, 35, 235);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(25, 30, 235);
    glVertex3d(125, 30, 235);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(125, 30, 235);
    glVertex3d(125, 30, 230);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(125, 35, 235);
    glVertex3d(125, 35, 230);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(125, 35, 235);
    glVertex3d(125, 30, 235);
    glEnd();
    //atap kaca depan gedung
    glBegin(GL_QUADS);
    glColor3ub(166, 175, 191);
    glVertex3d(80, 28, 250);
    glVertex3d(80, 28, 230);
    glVertex3d(145, 28, 230);
    glVertex3d(145, 28, 250);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(80, 25, 250);
    glVertex3d(80, 25, 230);
    glVertex3d(145, 25, 230);
    glVertex3d(145, 25, 250);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(125.1, 25, 230);
    glVertex3f(125.1, 25, 130);
    glVertex3d(145, 25, 130);
    glVertex3d(145, 25, 230);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(125.1, 28, 230);
    glVertex3f(125.1, 28, 130);
    glVertex3d(145, 28, 130);
    glVertex3d(145, 28, 230);
    glEnd();
    //segmen 2
    glBegin(GL_QUADS);
    glVertex3d(130, 28, 65);
    glVertex3d(130, 28, 130);
    glVertex3d(145, 28, 130);
    glVertex3d(145, 28, 65);
    glEnd();
    //tutup samping
    glBegin(GL_QUADS);
    glVertex3d(130, 25, 65);
    glVertex3d(130, 25, 130);
    glVertex3d(145, 25, 130);
    glVertex3d(145, 25, 65);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(145, 25, 65);
    glVertex3d(145, 25, 250);
    glVertex3d(145, 28, 250);
    glVertex3d(145, 28, 65);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(80, 25, 250);
    glVertex3d(80, 28, 250);
    glVertex3d(145, 28, 250);
    glVertex3d(145, 25, 250);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(80, 25, 230);
    glVertex3d(80, 28, 230);
    glVertex3d(80, 28, 250);
    glVertex3d(80, 25, 250);
    glEnd();
    //frame ornamen atap kaca
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex3d(80, 28, 250);
    glVertex3d(145, 28, 250);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(80, 25, 250);
    glVertex3d(145, 25, 250);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(80, 25, 250);
    glVertex3d(80, 28, 250);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(80, 25, 230);
    glVertex3d(80, 25, 250);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(80, 28, 230);
    glVertex3d(80, 28, 250);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(145, 28, 65);
    glVertex3d(145, 28, 250);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(145, 25, 65);
    glVertex3d(145, 25, 250);
    glEnd();
    //tiang atap kaca samping

    for(j=250; j>= 65; j=j-20)
    {
        glBegin(GL_QUADS);
        glColor3ub(90, 99, 115);
        glVertex3d(140, 25, j);
        glVertex3d(140, -20, j);
        glVertex3d(142, -20, j);
        glVertex3d(142, 25, j);
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(140, 25, j-2);
        glVertex3d(140, -20, j-2);
        glVertex3d(140, -20, j);
        glVertex3d(140, 25, j);
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(142, 25, j-2);
        glVertex3d(142, -20, j-2);
        glVertex3d(142, -20, j);
        glVertex3d(142, 25, j);
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(142, 25, j-2);
        glVertex3d(142, -20, j-2);
        glVertex3d(142, -20, j-2);
        glVertex3d(142, 25, j-2);
        glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glVertex3d(142, 25, j);
        glVertex3d(142, -20, j);
        glEnd();
        glBegin(GL_LINES);
        glVertex3d(140, 25, j);
        glVertex3d(140, -20, j);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glVertex3d(142, 25, j-2);
        glVertex3d(142, -20, j-2);
        glEnd();
        glBegin(GL_LINES);
        glVertex3d(140, 25, j-2);
        glVertex3d(140, -20, j-2);
        glEnd();
    glEnd();
    }



    //tembok samping
    glBegin(GL_LINES);
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
    //pager tembok basement kanan
    //panjang
    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(130, -20, -45);
    glVertex3d(130, -10, -45);
    glVertex3d(130, -10, 40);
    glVertex3d(130, -20, 40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(127, -20, -42);
    glVertex3d(127, -10, -42);
    glVertex3d(127, -10, 40);
    glVertex3d(127, -20, 40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(127, -10, -42);
    glVertex3d(127, -10, 40);
    glVertex3d(130, -10, 40);
    glVertex3d(130, -10, -42);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(127, -10, 40);
    glVertex3d(127, -20, 40);
    glVertex3d(130, -20, 40);
    glVertex3d(130, -10, 40);
    glEnd();

    //frame
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3d(127, -10, 40);
    glVertex3d(127, -20, 40);
    glVertex3d(130, -20, 40);
    glVertex3d(130, -10, 40);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3d(130, -10, 40);
    glVertex3d(130, -10, -45);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(127, -10, 40);
    glVertex3d(127, -10, -42);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(127, -10, -42);
    glVertex3d(115, -10, -42);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(130, -10, -45);
    glVertex3d(115, -10, -45);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(130, -10, -45);
    glVertex3d(130, -20, -45);
    glEnd();
    //pendek
    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(130, -20, -45);
    glVertex3d(130, -10, -45);
    glVertex3d(115, -10, -45);
    glVertex3d(115, -20, -45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(127, -20, -42);
    glVertex3d(127, -10, -42);
    glVertex3d(115, -10, -42);
    glVertex3d(115, -20, -42);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 250, 255);
    glVertex3d(130, -10, -45);
    glVertex3d(130, -10, -42);
    glVertex3d(115, -10, -42);
    glVertex3d(115, -10, -45);
    glEnd();

    //pillar bagian basement 1//dari kanan

    for (i=120, j= 115; j>15 && i>10; i=i-20,j=j-20)
    {
        if(j==75.0 && i==80.0)
        {
            i=i-20.0;j=j-20.0;
        }
        glBegin(GL_QUADS);
        glColor3ub(230, 250, 255);
        glVertex3d(j, -20, 25);
        glVertex3d(j, -20, 30);
        glVertex3d(j, 30, 30);
        glVertex3d(j, 30, 25);
        glEnd();
        glBegin(GL_QUADS);
        glColor3ub(230, 250, 255);
        glVertex3d(j, -20, 30);
        glVertex3d(i, -20, 30);
        glVertex3d(i, 30, 30);
        glVertex3d(j, 30, 30);
        glEnd();
        glBegin(GL_QUADS);
        glColor3ub(230, 250, 255);
        glVertex3d(j, -20, 25);
        glVertex3d(i, -20, 25);
        glVertex3d(i, 30, 25);
        glVertex3d(j, 30, 25);
        glEnd();
        glBegin(GL_QUADS);
        glColor3ub(230, 250, 255);
        glVertex3d(i, -20, 25);
        glVertex3d(i, -20, 30);
        glVertex3d(i, 30, 30);
        glVertex3d(i, 30, 25);
        glEnd();
        //frame
        glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex3d(j, -20, 30);
        glVertex3d(j, 30, 30);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex3d(j, -20, 25);
        glVertex3d(j, 30, 25);
        glEnd();
        glColor3ub(0, 0, 0);
        glVertex3d(i, -20, 30);
        glVertex3d(i, 30, 30);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex3d(i, -20, 25);
        glVertex3d(i, 30, 25);
        glEnd();
        printf("pillar %f\n",j);


    }
    //pondasi hotel//depan
    glBegin(GL_QUADS);
    glColor3ub(200, 218, 227);
    glVertex3d(20, -20, 250);
    glVertex3d(20, -20, 230);
    glVertex3d(145, -20, 230);
    glVertex3d(145, -20, 250);
    glEnd();
    //depan1
    glBegin(GL_QUADS);
    glVertex3d(20, -20, 250);
    glVertex3d(20, -25, 250);
    glVertex3d(145, -25, 250);
    glVertex3d(145, -20, 250);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(20, -20, 230);
    glVertex3d(20, -25, 230);
    glVertex3d(20, -25, 250);
    glVertex3d(20, -20, 250);
    glEnd();
    //frame depan
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3d(20, -20, 250);
    glVertex3d(145, -20, 250);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(20, -20, 250);
    glVertex3d(20, -20, 230);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(20, -20, 250);
    glVertex3d(20, -25, 250);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(145, -20, 250);
    glVertex3d(145, -25, 250);
    glEnd();
    //samping

    glBegin(GL_QUADS);
    glColor3ub(200, 218, 227);
    glVertex3d(125, -20, 250);
    glVertex3d(125, -20, 130);
    glVertex3d(145, -20, 130);
    glVertex3d(145, -20, 250);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(130, -20, 130);
    glVertex3d(130, -20, 68);
    glVertex3d(145, -20, 68);
    glVertex3d(145, -20, 130);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(145, -25, 250);
    glVertex3d(145, -25, 68);
    glVertex3d(145, -20, 68);
    glVertex3d(145, -20, 250);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(130, -20, 75);
    glVertex3d(130, -20, 68);
    glVertex3d(25, -20, 68);
    glVertex3d(25, -20, 75);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(130, -20, 68);
    glVertex3f(145, -20, 68);
    glVertex3f(145, -25, 68);
    glEnd();
    //frame
    glBegin(GL_LINES);
    glColor3b(0,0,0);
    glVertex3d(145, -20, 68);
    glVertex3d(145, -20, 250);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(145, -20, 68);
    glVertex3d(145, -25, 68);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(130, -20, 68);
    glVertex3d(145, -20, 68);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(130, -19.9, 68);
    glVertex3d(145, -24.9, 68);
    glEnd();
    //pondasi hotel samping
    glBegin(GL_QUADS);
    glColor3ub(200, 218, 227);
    glVertex3f(130, -20, 68);
    glVertex3f(130, -20, 40);
    glVertex3f(145, -25, 40);
    glVertex3f(145, -25, 68);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(130, -20, 40);
    glVertex3f(145, -20, 40);
    glVertex3f(145, -25, 40);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(130, -20, 42);
    glVertex3f(145, -20, 42);
    glVertex3f(145, -25, 42);

    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(145, -20, 40);
    glVertex3f(145, -20, -45);
    glVertex3f(145, -25, -45);
    glVertex3f(145, -25, 40);
    glEnd();


    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(143, -20, 38);
    glVertex3f(143, -20, -45);
    glVertex3f(143, -25, -45);
    glVertex3f(143, -25, 38);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(143, -20, 38);
    glVertex3f(143, -20, -45);
    glVertex3f(145, -20, -45);
    glVertex3f(145, -20, 38);
    glEnd();
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(143, -20, 38);
    glVertex3f(130, -20, 38);
    glVertex3f(130, -25, 38);
    glVertex3f(143, -25, 38);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(145, -20, 38);
    glVertex3f(130, -20, 38);
    glVertex3f(130, -20, 40);
    glVertex3f(145, -20, 40);
    glEnd();
    //hijau
    glBegin(GL_QUADS);
    glColor3ub(48, 122, 58);
    glVertex3f(145, -20, 38);
    glVertex3f(130, -20, 38);
    glVertex3f(130, -20, -45);
    glVertex3f(145, -20, -45);
    glEnd();
    //frame
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(145, -20, 40);
    glVertex3f(130, -20, 40);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(145, -20, -45);
    glVertex3f(145, -20, 40);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(130, -19.7, 40);
    glVertex3f(145, -24.7, 40);
    glEnd();
    //pondasi gedung belakang
    glBegin(GL_QUADS);
    glColor3ub(200, 218, 227);
    glVertex3f(145, -25, -45);
    glVertex3f(25, -25, -45);
    glVertex3f(25, -20, -45);
    glVertex3f(145, -20, -45);
    glEnd();
    //pondasi gedung samping
    glBegin(GL_QUADS);
    glColor3ub(200, 218, 227);
    glVertex3f(25, -25, -45);
    glVertex3f(25, -25, 130);
    glVertex3f(25, -20, 130);
    glVertex3f(25, -20, -45);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(200, 218, 227);
    glVertex3f(25, -25, 130);
    glVertex3f(20, -25, 130);
    glVertex3f(20, -20, 130);
    glVertex3f(25, -20, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(200, 218, 227);
    glVertex3f(20, -25, 130);
    glVertex3f(20, -25, 230);
    glVertex3f(20, -20, 230);
    glVertex3f(20, -20, 130);
    glEnd();
    //lantai basement
    glBegin(GL_QUADS);
    glColor3ub(200, 218, 227);
    glVertex3f(25, -20, -45);
    glVertex3f(25, -20, 70);
    glVertex3f(130, -20, 70);
    glVertex3f(130, -20, -45);
    glEnd();
    //lantai lobby
    glBegin(GL_POLYGON);
    glColor3ub(213, 235, 232);
    glVertex3f(20, -20, 230);
    glVertex3f(125, -20, 230);
    glVertex3f(125, -20, 130);
    glVertex3f(130, -20, 130);
    glVertex3f(130, -20, 75);
    glVertex3f(25, -20, 75);
    glVertex3f(20, -20, 75);
    glEnd();
    //pintu kanan
    glBegin(GL_QUADS);
    glColor3ub(97, 117, 115);
    glVertex3f(130.1, 0, 125);
    glVertex3f(130.1, 0, 115);
    glVertex3f(130.1, -20, 115);
    glVertex3f(130.1, -20, 125);
    glEnd();
    //frame pintu
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(130.1, 0, 125);
    glVertex3f(130.1, 0, 115);
    glVertex3f(130.1, -20, 115);
    glVertex3f(130.1, -20, 125);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 117, 115);
    glVertex3f(130.1, 0, 105);
    glVertex3f(130.1, 0, 95);
    glVertex3f(130.1, -20, 95);
    glVertex3f(130.1, -20, 105);
    glEnd();
    //frame pintu
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(130.1, 0, 105);
    glVertex3f(130.1, 0, 95);
    glVertex3f(130.1, -20, 95);
    glVertex3f(130.1, -20, 105);
    glEnd();

    //jendela kanan

    glBegin(GL_QUADS);
    glColor3ub(36, 41, 40);
    glVertex3f(130.1, 0, 90);
    glVertex3f(130.1, 0, 85);
    glVertex3f(130.1, -5, 85);
    glVertex3f(130.1, -5, 90);
    glEnd();
    //frame jendela1
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(130.1, 0, 90);
    glVertex3f(130.1, 0, 85);
    glVertex3f(130.1, -5, 85);
    glVertex3f(130.1, -5, 90);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(36, 41, 40);
    glVertex3f(130.1, 0, 85);
    glVertex3f(130.1, 0, 80);
    glVertex3f(130.1, -5, 80);
    glVertex3f(130.1, -5, 85);
    glEnd();
    //frame jendela1
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(130.1, 0, 85);
    glVertex3f(130.1, 0, 80);
    glVertex3f(130.1, -5, 80);
    glVertex3f(130.1, -5, 85);
    glEnd();

    //* 2ND FLOOR *// //* 2ND FLOOR *// //* 2ND FLOOR *// //* 2ND FLOOR *//
    //* 2ND FLOOR *// //* 2ND FLOOR *// //* 2ND FLOOR *// //* 2ND FLOOR *//
    //* 2ND FLOOR *// //* 2ND FLOOR *// //* 2ND FLOOR *// //* 2ND FLOOR *//

    //Frame Sisi Depan
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(125, 30, 230);//Sisi Kanan
    glVertex3d(125, 80, 230);
    glVertex3d(20, 80, 230);//Sisi kiri
    glVertex3d(20, 30, 230);
    glEnd();

    //Frame Sisi Kanan
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(125, 30, 230);
    glVertex3d(125, 80, 230);
    glVertex3d(125, 80, 130);
    glVertex3d(125, 30, 130);
    glEnd();
    //L1 (Lekukan)
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(125, 30, 130);
    glVertex3d(125, 80, 130);
    glVertex3d(130, 80, 130);
    glVertex3d(130, 30, 130);
    glEnd();
    //L2
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(130, 30, 130);
    glVertex3d(130, 80, 130);
    glVertex3d(130, 80, -45);
    glVertex3d(130, 30, -45);
    glEnd();

    //Frame Sisi Kiri
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(20, 30, 230);
    glVertex3d(20, 80, 230);
    glVertex3d(20, 80, 130);
    glVertex3d(20, 30, 130);
    glEnd();
    //L1 (Lekukan)
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(20, 30, 130);
    glVertex3d(20, 80, 130);
    glVertex3d(25, 80, 130);
    glVertex3d(25, 30, 130);
    glEnd();
    //L2
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(25, 30, 130);
    glVertex3d(25, 80, 130);
    glVertex3d(25, 80, -45);
    glVertex3d(25, 30, -45);
    glEnd();

    //Frame Sisi Belakang
    glBegin(GL_QUADS);
    glColor3ub(126, 143, 140);
    glVertex3d(25, 30, -45);
    glVertex3d(25, 80, -45);
    glVertex3d(130, 80, -45);
    glVertex3d(130, 30, -45);
    glEnd();

    //////// Lantai 3 /////////
    
    //alas hotel 
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.75, 0.75);
    glVertex3d(25, 80.1, -45);
    glVertex3d(130, 80.1, -45);
    glVertex3d(130, 80.1, 230);
    glVertex3d(25, 80.1, 230);
    glEnd();

    //atap hotel
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.75, 0.75);
    glVertex3d(25, 130.0, -45);
    glVertex3d(130, 130.0, -45);
    glVertex3d(130, 130.0, 230);
    glVertex3d(25, 130.0, 230);
    glEnd();

    // tembok depan
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3d(25, 80.1, -45);
    glVertex3d(130, 80.1, -45);
    glVertex3d(130, 130.0, -45);
    glVertex3d(25, 130.0, -45);
    glEnd();

    // tembok belakang
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3d(25, 80.1, 230);
    glVertex3d(130, 80.1, 230);
    glVertex3d(130, 130.0, 230);
    glVertex3d(25, 130.0, 230);
    glEnd();

    // tembok kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3d(25, 80.1, -45);
    glVertex3d(25, 80.1, 230);
    glVertex3d(25, 130.0, 230);
    glVertex3d(25, 130.0, -45);
    glEnd();

    //tembok kanan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3d(130, 80.1, -45);
    glVertex3d(130, 80.1, 230);
    glVertex3d(130, 130.0, 230);
    glVertex3d(130, 130.0, -45);
    glEnd();

    //luarbawah1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(75, 125.0, 230.1);
    glVertex3d(135, 125.0, 230.1);
    glVertex3d(135, 125.0, 235);
    glVertex3d(75, 125.0, 235);
    glEnd();

    //luaratas1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(75, 130.0, 230.1);
    glVertex3d(135, 130.0, 230.1);
    glVertex3d(135, 130.0, 235);
    glVertex3d(75, 130.0, 235);
    glEnd();

    //luarkiri1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(75, 125.0, 230.1);
    glVertex3d(75, 125.0, 235);
    glVertex3d(75, 130.0, 235);
    glVertex3d(75, 130.0, 230.1);
    glEnd();

    //luarkanan1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(135, 125.0, 230.1);
    glVertex3d(135, 125.0, 235);
    glVertex3d(135, 130.0, 235);
    glVertex3d(135, 130.0, 230.1);
    glEnd();

    //luardepan1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(75, 125.0, 235);
    glVertex3d(135, 125.0, 235);
    glVertex3d(135, 130.0, 235);
    glVertex3d(75, 130.0, 235);
    glEnd();

    //luardepangaris1
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(25, 125.0, 235);
    glVertex3d(135, 125.0, 235);
    glVertex3d(135, 130.0, 235);
    glVertex3d(25, 130.0, 235);
    glEnd();

    //luarkiri2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(75, 85.0, 230.1);
    glVertex3d(75, 85.0, 235);
    glVertex3d(75, 125.0, 235);
    glVertex3d(75, 125.0, 230.1);
    glEnd();

    //luarkanan2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(80, 85.0, 230.1);
    glVertex3d(80, 85.0, 235);
    glVertex3d(80, 125.0, 235);
    glVertex3d(80, 125.0, 230.1);
    glEnd();

    //luardepan2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(75, 85.0, 235);
    glVertex3d(80, 85.0, 235);
    glVertex3d(80, 125.0, 235);
    glVertex3d(75, 125.0, 235);
    glEnd();

    //luardepangaris2
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(75, 85.0, 235);
    glVertex3d(80, 85.0, 235);
    glVertex3d(80, 125.0, 235);
    glVertex3d(75, 125.0, 235);
    glEnd();

    //luarbawah3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(75, 80.1, 230.1);
    glVertex3d(135, 80.1, 230.1);
    glVertex3d(135, 80.1, 235);
    glVertex3d(75, 80.1, 235);
    glEnd();

    //luaratas3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(75, 85.0, 230.1);
    glVertex3d(135, 85.0, 230.1);
    glVertex3d(135, 85.0, 235);
    glVertex3d(75, 85.0, 235);
    glEnd();

    //luarkiri3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(75, 80.1, 230.1);
    glVertex3d(75, 80.1, 235);
    glVertex3d(75, 85.0, 235);
    glVertex3d(75, 85.0, 230.1);
    glEnd();

    //luarkanan3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(135, 80.1, 230.1);
    glVertex3d(135, 80.1, 235);
    glVertex3d(135, 85.0, 235);
    glVertex3d(135, 85.0, 230.1);
    glEnd();

    //luardepan3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(75, 80.1, 235);
    glVertex3d(135, 80.1, 235);
    glVertex3d(135, 85.0, 235);
    glVertex3d(75, 85.0, 235);
    glEnd();

    //luardepangaris3
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(75, 80.1, 235);
    glVertex3d(135, 80.1, 235);
    glVertex3d(135, 85.0, 235);
    glVertex3d(75, 85.0, 235);
    glEnd();

    //luarbawah4
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(130, 125.0, 230.1);
    glVertex3d(135, 125.0, 230.1);
    glVertex3d(135, 125.0, 130);
    glVertex3d(130, 125.0, 130);
    glEnd();

    //luaratap4
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(130, 130.0, 230.1);
    glVertex3d(135, 130.0, 230.1);
    glVertex3d(135, 130.0, 130);
    glVertex3d(130, 130.0, 130);
    glEnd();

    //luarkanan4
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(135, 125.0, 230.1);
    glVertex3d(135, 125.0, 130);
    glVertex3d(135, 130.0, 130);
    glVertex3d(135, 130.0, 230.1);
    glEnd();

    //luarkanangaris4
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(135, 125.0, 235);
    glVertex3d(135, 125.0, 130);
    glVertex3d(135, 130.0, 130);
    glVertex3d(135, 130.0, 235);
    glEnd();

    //luarbelakang4
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(130, 125.0, 130);
    glVertex3d(135, 125.0, 130);
    glVertex3d(135, 130.0, 130);
    glVertex3d(130, 130.0, 130);
    glEnd();

    //luarbawah5
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(130, 80.1, 230.1);
    glVertex3d(135, 80.1, 230.1);
    glVertex3d(135, 80.1, 130);
    glVertex3d(130, 80.1, 130);
    glEnd();

    //luaratap5
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(130, 85.0, 230.1);
    glVertex3d(135, 85.0, 230.1);
    glVertex3d(135, 85.0, 130);
    glVertex3d(130, 85.0, 130);
    glEnd();

    //luarkanan5
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(135, 80.1, 230.1);
    glVertex3d(135, 80.1, 130);
    glVertex3d(135, 85.0, 130);
    glVertex3d(135, 85.0, 230.1);
    glEnd();

    //luarkanangaris5
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(135, 80.1, 235);
    glVertex3d(135, 80.1, 130);
    glVertex3d(135, 85.0, 130);
    glVertex3d(135, 85.0, 235);
    glEnd();

    //luarbelakang5
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(130, 80.1, 130);
    glVertex3d(135, 80.1, 130);
    glVertex3d(135, 85.0, 130);
    glVertex3d(130, 85.0, 130);
    glEnd();

    //luardepan6
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(130, 85.0, 135);
    glVertex3d(135, 85.0, 135);
    glVertex3d(135, 125.0, 135);
    glVertex3d(130, 125.0, 135);
    glEnd();

    //luarbelakang6
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(130, 85.0, 130);
    glVertex3d(135, 85.0, 130);
    glVertex3d(135, 125.0, 130);
    glVertex3d(130, 125.0, 130);
    glEnd();

    //luarkanan6
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(135, 85.0, 135);
    glVertex3d(135, 85.0, 130);
    glVertex3d(135, 125.0, 130);
    glVertex3d(135, 125.0, 135);
    glEnd();

    //luarkanangaris6
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(135, 85.0, 135);
    glVertex3d(135, 85.0, 130);
    glVertex3d(135, 125.0, 130);
    glVertex3d(135, 125.0, 135);
    glEnd();

    //kacabesar1
    glBegin(GL_QUADS);
    glColor3ub(104, 105, 104);
    glVertex3d(80.1, 90.0, 230.1);
    glVertex3d(130, 90.0, 230.1);
    glVertex3d(130, 120.0, 230.1);
    glVertex3d(80.1, 120.0, 230.1);
    glEnd();

    //kacabesar2
    glBegin(GL_QUADS);
    glColor3ub(104, 105, 104);
    glVertex3d(130.1, 90.0, 135.0);
    glVertex3d(130.1, 90.0, 230.1);
    glVertex3d(130.1, 120.0, 230.1);
    glVertex3d(130.1, 120.0, 135.0);
    glEnd();

    //kacabesargaris1
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(80.1, 90.0, 230.2);
    glVertex3d(130, 90.0, 230.2);
    glVertex3d(130, 120.0, 230.2);
    glVertex3d(80.1, 120.0, 230.2);
    glEnd();

    //kacabesargaris2
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(130.2, 90.0, 135.0);
    glVertex3d(130.2, 90.0, 230.1);
    glVertex3d(130.2, 120.0, 230.1);
    glVertex3d(130.2, 120.0, 135.0);
    glEnd();

    //kacalubang
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(130.2, 95.0, 150.0);
    glVertex3d(130.2, 95.0, 230.1);
    glVertex3d(130.2, 115.0, 230.1);
    glVertex3d(130.2, 115.0, 150.0);
    glEnd();

    //kacalubanggaris1
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(130.2, 95.0, 150.0);
    glVertex3d(130.2, 95.0, 230.1);
    glVertex3d(130.2, 115.0, 230.1);
    glVertex3d(130.2, 115.0, 150.0);
    glEnd();

    //kacalubanggaris2
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(130.2, 95.0, 210.0);
    glVertex3d(130.2, 115.0, 210.0);
    glEnd();

    //kacalubanggaris3
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(130.2, 95.0, 170.0);
    glVertex3d(130.2, 115.0, 170.0);
    glEnd();

    //luarbawah7
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(25, 125.0, 230.1);
    glVertex3d(75, 125.0, 230.1);
    glVertex3d(75, 125.0, 235);
    glVertex3d(25, 125.0, 235);
    glEnd();

    //luaratas7
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(25, 130.0, 230.1);
    glVertex3d(75, 130.0, 230.1);
    glVertex3d(75, 130.0, 235);
    glVertex3d(25, 130.0, 235);
    glEnd();

    //luarkiri7
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(25, 125.0, 230.1);
    glVertex3d(25, 125.0, 235);
    glVertex3d(25, 130.0, 235);
    glVertex3d(25, 130.0, 230.1);
    glEnd();

    //luardepan7
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(25, 125.0, 235);
    glVertex3d(75, 125.0, 235);
    glVertex3d(75, 130.0, 235);
    glVertex3d(25, 130.0, 235);
    glEnd();

    //luargaris1
    glBegin(GL_LINE_LOOP);
    glColor3ub(196, 196, 196);
    glVertex3d(35, 80.0, 230.1);
    glVertex3d(35, 125.0, 230.1);
    glEnd();

    //luargaris2
    glBegin(GL_LINE_LOOP);
    glColor3ub(196, 196, 196);
    glVertex3d(50, 80.0, 230.1);
    glVertex3d(50, 125.0, 230.1);
    glEnd();

    //luargaris3
    glBegin(GL_LINE_LOOP);
    glColor3ub(196, 196, 196);
    glVertex3d(65, 80.0, 230.1);
    glVertex3d(65, 125.0, 230.1);
    glEnd();

    //luargaris4
    glBegin(GL_LINE_LOOP);
    glColor3ub(196, 196, 196);
    glVertex3d(25, 95.0, 230.1);
    glVertex3d(75, 95.0, 230.1);
    glEnd();

     //luargaris5
    glBegin(GL_LINE_LOOP);
    glColor3ub(196, 196, 196);
    glVertex3d(25, 110.0, 230.1);
    glVertex3d(75, 110.0, 230.1);
    glEnd();

    //luarbawah8
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3d(130, 80.1, 130.1);
    glVertex3d(133, 80.1, 130.1);
    glVertex3d(133, 80.1, -45);
    glVertex3d(130, 80.1, -45);
    glEnd();

    //luaratap8
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3d(130, 130.0, 130.1);
    glVertex3d(133, 130.0, 130.1);
    glVertex3d(133, 130.0, -45);
    glVertex3d(130, 130.0, -45);
    glEnd();

    //luarkanan8
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3d(133, 80.1, 130.1);
    glVertex3d(133, 80.1, -45);
    glVertex3d(133, 130.0, -45);
    glVertex3d(133, 130.0, 130.1);
    glEnd();

    //luarbelakang8
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3d(130, 80.1, -45);
    glVertex3d(133, 80.1, -45);
    glVertex3d(133, 130.0, -45);
    glVertex3d(130, 130.0, -45);
    glEnd();

    //luarkanan9
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(133.1, 125.0, 120);
    glVertex3d(133.1, 125.0, -50);
    glVertex3d(133.1, 130.0, -50);
    glVertex3d(133.1, 130.0, 120);
    glEnd();

    //luarkanangaris9
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(133.1, 125.0, 120);
    glVertex3d(133.1, 125.0, -50);
    glVertex3d(133.1, 130.0, -50);
    glVertex3d(133.1, 130.0, 120);
    glEnd();

    //jendelakanan1
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(133.1, 95.0, 115);
    glVertex3d(133.1, 95.0, 105);
    glVertex3d(133.1, 115.0, 105);
    glVertex3d(133.1, 115.0, 115);
    glEnd();

    //jendelakanangaris1
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(133.2, 95.0, 115);
    glVertex3d(133.2, 95.0, 105);
    glVertex3d(133.2, 115.0, 105);
    glVertex3d(133.2, 115.0, 115);
    glEnd();

    //jendelakanan2
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(133.1, 95.0, 95);
    glVertex3d(133.1, 95.0, 85);
    glVertex3d(133.1, 115.0, 85);
    glVertex3d(133.1, 115.0, 95);
    glEnd();

    //jendelakanangaris2
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(133.2, 95.0, 95);
    glVertex3d(133.2, 95.0, 85);
    glVertex3d(133.2, 115.0, 85);
    glVertex3d(133.2, 115.0, 95);
    glEnd();

    //jendelakanan3
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(133.1, 95.0, 75);
    glVertex3d(133.1, 95.0, 65);
    glVertex3d(133.1, 115.0, 65);
    glVertex3d(133.1, 115.0, 75);
    glEnd();

    //jendelakanangaris3
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(133.2, 95.0, 75);
    glVertex3d(133.2, 95.0, 65);
    glVertex3d(133.2, 115.0, 65);
    glVertex3d(133.2, 115.0, 75);
    glEnd();

    //jendelakanan4
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(133.1, 95.0, 55);
    glVertex3d(133.1, 95.0, 45);
    glVertex3d(133.1, 115.0, 45);
    glVertex3d(133.1, 115.0, 55);
    glEnd();

    //jendelakanangaris4
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(133.2, 95.0, 55);
    glVertex3d(133.2, 95.0, 45);
    glVertex3d(133.2, 115.0, 45);
    glVertex3d(133.2, 115.0, 55);
    glEnd();

    //jendelakanan5
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(133.1, 95.0, 35);
    glVertex3d(133.1, 95.0, 25);
    glVertex3d(133.1, 115.0, 25);
    glVertex3d(133.1, 115.0, 35);
    glEnd();

    //jendelakanangaris5
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(133.2, 95.0, 35);
    glVertex3d(133.2, 95.0, 25);
    glVertex3d(133.2, 115.0, 25);
    glVertex3d(133.2, 115.0, 35);
    glEnd();

    //jendelakanan6
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(133.1, 95.0, 15);
    glVertex3d(133.1, 95.0, 5);
    glVertex3d(133.1, 115.0, 5);
    glVertex3d(133.1, 115.0, 15);
    glEnd();

    //jendelakanangaris6
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(133.2, 95.0, 15);
    glVertex3d(133.2, 95.0, 5);
    glVertex3d(133.2, 115.0, 5);
    glVertex3d(133.2, 115.0, 15);
    glEnd();

    //jendelakanan7
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(133.1, 95.0, -5);
    glVertex3d(133.1, 95.0, -15);
    glVertex3d(133.1, 115.0, -15);
    glVertex3d(133.1, 115.0, -5);
    glEnd();

    //jendelakanangaris7
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(133.2, 95.0, -5);
    glVertex3d(133.2, 95.0, -15);
    glVertex3d(133.2, 115.0, -15);
    glVertex3d(133.2, 115.0, -5);
    glEnd();

    //luarbawah10
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(20, 125.0, -45.1);
    glVertex3d(133.1, 125.0, -45.1);
    glVertex3d(133.1, 125.0, -50);
    glVertex3d(20, 125.0, -50);
    glEnd();

    //luaratas10
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(20, 130.0, -45.1);
    glVertex3d(133.1, 130.0, -45.1);
    glVertex3d(133.1, 130.0, -50);
    glVertex3d(20, 130.0, -50);
    glEnd();

    //luarkiri10
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(20, 125.0, -45.1);
    glVertex3d(20, 125.0, -50);
    glVertex3d(20, 130.0, -50);
    glVertex3d(20, 130.0, -45.1);
    glEnd();

    //luarbelakang10
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(20, 125.0, -50);
    glVertex3d(133.1, 125.0, -50);
    glVertex3d(133.1, 130.0, -50);
    glVertex3d(20, 130.0, -50);
    glEnd();

    //luarbelakanggaris10
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(20, 125.0, -50);
    glVertex3d(133.1, 125.0, -50);
    glVertex3d(133.1, 130.0, -50);
    glVertex3d(20, 130.0, -50);
    glEnd();

    //luardepan10
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(20, 125.0, -45.1);
    glVertex3d(133.1, 125.0, -45.1);
    glVertex3d(133.1, 130.0, -45.1);
    glVertex3d(20, 130.0, -45.1);
    glEnd();

    //luarbawah11
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(20, 125.0, -45.1);
    glVertex3d(25, 125.0, -45.1);
    glVertex3d(25, 125.0, 150);
    glVertex3d(20, 125.0, 150);
    glEnd();

   //luaratas11
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(20, 130.0, -45.1);
    glVertex3d(25, 130.0, -45.1);
    glVertex3d(25, 130.0, 150);
    glVertex3d(20, 130.0, 150);
    glEnd();

    //luarkiri11
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(20, 125.0, -45.1);
    glVertex3d(20, 125.0, 150);
    glVertex3d(20, 130.0, 150);
    glVertex3d(20, 130.0, -45.1);
    glEnd();

    //luarkirigaris11
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(20, 125.0, -50);
    glVertex3d(20, 125.0, 150);
    glVertex3d(20, 130.0, 150);
    glVertex3d(20, 130.0, -50);
    glEnd();

    //luardepan11
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(20, 125.0, 150);
    glVertex3d(25, 125.0, 150);
    glVertex3d(25, 130.0, 150);
    glVertex3d(20, 130.0, 150);
    glEnd();

    //luardepangaris11
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(20, 125.0, 150);
    glVertex3d(25, 125.0, 150);
    glVertex3d(25, 130.0, 150);
    glVertex3d(20, 130.0, 150);
    glEnd();

    //luarkiri11(tembok)
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3d(24.9, 80.0, -45.1);
    glVertex3d(24.9, 80.0, 150);
    glVertex3d(24.9, 125.0, 150);
    glVertex3d(24.9, 125.0, -45.1);
    glEnd();

    //luarkiri12
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3d(24.9, 125.0, 150.1);
    glVertex3d(24.9, 125.0, 235);
    glVertex3d(24.9, 130.0, 235);
    glVertex3d(24.9, 130.0, 150.1);
    glEnd();

    //luarkirigaris12
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(24.9, 125.0, 150.1);
    glVertex3d(24.9, 125.0, 235);
    glVertex3d(24.9, 130.0, 235);
    glVertex3d(24.9, 130.0, 150.1);
    glEnd();

    //jendelabelakang1
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3d(75, 95.0, -45.1);
    glVertex3d(85, 95.0, -45.1);
    glVertex3d(85, 115.0, -45.1);
    glVertex3d(75, 115.0, -45.1);
    glEnd();

    //jendelabelakanggaris1
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(75, 95.0, -45.2);
    glVertex3d(85, 95.0, -45.2);
    glVertex3d(85, 115.0, -45.2);
    glVertex3d(75, 115.0, -45.2);
    glEnd();

    //jendelakiri1
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(24.9, 95.0, 170);
    glVertex3d(24.9, 95.0, 180);
    glVertex3d(24.9, 115.0, 180);
    glVertex3d(24.9, 115.0, 170);
    glEnd();

    //jendelakirigaris1
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(24.8, 95.0, 170);
    glVertex3d(24.8, 95.0, 180);
    glVertex3d(24.8, 115.0, 180);
    glVertex3d(24.8, 115.0, 170);
    glEnd();

    //jendelakiri2
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(24.9, 95.0, 190);
    glVertex3d(24.9, 95.0, 200);
    glVertex3d(24.9, 115.0, 200);
    glVertex3d(24.9, 115.0, 190);
    glEnd();

    //jendelakirigaris2
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(24.8, 95.0, 190);
    glVertex3d(24.8, 95.0, 200);
    glVertex3d(24.8, 115.0, 200);
    glVertex3d(24.8, 115.0, 190);
    glEnd();

    //jendelakiri3
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(24.8, 95.0, -10);
    glVertex3d(24.8, 95.0, 0);
    glVertex3d(24.8, 115.0, 0);
    glVertex3d(24.8, 115.0, -10);
    glEnd();

    //jendelakirigaris3
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(24.7, 95.0, -10);
    glVertex3d(24.7, 95.0, 0);
    glVertex3d(24.7, 115.0, 0);
    glVertex3d(24.7, 115.0, -10);
    glEnd();

    //jendelakiri4
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(24.8, 95.0, 20);
    glVertex3d(24.8, 95.0, 30);
    glVertex3d(24.8, 115.0, 30);
    glVertex3d(24.8, 115.0, 20);
    glEnd();

    //jendelakirigaris4
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(24.7, 95.0, 20);
    glVertex3d(24.7, 95.0, 30);
    glVertex3d(24.7, 115.0, 30);
    glVertex3d(24.7, 115.0, 20);
    glEnd();

    //jendelakiri5
    glBegin(GL_QUADS);
    glColor3ub(212, 214, 213);
    glVertex3d(24.8, 110.0, 80);
    glVertex3d(24.8, 110.0, 100);
    glVertex3d(24.8, 115.0, 100);
    glVertex3d(24.8, 115.0, 80);
    glEnd();

    //jendelakirigaris5
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3d(24.8, 110.0, 80);
    glVertex3d(24.8, 110.0, 100);
    glVertex3d(24.8, 115.0, 100);
    glVertex3d(24.8, 115.0, 80);
    glEnd(); 

    glPopMatrix();
    glutSwapBuffers();
    glFlush();
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
  
