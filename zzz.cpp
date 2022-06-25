#include <windows.h>
#include <GL/glut.h>

// 672019032 - ALEXANDER BAGUS KRISTIAWAN
// 672019109 - BUYUNG HERFANDY MAAY
// 672019208 - ANASTASIA KEZIA BEATRIX MAYESTIKA
// 672019277 - DISMAS NIGEL ABYASA

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void Init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
}

void Display(void) {
    int i, j;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    //Alas Besar
    glBegin(GL_QUADS);
    glColor3ub(50, 205, 50);
    glVertex3i(-120, 0, 120);
    glVertex3i(120, 0, 120);
    glVertex3i(120, 0, -120);
    glVertex3i(-120, 0, -120);
    glEnd();

    //Alas
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-12, 0.1, 12);
    glVertex3f(12, 0.1, 12);
    glVertex3f(12, 0.1, -12);
    glVertex3f(-12, 0.1, -12);
    glEnd();

    //Atap 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-12, 40, 12);
    glVertex3i(12, 40, 12);
    glVertex3i(12, 40, -12);
    glVertex3i(-12, 40, -12);
    glEnd();

    //Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(12, 40, -12);
    glVertex3i(12, 40, 12);
    glVertex3i(12, 0, 12);
    glVertex3i(12, 0, -12);
    glEnd();
    //Jendela 1
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(0, 0, -1.5 * j); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(0, -4 * i, -1);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(12.1, 37, 10);
            glVertex3f(12.1, 37, 9);
            glVertex3f(12.1, 34, 9);
            glVertex3f(12.1, 34, 10);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(0, 0, -1.5 * j); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -4 * i, -1); //Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(12.1, 37, 10);
            glVertex3f(12.1, 37, 9);
            glVertex3f(12.1, 34, 9);
            glVertex3f(12.1, 34, 10);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(12.1, 37, 9.5);
            glVertex3f(12.1, 34, 9.5);
            glVertex3f(12.1, 36, 9);
            glVertex3f(12.1, 36, 10);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-12, 40, -12);
    glVertex3i(12, 40, -12);
    glVertex3i(12, 0, -12);
    glVertex3i(-12, 0, -12);
    glEnd();
    //Jendela 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(-1, -4 * i, 0); //Vertical
            glBegin(GL_POLYGON);
            glVertex3f(10, 37, -12.1);
            glVertex3f(9, 37, -12.1);
            glVertex3f(9, 34, -12.1);
            glVertex3f(10, 34, -12.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(-1, -4 * i, 0); //Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(10, 37, -12.1);
            glVertex3f(9, 37, -12.1);
            glVertex3f(9, 34, -12.1);
            glVertex3f(10, 34, -12.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(9.5, 37, -12.1);
            glVertex3f(9.5, 34, -12.1);
            glVertex3f(10, 36, -12.1);
            glVertex3f(9, 36, -12.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(12, 40, 12);
    glVertex3i(-12, 40, 12);
    glVertex3i(-12, 0, 12);
    glVertex3i(12, 0, 12);
    glEnd();
    //Jendela 3
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(18, -4 * i, 0); //Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-10, 37, 12.1);
            glVertex3f(-9, 37, 12.1);
            glVertex3f(-9, 34, 12.1);
            glVertex3f(-10, 34, 12.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(18, -4 * i, 0); //Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-10, 37, 12.1);
            glVertex3f(-9, 37, 12.1);
            glVertex3f(-9, 34, 12.1);
            glVertex3f(-10, 34, 12.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-9.5, 37, 12.1);
            glVertex3f(-9.5, 34, 12.1);
            glVertex3f(-10, 36, 12.1);
            glVertex3f(-9, 36, 12.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-12, 40, 12);
    glVertex3i(-12, 40, -12);
    glVertex3i(-12, 0, -12);
    glVertex3i(-12, 0, 12);
    glEnd();
    //Jendela 4
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-18, 0, -1.5 * j); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(18, -4 * i, 18); //Vertical
            glBegin(GL_POLYGON);
            glVertex3f( -12.1, 37, -10);
            glVertex3f(-12.1, 37, -9);
            glVertex3f(-12.1, 34, -9);
            glVertex3f(-12.1, 34, -10);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-18, 0, -1.5 * j); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(18, -4 * i, 18); //Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-12.1, 37, -10);
            glVertex3f(-12.1, 37, -9);
            glVertex3f(-12.1, 34, -9);
            glVertex3f(-12.1, 34, -10);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-12.1, 37, -9.5);
            glVertex3f(-12.1, 34, -9.5);
            glVertex3f(-12.1, 36, -10);
            glVertex3f(-12.1, 36, -9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Atap 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-8, 60, 8);
    glVertex3i(8, 60, 8);
    glVertex3i(8, 60, -8);
    glVertex3i(-8, 60, -8);
    glEnd();
    //Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-8, 60, -8);
    glVertex3i(8, 60, -8);
    glVertex3i(8, 40, -8);
    glVertex3i(-8, 40, -8);
    glEnd();
    //Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(8, 60, -8);
    glVertex3i(8, 60, 8);
    glVertex3i(8, 40, 8);
    glVertex3i(8, 40, -8);
    glEnd();
    //Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(8, 60, 8);
    glVertex3i(-8, 60, 8);
    glVertex3i(-8, 40, 8);
    glVertex3i(8, 40, 8);
    glEnd();
    //Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-8, 60, 8);
    glVertex3i(-8, 60, -8);
    glVertex3i(-8, 40, -8);
    glVertex3i(-8, 40, 8);
    glEnd();

    //Pojokan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-14, 40, -10);
    glVertex3i(-10, 40, -10);
    glVertex3i(-10, 40, -14);
    glVertex3i(-14, 40, -14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-14, 40, -10);
    glVertex3i(-10, 40, -10);
    glVertex3i(-10, 0, -10);
    glVertex3i(-14, 0, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 40, -10);
    glVertex3i(-10, 40, -14);
    glVertex3i(-10, 0, -14);
    glVertex3i(-10, 0, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 40, -14);
    glVertex3i(-14, 40, -14);
    glVertex3i(-14, 0, -14);
    glVertex3i(-10, 0, -14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-14, 40, -14);
    glVertex3i(-14, 40, -10);
    glVertex3i(-14, 0, -10);
    glVertex3i(-14, 0, -14);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 0, -12);
    glVertex3i(-10, 40, -12);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 0, -14);
    glVertex3i(-10, 40, -14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-14, 0, -14);
    glVertex3i(-14, 40, -14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-14, 0, -10);
    glVertex3i(-14, 40, -10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-12, 0, -10);
    glVertex3i(-12, 40, -10);
    glEnd();

    //Pojokan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 40, -10);
    glVertex3i(14, 40, -10);
    glVertex3i(14, 40, -14);
    glVertex3i(10, 40, -14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 40, -10);
    glVertex3i(14, 40, -10);
    glVertex3i(14, 0, -10);
    glVertex3i(10, 0, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(14, 40, -10);
    glVertex3i(14, 40, -14);
    glVertex3i(14, 0, -14);
    glVertex3i(14, 0, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(14, 40, -14);
    glVertex3i(10, 40, -14);
    glVertex3i(10, 0, -14);
    glVertex3i(14, 0, -14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 40, -14);
    glVertex3i(10, 40, -10);
    glVertex3i(10, 0, -10);
    glVertex3i(10, 0, -14);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 0, -12);
    glVertex3i(10, 40, -12);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 0, -14);
    glVertex3i(10, 40, -14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(14, 0, -14);
    glVertex3i(14, 40, -14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(14, 0, -10);
    glVertex3i(14, 40, -10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(12, 0, -10);
    glVertex3i(12, 40, -10);
    glEnd();

    //Pojokan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 40, 14);
    glVertex3i(14, 40, 14);
    glVertex3i(14, 40, 10);
    glVertex3i(10, 40, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 40, 14);
    glVertex3i(14, 40, 14);
    glVertex3i(14, 0, 14);
    glVertex3i(10, 0, 14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(14, 40, 14);
    glVertex3i(14, 40, 10);
    glVertex3i(14, 0, 10);
    glVertex3i(14, 0, 14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(14, 40, 10);
    glVertex3i(10, 40, 10);
    glVertex3i(10, 0, 10);
    glVertex3i(14, 0, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 40, 10);
    glVertex3i(10, 40, 14);
    glVertex3i(10, 0, 14);
    glVertex3i(10, 0, 10);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 0, 12);
    glVertex3i(10, 40, 12);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 0, 14);
    glVertex3i(10, 40, 14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(14, 0, 14);
    glVertex3i(14, 40, 14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(14, 0, 10);
    glVertex3i(14, 40, 10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(12, 0, 10);
    glVertex3i(12, 40, 10);
    glEnd();

    //Pojokan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-14, 40, 14);
    glVertex3i(-10, 40, 14);
    glVertex3i(-10, 40, 10);
    glVertex3i(-14, 40, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-14, 40, 14);
    glVertex3i(-10, 40, 14);
    glVertex3i(-10, 0, 14);
    glVertex3i(-14, 0, 14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 40, 14);
    glVertex3i(-10, 40, 10);
    glVertex3i(-10, 0, 10);
    glVertex3i(-10, 0, 14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 40, 10);
    glVertex3i(-14, 40, 10);
    glVertex3i(-14, 0, 10);
    glVertex3i(-10, 0, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-14, 40, 10);
    glVertex3i(-14, 40, 14);
    glVertex3i(-14, 0, 14);
    glVertex3i(-14, 0, 10);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 0, 12);
    glVertex3i(-10, 40, 12);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 0, 14);
    glVertex3i(-10, 40, 14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-14, 0, 14);
    glVertex3i(-14, 40, 14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-14, 0, 10);
    glVertex3i(-14, 40, 10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-12, 0, 10);
    glVertex3i(-12, 40, 10);
    glEnd();

    //Garis Atap
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 40, 12); glVertex3i(10, 40, 12);
    glVertex3i(10, 40, 12); glVertex3i(10, 40, 14);
    glVertex3i(10, 40, 14); glVertex3i(14, 40, 14);
    glVertex3i(14, 40, 14); glVertex3i(14, 40, 10);
    glVertex3i(14, 40, 10); glVertex3i(12, 40, 10);
    glVertex3i(12, 40, 10); glVertex3i(12, 40, -10);
    glVertex3i(12, 40, -10); glVertex3i(14, 40, -10);
    glVertex3i(14, 40, -10); glVertex3i(14, 40, -14);
    glVertex3i(14, 40, -14); glVertex3i(10, 40, -14);
    glVertex3i(10, 40, -14); glVertex3i(10, 40, -12);
    glVertex3i(10, 40, -12); glVertex3i(-10, 40, -12);
    glVertex3i(-10, 40, -12); glVertex3i(-10, 40, -14);
    glVertex3i(-10, 40, -14); glVertex3i(-14, 40, -14);
    glVertex3i(-14, 40, -14); glVertex3i(-14, 40, -10);
    glVertex3i(-14, 40, -10); glVertex3i(-12, 40, -10);
    glVertex3i(-12, 40, -10); glVertex3i(-12, 40, 10);
    glVertex3i(-12, 40, 10); glVertex3i(-14, 40, 10);
    glVertex3i(-14, 40, 10); glVertex3i(-14, 40, 14);
    glVertex3i(-14, 40, 14); glVertex3i(-10, 40, 14);
    glVertex3i(-10, 40, 14); glVertex3i(-10, 40, 12);
    glEnd();

    //Atas Pojokan 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-13, 42, -11);
    glVertex3i(-11, 42, -11);
    glVertex3i(-11, 42, -13);
    glVertex3i(-13, 42, -13);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-13, 42, -11);
    glVertex3i(-11, 42, -11);
    glVertex3i(-11, 40, -11);
    glVertex3i(-13, 40, -11);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-11, 42, -11);
    glVertex3i(-11, 42, -13);
    glVertex3i(-11, 40, -13);
    glVertex3i(-11, 40, -11);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-11, 42, -13);
    glVertex3i(-13, 42, -13);
    glVertex3i(-13, 40, -13);
    glVertex3i(-11, 40, -13);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-13, 42, -13);
    glVertex3i(-13, 42, -11);
    glVertex3i(-13, 40, -11);
    glVertex3i(-13, 40, -13);
    glEnd();
    //Garis Atas Pojokan
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-13, 42, -11);
    glVertex3i(-11, 42, -11);
    glVertex3i(-11, 42, -13);
    glVertex3i(-13, 42, -13);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-13, 42, -11);
    glVertex3i(-11, 42, -11);
    glVertex3i(-11, 40, -11);
    glVertex3i(-13, 40, -11);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-11, 42, -11);
    glVertex3i(-11, 42, -13);
    glVertex3i(-11, 40, -13);
    glVertex3i(-11, 40, -11);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-11, 42, -13);
    glVertex3i(-13, 42, -13);
    glVertex3i(-13, 40, -13);
    glVertex3i(-11, 40, -13);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-13, 42, -13);
    glVertex3i(-13, 42, -11);
    glVertex3i(-13, 40, -11);
    glVertex3i(-13, 40, -13);
    glEnd();

    //Atas Pojokan 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(13, 42, -11);
    glVertex3i(11, 42, -11);
    glVertex3i(11, 42, -13);
    glVertex3i(13, 42, -13);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(13, 42, -11);
    glVertex3i(11, 42, -11);
    glVertex3i(11, 40, -11);
    glVertex3i(13, 40, -11);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(11, 42, -11);
    glVertex3i(11, 42, -13);
    glVertex3i(11, 40, -13);
    glVertex3i(11, 40, -11);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(11, 42, -13);
    glVertex3i(13, 42, -13);
    glVertex3i(13, 40, -13);
    glVertex3i(11, 40, -13);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(13, 42, -13);
    glVertex3i(13, 42, -11);
    glVertex3i(13, 40, -11);
    glVertex3i(13, 40, -13);
    glEnd();
    //Garis Atas Pojokan
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(13, 42, -11);
    glVertex3i(11, 42, -11);
    glVertex3i(11, 42, -13);
    glVertex3i(13, 42, -13);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(13, 42, -11);
    glVertex3i(11, 42, -11);
    glVertex3i(11, 40, -11);
    glVertex3i(13, 40, -11);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(11, 42, -11);
    glVertex3i(11, 42, -13);
    glVertex3i(11, 40, -13);
    glVertex3i(11, 40, -11);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(11, 42, -13);
    glVertex3i(13, 42, -13);
    glVertex3i(13, 40, -13);
    glVertex3i(11, 40, -13);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(13, 42, -13);
    glVertex3i(13, 42, -11);
    glVertex3i(13, 40, -11);
    glVertex3i(13, 40, -13);
    glEnd();

    //Atas Pojokan 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(13, 42, 11);
    glVertex3i(11, 42, 11);
    glVertex3i(11, 42, 13);
    glVertex3i(13, 42, 13);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(13, 42, 11);
    glVertex3i(11, 42, 11);
    glVertex3i(11, 40, 11);
    glVertex3i(13, 40, 11);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(11, 42, 11);
    glVertex3i(11, 42, 13);
    glVertex3i(11, 40, 13);
    glVertex3i(11, 40, 11);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(11, 42, 13);
    glVertex3i(13, 42, 13);
    glVertex3i(13, 40, 13);
    glVertex3i(11, 40, 13);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(13, 42, 13);
    glVertex3i(13, 42, 11);
    glVertex3i(13, 40, 11);
    glVertex3i(13, 40, 13);
    glEnd();
    //Garis Atas Pojokan
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(13, 42, 11);
    glVertex3i(11, 42, 11);
    glVertex3i(11, 42, 13);
    glVertex3i(13, 42, 13);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(13, 42, 11);
    glVertex3i(11, 42, 11);
    glVertex3i(11, 40, 11);
    glVertex3i(13, 40, 11);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(11, 42, 11);
    glVertex3i(11, 42, 13);
    glVertex3i(11, 40, 13);
    glVertex3i(11, 40, 11);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(11, 42, 13);
    glVertex3i(13, 42, 13);
    glVertex3i(13, 40, 13);
    glVertex3i(11, 40, 13);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(13, 42, 13);
    glVertex3i(13, 42, 11);
    glVertex3i(13, 40, 11);
    glVertex3i(13, 40, 13);
    glEnd();

    //Atas Pojokan 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-13, 42, 11);
    glVertex3i(-11, 42, 11);
    glVertex3i(-11, 42, 13);
    glVertex3i(-13, 42, 13);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-13, 42, 11);
    glVertex3i(-11, 42, 11);
    glVertex3i(-11, 40, 11);
    glVertex3i(-13, 40, 11);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-11, 42, 11);
    glVertex3i(-11, 42, 13);
    glVertex3i(-11, 40, 13);
    glVertex3i(-11, 40, 11);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-11, 42, 13);
    glVertex3i(-13, 42, 13);
    glVertex3i(-13, 40, 13);
    glVertex3i(-11, 40, 13);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-13, 42, 13);
    glVertex3i(-13, 42, 11);
    glVertex3i(-13, 40, 11);
    glVertex3i(-13, 40, 13);
    glEnd();
    //Garis Atas Pojokan
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-13, 42, 11);
    glVertex3i(-11, 42, 11);
    glVertex3i(-11, 42, 13);
    glVertex3i(-13, 42, 13);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-13, 42, 11);
    glVertex3i(-11, 42, 11);
    glVertex3i(-11, 40, 11);
    glVertex3i(-13, 40, 11);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-11, 42, 11);
    glVertex3i(-11, 42, 13);
    glVertex3i(-11, 40, 13);
    glVertex3i(-11, 40, 11);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-11, 42, 13);
    glVertex3i(-13, 42, 13);
    glVertex3i(-13, 40, 13);
    glVertex3i(-11, 40, 13);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-13, 42, 13);
    glVertex3i(-13, 42, 11);
    glVertex3i(-13, 40, 11);
    glVertex3i(-13, 40, 13);
    glEnd();

    //Atap 3
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 224);
    glVertex3i(-3, 64, 5);
    glVertex3i(3, 64, 5);
    glVertex3i(5, 64, 3);
    glVertex3i(5, 64, -3);
    glVertex3i(3, 64, -5);
    glVertex3i(-3, 64, -5);
    glVertex3i(-5, 64, -3);
    glVertex3i(-5, 64, 3);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-3, 60, 5);
    glVertex3i(3, 60, 5);
    glVertex3i(3, 60, 5);
    glVertex3i(5, 60, 3);
    glVertex3i(5, 60, 3);
    glVertex3i(5, 60, -3);
    glVertex3i(5, 60, -3);
    glVertex3i(3, 60, -5);
    glVertex3i(3, 60, -5);
    glVertex3i(-3, 60, -5);
    glVertex3i(-3, 60, -5);
    glVertex3i(-5, 60, -3);
    glVertex3i(-5, 60, -3);
    glVertex3i(-5, 60, 3);
    glVertex3i(-5, 60, 3);
    glVertex3i(-3, 60, 5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-3, 64, 5);
    glVertex3i(3, 64, 5);
    glVertex3i(3, 64, 5);
    glVertex3i(5, 64, 3);
    glVertex3i(5, 64, 3);
    glVertex3i(5, 64, -3);
    glVertex3i(5, 64, -3);
    glVertex3i(3, 64, -5);
    glVertex3i(3, 64, -5);
    glVertex3i(-3, 64, -5);
    glVertex3i(-3, 64, -5);
    glVertex3i(-5, 64, -3);
    glVertex3i(-5, 64, -3);
    glVertex3i(-5, 64, 3);
    glVertex3i(-5, 64, 3);
    glVertex3i(-3, 64, 5);
    glEnd();
    //Tembok Atap 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-3, 64, 5);
    glVertex3i(3, 64, 5);
    glVertex3i(3, 60, 5);
    glVertex3i(-3, 60, 5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(3, 64, 5);
    glVertex3i(5, 64, 3);
    glVertex3i(5, 60, 3);
    glVertex3i(3, 60, 5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(5, 64, 3);
    glVertex3i(5, 64, -3);
    glVertex3i(5, 60, -3);
    glVertex3i(5, 60, 3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(5, 64, -3);
    glVertex3i(3, 64, -5);
    glVertex3i(3, 60, -5);
    glVertex3i(5, 60, -3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(3, 64, -5);
    glVertex3i(-3, 64, -5);
    glVertex3i(-3, 60, -5);
    glVertex3i(3, 60, -5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-3, 64, -5);
    glVertex3i(-5, 64, -3);
    glVertex3i(-5, 60, -3);
    glVertex3i(-3, 60, -5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-5, 64, -3);
    glVertex3i(-5, 64, 3);
    glVertex3i(-5, 60, 3);
    glVertex3i(-5, 60, -3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-5, 64, 3);
    glVertex3i(-3, 64, 5);
    glVertex3i(-3, 60, 5);
    glVertex3i(-5, 60, 3);
    glEnd();
    //Garis Tembok Atap 3
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-3, 60, 5);
    glVertex3i(-3, 64, 5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(3, 60, 5);
    glVertex3i(3, 64, 5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(5, 60, 3);
    glVertex3i(5, 64, 3);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(5, 60, -3);
    glVertex3i(5, 64, -3);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(3, 60, -5);
    glVertex3i(3, 64, -5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-3, 60, -5);
    glVertex3i(-3, 64, -5);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-5, 60, -3);
    glVertex3i(-5, 64, -3);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-5, 60, 3);
    glVertex3i(-5, 64, 3);
    glEnd();

    //Atap 4
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 224);
    glVertex3i(-2, 70, 3);
    glVertex3i(2, 70, 3);
    glVertex3i(3, 70, 2);
    glVertex3i(3, 70, -2);
    glVertex3i(2, 70, -3);
    glVertex3i(-2, 70, -3);
    glVertex3i(-3, 70, -2);
    glVertex3i(-3, 70, 2);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-2, 64, 3);
    glVertex3i(2, 64, 3);
    glVertex3i(2, 64, 3);
    glVertex3i(3, 64, 2);
    glVertex3i(3, 64, 2);
    glVertex3i(3, 64, -2);
    glVertex3i(3, 64, -2);
    glVertex3i(2, 64, -3);
    glVertex3i(2, 64, -3);
    glVertex3i(-2, 64, -3);
    glVertex3i(-2, 64, -3);
    glVertex3i(-3, 64, -2);
    glVertex3i(-3, 64, -2);
    glVertex3i(-3, 64, 2);
    glVertex3i(-3, 64, 2);
    glVertex3i(-2, 64, 3);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-2, 70, 3);
    glVertex3i(2, 70, 3);
    glVertex3i(2, 70, 3);
    glVertex3i(3, 70, 2);
    glVertex3i(3, 70, 2);
    glVertex3i(3, 70, -2);
    glVertex3i(3, 70, -2);
    glVertex3i(2, 70, -3);
    glVertex3i(2, 70, -3);
    glVertex3i(-2, 70, -3);
    glVertex3i(-2, 70, -3);
    glVertex3i(-3, 70, -2);
    glVertex3i(-3, 70, -2);
    glVertex3i(-3, 70, 2);
    glVertex3i(-3, 70, 2);
    glVertex3i(-2, 70, 3);
    glEnd();
    //Tembok Atap 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-2, 70, 3);
    glVertex3i(2, 70, 3);
    glVertex3i(2, 64, 3);
    glVertex3i(-2, 64, 3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(2, 70, 3);
    glVertex3i(3, 70, 2);
    glVertex3i(3, 64, 2);
    glVertex3i(2, 64, 3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(3, 70, 2);
    glVertex3i(3, 70, -2);
    glVertex3i(3, 64, -2);
    glVertex3i(3, 64, 2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(3, 70, -2);
    glVertex3i(2, 70, -3);
    glVertex3i(2, 64, -3);
    glVertex3i(3, 64, -2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(2, 70, -3);
    glVertex3i(-2, 70, -3);
    glVertex3i(-2, 64, -3);
    glVertex3i(2, 64, -3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-2, 70, -3);
    glVertex3i(-3, 70, -2);
    glVertex3i(-3, 64, -2);
    glVertex3i(-2, 64, -3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-3, 70, -2);
    glVertex3i(-3, 70, 2);
    glVertex3i(-3, 64, 2);
    glVertex3i(-3, 64, -2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-3, 70, 2);
    glVertex3i(-2, 70, 3);
    glVertex3i(-2, 64, 3);
    glVertex3i(-3, 64, 2);
    glEnd();
    //Garis Tembok Atap 4
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-2, 64, 3);
    glVertex3i(-2, 70, 3);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(2, 64, 3);
    glVertex3i(2, 70, 3);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(3, 64, 2);
    glVertex3i(3, 70, 2);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(3, 64, -2);
    glVertex3i(3, 70, -2);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(2, 64, -3);
    glVertex3i(2, 70, -3);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-2, 64, -3);
    glVertex3i(-2, 70, -3);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-3, 64, -2);
    glVertex3i(-3, 70, -2);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-3, 64, 2);
    glVertex3i(-3, 70, 2);
    glEnd();

    //Penyangga
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(-1.5, 73, 1.5);
    glVertex3f(1.5, 73, 1.5);
    glVertex3f(1.5, 73, -1.5);
    glVertex3f(-1.5, 73, -1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(-1.5, 73, 1.5);
    glVertex3f(1.5, 73, 1.5);
    glVertex3f(0.75, 70, 0.75);
    glVertex3f(-0.75, 70, 0.75);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(1.5, 73, 1.5);
    glVertex3f(1.5, 73, -1.5);
    glVertex3f(0.75, 70, -0.75);
    glVertex3f(0.75, 70, 0.75);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(1.5, 73, -1.5);
    glVertex3f(-1.5, 73, -1.5);
    glVertex3f(-0.75, 70, -0.75);
    glVertex3f(0.75, 70, -0.75);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(-1.5, 73, -1.5);
    glVertex3f(-1.5, 73, 1.5);
    glVertex3f(-0.75, 70, 0.75);
    glVertex3f(-0.75, 70, -0.75);
    glEnd();
    //Garis Penyangga
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-1.5, 73, 1.5);
    glVertex3f(1.5, 73, 1.5);
    glVertex3f(1.5, 73, -1.5);
    glVertex3f(-1.5, 73, -1.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-1.5, 73, 1.5);
    glVertex3f(1.5, 73, 1.5);
    glVertex3f(0.75, 70, 0.75);
    glVertex3f(-0.75, 70, 0.75);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(1.5, 73, 1.5);
    glVertex3f(1.5, 73, -1.5);
    glVertex3f(0.75, 70, -0.75);
    glVertex3f(0.75, 70, 0.75);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(1.5, 73, -1.5);
    glVertex3f(-1.5, 73, -1.5);
    glVertex3f(-0.75, 70, -0.75);
    glVertex3f(0.75, 70, -0.75);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-1.5, 73, -1.5);
    glVertex3f(-1.5, 73, 1.5);
    glVertex3f(-0.75, 70, 0.75);
    glVertex3f(-0.75, 70, -0.75);
    glEnd();

    //Pucuk
    glBegin(GL_TRIANGLES);
    glColor3ub(245, 222, 179);
    glVertex3i(-1, 73, 1);
    glVertex3i(0, 85, 0);
    glVertex3i(-1, 73, -1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(245, 222, 179);
    glVertex3i(-1, 73, 1);
    glVertex3i(0, 85, 0);
    glVertex3i(1, 73, 1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(245, 222, 179);
    glVertex3i(1, 73, 1);
    glVertex3i(0, 85, 0);
    glVertex3i(1, 73, -1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(245, 222, 179);
    glVertex3i(1, 73, -1);
    glVertex3i(0, 85, 0);
    glVertex3i(-1, 73, -1);
    glEnd();
    //Garis Pucuk
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-1, 73, 1);
    glVertex3i(0, 85, 0);
    glVertex3i(-1, 73, -1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-1, 73, 1);
    glVertex3i(0, 85, 0);
    glVertex3i(1, 73, 1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(1, 73, 1);
    glVertex3i(0, 85, 0);
    glVertex3i(1, 73, -1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(1, 73, -1);
    glVertex3i(0, 85, 0);
    glVertex3i(-1, 73, -1);
    glEnd();

    //Pojokan Atas
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 60, -6);
    glVertex3i(-6, 60, -6);
    glVertex3i(-6, 60, -10);
    glVertex3i(-10, 60, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 60, -6);
    glVertex3i(-6, 60, -6);
    glVertex3i(-6, 40, -6);
    glVertex3i(-10, 40, -6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-6, 60, -6);
    glVertex3i(-6, 60, -10);
    glVertex3i(-6, 40, -10);
    glVertex3i(-6, 40, -6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-6, 60, -10);
    glVertex3i(-10, 60, -10);
    glVertex3i(-10, 40, -10);
    glVertex3i(-6, 40, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 60, -10);
    glVertex3i(-10, 60, -6);
    glVertex3i(-10, 40, -6);
    glVertex3i(-10, 40, -10);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 40, -6);
    glVertex3i(-8, 60, -6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 40, -6);
    glVertex3i(-10, 60, -6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 40, -10);
    glVertex3i(-10, 60, -10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 40, -10);
    glVertex3i(-6, 60, -10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 40, -8);
    glVertex3i(-6, 60, -8);
    glEnd();

    //Pojokan Atas
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 60, -6);
    glVertex3i(6, 60, -6);
    glVertex3i(6, 60, -10);
    glVertex3i(10, 60, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 60, -6);
    glVertex3i(6, 60, -6);
    glVertex3i(6, 40, -6);
    glVertex3i(10, 40, -6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 60, -6);
    glVertex3i(6, 60, -10);
    glVertex3i(6, 40, -10);
    glVertex3i(6, 40, -6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 60, -10);
    glVertex3i(10, 60, -10);
    glVertex3i(10, 40, -10);
    glVertex3i(6, 40, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 60, -10);
    glVertex3i(10, 60, -6);
    glVertex3i(10, 40, -6);
    glVertex3i(10, 40, -10);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 40, -6);
    glVertex3i(8, 60, -6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 40, -6);
    glVertex3i(10, 60, -6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 40, -10);
    glVertex3i(10, 60, -10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 40, -10);
    glVertex3i(6, 60, -10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 40, -8);
    glVertex3i(6, 60, -8);
    glEnd();

    //Pojokan Atas
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 60, 6);
    glVertex3i(6, 60, 6);
    glVertex3i(6, 60, 10);
    glVertex3i(10, 60, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 60, 6);
    glVertex3i(6, 60, 6);
    glVertex3i(6, 40, 6);
    glVertex3i(10, 40, 6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 60, 6);
    glVertex3i(6, 60, 10);
    glVertex3i(6, 40, 10);
    glVertex3i(6, 40, 6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 60, 10);
    glVertex3i(10, 60, 10);
    glVertex3i(10, 40, 10);
    glVertex3i(6, 40, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 60, 10);
    glVertex3i(10, 60, 6);
    glVertex3i(10, 40, 6);
    glVertex3i(10, 40, 10);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 40, 6);
    glVertex3i(8, 60, 6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 40, 6);
    glVertex3i(10, 60, 6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 40, 10);
    glVertex3i(10, 60, 10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 40, 10);
    glVertex3i(6, 60, 10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 40, 8);
    glVertex3i(6, 60, 8);
    glEnd();

    //Pojokan Atas
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 60, 6);
    glVertex3i(-6, 60, 6);
    glVertex3i(-6, 60, 10);
    glVertex3i(-10, 60, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 60, 6);
    glVertex3i(-6, 60, 6);
    glVertex3i(-6, 40, 6);
    glVertex3i(-10, 40, 6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-6, 60, 6);
    glVertex3i(-6, 60, 10);
    glVertex3i(-6, 40, 10);
    glVertex3i(-6, 40, 6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-6, 60, 10);
    glVertex3i(-10, 60, 10);
    glVertex3i(-10, 40, 10);
    glVertex3i(-6, 40, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 60, 10);
    glVertex3i(-10, 60, 6);
    glVertex3i(-10, 40, 6);
    glVertex3i(-10, 40, 10);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 40, 6);
    glVertex3i(-8, 60, 6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 40, 6);
    glVertex3i(-10, 60, 6);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 40, 10);
    glVertex3i(-10, 60, 10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 40, 10);
    glVertex3i(-6, 60, 10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 40, 8);
    glVertex3i(-6, 60, 8);
    glEnd();

    //Garis Atap 2
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 40, 8); glVertex3i(6, 40, 8);
    glVertex3i(6, 40, 8); glVertex3i(6, 40, 10);
    glVertex3i(6, 40, 10); glVertex3i(10, 40, 10);
    glVertex3i(10, 40, 10); glVertex3i(10, 40, 6);
    glVertex3i(10, 40, 6); glVertex3i(8, 40, 6);
    glVertex3i(8, 40, 6); glVertex3i(8, 40, -6);
    glVertex3i(8, 40, -6); glVertex3i(10, 40, -6);
    glVertex3i(10, 40, -6); glVertex3i(10, 40, -10);
    glVertex3i(10, 40, -10); glVertex3i(6, 40, -10);
    glVertex3i(6, 40, -10); glVertex3i(6, 40, -8);
    glVertex3i(6, 40, -8); glVertex3i(-6, 40, -8);
    glVertex3i(-6, 40, -8); glVertex3i(-6, 40, -10);
    glVertex3i(-6, 40, -10); glVertex3i(-10, 40, -10);
    glVertex3i(-10, 40, -10); glVertex3i(-10, 40, -6);
    glVertex3i(-10, 40, -6); glVertex3i(-8, 40, -6);
    glVertex3i(-8, 40, -6); glVertex3i(-8, 40, 6);
    glVertex3i(-8, 40, 6); glVertex3i(-10, 40, 6);
    glVertex3i(-10, 40, 6); glVertex3i(-10, 40, 10);
    glVertex3i(-10, 40, 10); glVertex3i(-6, 40, 10);
    glVertex3i(-6, 40, 10); glVertex3i(-6, 40, 8);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 60, 8); glVertex3i(6, 60, 8);
    glVertex3i(6, 60, 8); glVertex3i(6, 60, 10);
    glVertex3i(6, 60, 10); glVertex3i(10, 60, 10);
    glVertex3i(10, 60, 10); glVertex3i(10, 60, 6);
    glVertex3i(10, 60, 6); glVertex3i(8, 60, 6);
    glVertex3i(8, 60, 6); glVertex3i(8, 60, -6);
    glVertex3i(8, 60, -6); glVertex3i(10, 60, -6);
    glVertex3i(10, 60, -6); glVertex3i(10, 60, -10);
    glVertex3i(10, 60, -10); glVertex3i(6, 60, -10);
    glVertex3i(6, 60, -10); glVertex3i(6, 60, -8);
    glVertex3i(6, 60, -8); glVertex3i(-6, 60, -8);
    glVertex3i(-6, 60, -8); glVertex3i(-6, 60, -10);
    glVertex3i(-6, 60, -10); glVertex3i(-10, 60, -10);
    glVertex3i(-10, 60, -10); glVertex3i(-10, 60, -6);
    glVertex3i(-10, 60, -6); glVertex3i(-8, 60, -6);
    glVertex3i(-8, 60, -6); glVertex3i(-8, 60, 6);
    glVertex3i(-8, 60, 6); glVertex3i(-10, 60, 6);
    glVertex3i(-10, 60, 6); glVertex3i(-10, 60, 10);
    glVertex3i(-10, 60, 10); glVertex3i(-6, 60, 10);
    glVertex3i(-6, 60, 10); glVertex3i(-6, 60, 8);
    glEnd();

    //Atas Pojokan Kedua 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-9, 62, -7);
    glVertex3i(-7, 62, -7);
    glVertex3i(-7, 62, -9);
    glVertex3i(-9, 62, -9);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-9, 62, -7);
    glVertex3i(-7, 62, -7);
    glVertex3i(-7, 60, -7);
    glVertex3i(-9, 60, -7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-7, 62, -7);
    glVertex3i(-7, 62, -9);
    glVertex3i(-7, 60, -9);
    glVertex3i(-7, 60, -7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-7, 62, -9);
    glVertex3i(-9, 62, -9);
    glVertex3i(-9, 60, -9);
    glVertex3i(-7, 60, -9);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-9, 62, -9);
    glVertex3i(-9, 62, -7);
    glVertex3i(-9, 60, -7);
    glVertex3i(-9, 60, -9);
    glEnd();
    //Garis Atas Pojokan Kedua
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-9, 62, -7);
    glVertex3i(-7, 62, -7);
    glVertex3i(-7, 62, -9);
    glVertex3i(-9, 62, -9);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-9, 62, -7);
    glVertex3i(-7, 62, -7);
    glVertex3i(-7, 60, -7);
    glVertex3i(-9, 60, -7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-7, 62, -7);
    glVertex3i(-7, 62, -9);
    glVertex3i(-7, 60, -9);
    glVertex3i(-7, 60, -7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-7, 62, -9);
    glVertex3i(-9, 62, -9);
    glVertex3i(-9, 60, -9);
    glVertex3i(-7, 60, -9);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-9, 62, -9);
    glVertex3i(-9, 62, -7);
    glVertex3i(-9, 60, -7);
    glVertex3i(-9, 60, -9);
    glEnd();

    //Atas Pojokan Kedua 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(9, 62, -7);
    glVertex3i(7, 62, -7);
    glVertex3i(7, 62, -9);
    glVertex3i(9, 62, -9);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(9, 62, -7);
    glVertex3i(7, 62, -7);
    glVertex3i(7, 60, -7);
    glVertex3i(9, 60, -7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(7, 62, -7);
    glVertex3i(7, 62, -9);
    glVertex3i(7, 60, -9);
    glVertex3i(7, 60, -7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(7, 62, -9);
    glVertex3i(9, 62, -9);
    glVertex3i(9, 60, -9);
    glVertex3i(7, 60, -9);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(9, 62, -9);
    glVertex3i(9, 62, -7);
    glVertex3i(9, 60, -7);
    glVertex3i(9, 60, -9);
    glEnd();
    //Garis Atas Pojokan Kedua
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(9, 62, -7);
    glVertex3i(7, 62, -7);
    glVertex3i(7, 62, -9);
    glVertex3i(9, 62, -9);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(9, 62, -7);
    glVertex3i(7, 62, -7);
    glVertex3i(7, 60, -7);
    glVertex3i(9, 60, -7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(7, 62, -7);
    glVertex3i(7, 62, -9);
    glVertex3i(7, 60, -9);
    glVertex3i(7, 60, -7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(7, 62, -9);
    glVertex3i(9, 62, -9);
    glVertex3i(9, 60, -9);
    glVertex3i(7, 60, -9);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(9, 62, -9);
    glVertex3i(9, 62, -7);
    glVertex3i(9, 60, -7);
    glVertex3i(9, 60, -9);
    glEnd();

    //Atas Pojokan Kedua 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(9, 62, 7);
    glVertex3i(7, 62, 7);
    glVertex3i(7, 62, 9);
    glVertex3i(9, 62, 9);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(9, 62, 7);
    glVertex3i(7, 62, 7);
    glVertex3i(7, 60, 7);
    glVertex3i(9, 60, 7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(7, 62, 7);
    glVertex3i(7, 62, 9);
    glVertex3i(7, 60, 9);
    glVertex3i(7, 60, 7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(7, 62, 9);
    glVertex3i(9, 62, 9);
    glVertex3i(9, 60, 9);
    glVertex3i(7, 60, 9);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(9, 62, 9);
    glVertex3i(9, 62, 7);
    glVertex3i(9, 60, 7);
    glVertex3i(9, 60, 9);
    glEnd();
    //Garis Atas Pojokan Kedua
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(9, 62, 7);
    glVertex3i(7, 62, 7);
    glVertex3i(7, 62, 9);
    glVertex3i(9, 62, 9);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(9, 62, 7);
    glVertex3i(7, 62, 7);
    glVertex3i(7, 60, 7);
    glVertex3i(9, 60, 7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(7, 62, 7);
    glVertex3i(7, 62, 9);
    glVertex3i(7, 60, 9);
    glVertex3i(7, 60, 7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(7, 62, 9);
    glVertex3i(9, 62, 9);
    glVertex3i(9, 60, 9);
    glVertex3i(7, 60, 9);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(9, 62, 9);
    glVertex3i(9, 62, 7);
    glVertex3i(9, 60, 7);
    glVertex3i(9, 60, 9);
    glEnd();

    //Atas Pojokan Kedua 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-9, 62, 7);
    glVertex3i(-7, 62, 7);
    glVertex3i(-7, 62, 9);
    glVertex3i(-9, 62, 9);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-9, 62, 7);
    glVertex3i(-7, 62, 7);
    glVertex3i(-7, 60, 7);
    glVertex3i(-9, 60, 7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-7, 62, 7);
    glVertex3i(-7, 62, 9);
    glVertex3i(-7, 60, 9);
    glVertex3i(-7, 60, 7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-7, 62, 9);
    glVertex3i(-9, 62, 9);
    glVertex3i(-9, 60, 9);
    glVertex3i(-7, 60, 9);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-9, 62, 9);
    glVertex3i(-9, 62, 7);
    glVertex3i(-9, 60, 7);
    glVertex3i(-9, 60, 9);
    glEnd();
    //Garis Atas Pojokan Kedua
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-9, 62, 7);
    glVertex3i(-7, 62, 7);
    glVertex3i(-7, 62, 9);
    glVertex3i(-9, 62, 9);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-9, 62, 7);
    glVertex3i(-7, 62, 7);
    glVertex3i(-7, 60, 7);
    glVertex3i(-9, 60, 7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-7, 62, 7);
    glVertex3i(-7, 62, 9);
    glVertex3i(-7, 60, 9);
    glVertex3i(-7, 60, 7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-7, 62, 9);
    glVertex3i(-9, 62, 9);
    glVertex3i(-9, 60, 9);
    glVertex3i(-7, 60, 9);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-9, 62, 9);
    glVertex3i(-9, 62, 7);
    glVertex3i(-9, 60, 7);
    glVertex3i(-9, 60, 9);
    glEnd();

    //Gerbang Depan Alas
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 0, 12);
    glVertex3i(-6, 0, 12);
    glVertex3i(-6, 0, 30);
    glVertex3i(6, 0, 30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 1, 12);
    glVertex3i(-6, 1, 12);
    glVertex3i(-6, 1, 29);
    glVertex3i(6, 1, 29);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 2, 12);
    glVertex3i(-6, 2, 12);
    glVertex3i(-6, 2, 28);
    glVertex3i(6, 2, 28);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 1, 29);
    glVertex3i(-6, 1, 29);
    glVertex3i(-6, 0, 29);
    glVertex3i(6, 0, 29);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 1, 29);
    glVertex3i(-6, 1, 29);
    glVertex3i(-6, 0, 29);
    glVertex3i(6, 0, 29);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 1, 26);
    glVertex3i(6, 1, 29);
    glVertex3i(6, 0, 29);
    glVertex3i(6, 0, 26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 1, 26);
    glVertex3i(-6, 1, 29);
    glVertex3i(-6, 0, 29);
    glVertex3i(-6, 0, 26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 2, 28);
    glVertex3i(-6, 2, 28);
    glVertex3i(-6, 1, 28);
    glVertex3i(6, 1, 28);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 2, 26);
    glVertex3i(6, 2, 28);
    glVertex3i(6, 1, 28);
    glVertex3i(6, 1, 26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 2, 26);
    glVertex3i(-6, 2, 28);
    glVertex3i(-6, 1, 28);
    glVertex3i(-6, 1, 26);
    glEnd();
    //Pintu Gerbang
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 200);
    glVertex3i(6, 10, 26);
    glVertex3i(-6, 10, 26);
    glColor3ub(255, 255, 255);
    glVertex3i(-6, 2, 26);
    glVertex3i(6, 2, 26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(4, 2, 26);
    glVertex3i(4, 10, 26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(2, 2, 26);
    glVertex3i(2, 10, 26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(0, 2, 26);
    glVertex3i(0, 10, 26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-2, 2, 26);
    glVertex3i(-2, 10, 26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-4, 2, 26);
    glVertex3i(-4, 10, 26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 6, 26);
    glVertex3i(-6, 6, 26);
    glEnd();
    //Gerbang Depan Atap
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(8, 10, 12);
    glVertex3i(-8, 10, 12);
    glVertex3i(-8, 10, 26);
    glVertex3i(8, 10, 26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(8, 12, 12);
    glVertex3i(-8, 12, 12);
    glVertex3i(-8, 12, 26);
    glVertex3i(8, 12, 26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(10, 12, 22);
    glVertex3i(-10, 12, 22);
    glVertex3i(-10, 12, 26);
    glVertex3i(10, 12, 26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(8, 12, 12);
    glVertex3i(8, 12, 22);
    glVertex3i(8, 10, 22);
    glVertex3i(8, 10, 12);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(8, 12, 22);
    glVertex3i(10, 12, 22);
    glVertex3i(10, 10, 22);
    glVertex3i(8, 10, 22);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(10, 12, 22);
    glVertex3i(10, 12, 26);
    glVertex3i(10, 10, 26);
    glVertex3i(10, 10, 22);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(10, 12, 26);
    glVertex3i(-10, 12, 26);
    glVertex3i(-10, 10, 26);
    glVertex3i(10, 10, 26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(-8, 12, 12);
    glVertex3i(-8, 12, 22);
    glVertex3i(-8, 10, 22);
    glVertex3i(-8, 10, 12);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(-8, 12, 22);
    glVertex3i(-10, 12, 22);
    glVertex3i(-10, 10, 22);
    glVertex3i(-8, 10, 22);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(-10, 12, 22);
    glVertex3i(-10, 12, 26);
    glVertex3i(-10, 10, 26);
    glVertex3i(-10, 10, 22);
    glEnd();
    //Gerbang Depan Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-6, 10, 26);
    glVertex3i(-6, 10, 12);
    glVertex3i(-6, 0, 12);
    glVertex3i(-6, 0, 26);
    glEnd();
    //Gerbang Depan Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 10, 26);
    glVertex3i(6, 10, 12);
    glVertex3i(6, 0, 12);
    glVertex3i(6, 0, 26);
    glEnd();
    //Gerbang Depan Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-8, 10, 26);
    glVertex3i(-8, 10, 12);
    glVertex3i(-8, 0, 12);
    glVertex3i(-8, 0, 26);
    glEnd();
    //Gerbang Depan Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(8, 10, 26);
    glVertex3i(8, 10, 12);
    glVertex3i(8, 0, 12);
    glVertex3i(8, 0, 26);
    glEnd();
    //Gerbang Depan Tembok 5
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-8, 10, 26);
    glVertex3i(-6, 10, 26);
    glVertex3i(-6, 0, 26);
    glVertex3i(-8, 0, 26);
    glEnd();
    //Gerbang Depan Tembok 6
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(8, 10, 26);
    glVertex3i(6, 10, 26);
    glVertex3i(6, 0, 26);
    glVertex3i(8, 0, 26);
    glEnd();
    //Garis Tembok Depan
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 0, 26);
    glVertex3i(8, 10, 26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 0, 26);
    glVertex3i(6, 10, 26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 0, 26);
    glVertex3i(-8, 10, 26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 0, 26);
    glVertex3i(-6, 10, 26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 0, 26);
    glVertex3i(8, 10, 26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 2, 26);
    glVertex3i(-6, 2, 26);
    glEnd();

    //Gerbang Belakang
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 0, -12);
    glVertex3i(-6, 0, -12);
    glVertex3i(-6, 0, -30);
    glVertex3i(6, 0, -30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 1, -12);
    glVertex3i(-6, 1, -12);
    glVertex3i(-6, 1, -29);
    glVertex3i(6, 1, -29);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 2, -12);
    glVertex3i(-6, 2, -12);
    glVertex3i(-6, 2, -28);
    glVertex3i(6, 2, -28);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 1, -29);
    glVertex3i(-6, 1, -29);
    glVertex3i(-6, 0, -29);
    glVertex3i(6, 0, -29);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 1, -29);
    glVertex3i(-6, 1, -29);
    glVertex3i(-6, 0, -29);
    glVertex3i(6, 0, -29);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 1, -26);
    glVertex3i(6, 1, -29);
    glVertex3i(6, 0, -29);
    glVertex3i(6, 0, -26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 1, -26);
    glVertex3i(-6, 1, -29);
    glVertex3i(-6, 0, -29);
    glVertex3i(-6, 0, -26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 2, -28);
    glVertex3i(-6, 2, -28);
    glVertex3i(-6, 1, -28);
    glVertex3i(6, 1, -28);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 2, -26);
    glVertex3i(6, 2, -28);
    glVertex3i(6, 1, -28);
    glVertex3i(6, 1, -26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 2, -26);
    glVertex3i(-6, 2, -28);
    glVertex3i(-6, 1, -28);
    glVertex3i(-6, 1, -26);
    glEnd();
    //Gerbang Belakang Atap
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(6, 10, -12);
    glVertex3i(-6, 10, -12);
    glVertex3i(-6, 10, -26);
    glVertex3i(6, 10, -26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(6, 12, -12);
    glVertex3i(-6, 12, -12);
    glVertex3i(-6, 12, -26);
    glVertex3i(6, 12, -26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(6, 12, -12);
    glVertex3i(6, 12, -26);
    glVertex3i(6, 10, -26);
    glVertex3i(6, 10, -12);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(-6, 12, -12);
    glVertex3i(-6, 12, -26);
    glVertex3i(-6, 10, -26);
    glVertex3i(-6, 10, -12);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex3i(6, 12, -26);
    glVertex3i(-6, 12, -26);
    glVertex3i(-6, 10, -26);
    glVertex3i(6, 10, -26);
    glEnd();
    //Gerbang Belakang Tembok
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(6, 10, -12);
    glVertex3i(6, 10, -26);
    glVertex3i(6, 0, -26);
    glVertex3i(6, 0, -12);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-6, 10, -12);
    glVertex3i(-6, 10, -26);
    glVertex3i(-6, 0, -26);
    glVertex3i(-6, 0, -12);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 0, -26);
    glVertex3i(6, 10, -26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 0, -26);
    glVertex3i(-6, 10, -26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 200);
    glVertex3i(6, 10, -26);
    glVertex3i(-6, 10, -26);
    glColor3ub(255, 255, 255);
    glVertex3i(-6, 2, -26);
    glVertex3i(6, 2, -26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(4, 2, -26);
    glVertex3i(4, 10, -26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(2, 2, -26);
    glVertex3i(2, 10, -26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(0, 2, -26);
    glVertex3i(0, 10, -26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-2, 2, -26);
    glVertex3i(-2, 10, -26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-4, 2, -26);
    glVertex3i(-4, 10, -26);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 6, -26);
    glVertex3i(-6, 6, -26);
    glEnd();

    //Sayap Kanan Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(12, 28, 6);
    glVertex3i(40, 28, 6);
    glVertex3i(40, 0, 6);
    glVertex3i(12, 0, 6);
    glEnd();
    //Sayap Kanan Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(12, 28, -6);
    glVertex3i(40, 28, -6);
    glVertex3i(40, 0, -6);
    glVertex3i(12, 0, -6);
    glEnd();
    //Sayap Kanan Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(12, 28, -6);
    glVertex3i(12, 28, 6);
    glVertex3i(40, 28, 6);
    glVertex3i(40, 28, -6);
    glEnd();
    //Garis Kanan 1
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 28, 6);
    glVertex3i(40, 28, 6);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(6, 28, -6);
    glVertex3i(40, 28, -6);
    glEnd();

    //Jendela Sayap kanan tembok 1
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(0, -4 * i, 0 );//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(18, 26, 6.1);
            glVertex3f(19, 26, 6.1);
            glVertex3f(19, 23, 6.1);
            glVertex3f(18, 23, 6.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kanan tembok 1
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(18, 26, 6.1);
            glVertex3f(19, 26, 6.1);
            glVertex3f(19, 23, 6.1);
            glVertex3f(18, 23, 6.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(18.5, 26, 6.1);
            glVertex3f(18.5, 23, 6.1);
            glVertex3f(18, 25, 6.1);
            glVertex3f(19, 25, 6.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kanan tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(18, 26, -6.1);
            glVertex3f(19, 26, -6.1);
            glVertex3f(19, 23, -6.1);
            glVertex3f(18, 23, -6.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kanan tembok 2
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(18, 26, -6.1);
            glVertex3f(19, 26, -6.1);
            glVertex3f(19, 23, -6.1);
            glVertex3f(18, 23, -6.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(18.5, 26, -6.1);
            glVertex3f(18.5, 23, -6.1);
            glVertex3f(18, 25, -6.1);
            glVertex3f(19, 25, -6.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kanan 2 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(40, 28, -30);
    glVertex3i(40, 28, 30);
    glVertex3i(40, 0, 30);
    glVertex3i(40, 0, -30);
    glEnd();
    //Sayap Kanan 2 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(50, 28, -30);
    glVertex3i(50, 28, 30);
    glVertex3i(50, 0, 30);
    glVertex3i(50, 0, -30);
    glEnd();
    //Sayap Kanan 2 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(50, 28, 30);
    glVertex3i(40, 28, 30);
    glVertex3i(40, 0, 30);
    glVertex3i(50, 0, 30);
    glEnd();
    //Sayap Kanan 2 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(40, 28, -30);
    glVertex3i(50, 28, -30);
    glVertex3i(50, 0, -30);
    glVertex3i(40, 0, -30);
    glEnd();
    //Sayap Kanan 2 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(40, 28, 30);
    glVertex3i(50, 28, 30);
    glVertex3i(50, 28, -30);
    glVertex3i(40, 28, -30);
    glEnd();
    //Garis Kanan 2
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(40, 28, 6); glVertex3i(40, 28, 30);
    glVertex3i(40, 28, 30); glVertex3i(44, 28, 30);
    glVertex3i(44, 28, 30); glVertex3i(44, 28, 36);
    glVertex3i(44, 28, 36); glVertex3i(56, 28, 36);
    glVertex3i(56, 28, 36); glVertex3i(56, 28, 24);
    glVertex3i(56, 28, 24); glVertex3i(50, 28, 24);
    glVertex3i(50, 28, 24); glVertex3i(50, 28, -24);
    glVertex3i(50, 28, -24); glVertex3i(56, 28, -24);
    glVertex3i(56, 28, -24); glVertex3i(56, 28, -36);
    glVertex3i(56, 28, -36); glVertex3i(44, 28, -36);
    glVertex3i(44, 28, -36); glVertex3i(44, 28, -30);
    glVertex3i(44, 28, -30); glVertex3i(40, 28, -30);
    glVertex3i(40, 28, -6); glVertex3i(40, 28, -30);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(40, 0, 6);
    glVertex3i(40, 28, 6);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(40, 0, -6);
    glVertex3i(40, 28, -6);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(40, 0, 30);
    glVertex3i(40, 28, 30);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(40, 0, -30);
    glVertex3i(40, 28, -30);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(50, 0, 24);
    glVertex3i(50, 28, 24);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(50, 0, -24);
    glVertex3i(50, 28, -24);
    glEnd();

    //Jendela Sayap kanan 2 tembok 1
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 26; j++) {
        glPushMatrix();
        glTranslatef( 0, 0, -2.3 * j); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(39.9, 24, 28);
            glVertex3f(39.9, 24, 28.90);
            glVertex3f(39.9, 21, 28.90);
            glVertex3f(39.9, 21, 28);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kanan 2 tembok 1
    glColor3f(0, 0, 0);
    for (j = 0; j < 26; j++) {
        glPushMatrix();
        glTranslatef(0, 0, -2.3 * j); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(39.9, 24, 28);
            glVertex3f(39.9, 24, 28.90);
            glVertex3f(39.9, 21, 28.90);
            glVertex3f(39.9, 21, 28);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(39.9, 24, 28.45);
            glVertex3f(39.9, 21, 28.45);
            glVertex3f(39.9, 23, 28);
            glVertex3f(39.9, 23, 28.90);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kanan 2 tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 26; j++) {
        glPushMatrix();
        glTranslatef(0, 0, -2.3 * j); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(50.1, 24, 28);
            glVertex3f(50.1, 24, 28.90);
            glVertex3f(50.1, 21, 28.90);
            glVertex3f(50.1, 21, 28);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Bingkai Jendela sayap kanan 2 tembok 2
    glColor3f(0, 0, 0);
    for (j = 0; j < 26; j++) {
        glPushMatrix();
        glTranslatef(0, 0, -2.3 * j); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(50.1, 24, 28);
            glVertex3f(50.1, 24, 28.90);
            glVertex3f(50.1, 21, 28.90);
            glVertex3f(50.1 , 21, 28);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(50.1, 24, 28.45);
            glVertex3f(50.1, 21, 28.45);
            glVertex3f(50.1, 23, 28);
            glVertex3f(50.1, 23, 28.90);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kanan 3 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(44, 28, -24);
    glVertex3i(56, 28, -24);
    glVertex3i(56, 28, -36);
    glVertex3i(44, 28, -36);
    glEnd();
    //Sayap Kanan 3 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(44, 28, -36);
    glVertex3i(44, 28, -24);
    glVertex3i(44, 0, -24);
    glVertex3i(44, 0, -36);
    glEnd();
    //Sayap Kanan 3 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(44, 28, -36);
    glVertex3i(56, 28, -36);
    glVertex3i(56, 0, -36);
    glVertex3i(44, 0, -36);
    glEnd();
    //Sayap Kanan 3 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(44, 28, -24);
    glVertex3i(56, 28, -24);
    glVertex3i(56, 0, -24);
    glVertex3i(44, 0, -24);
    glEnd();
    //Sayap Kanan 3 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(56, 28, -24);
    glVertex3i(56, 28, -36);
    glVertex3i(56, 0, -36);
    glVertex3i(56, 0, -24);
    glEnd();
    //Garis Kanan 3
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(44, 0, -30);
    glVertex3i(44, 28, -30);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(44, 0, -36);
    glVertex3i(44, 28, -36);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(56, 0, -36);
    glVertex3i(56, 28, -36);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(56, 0, -24);
    glVertex3i(56, 28, -24);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(50, 0, -24);
    glVertex3i(50, 28, -24);
    glEnd();

    //Jendela Sayap kanan 3 tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(1, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(45, 26, -36.1);
            glVertex3f(45.60, 26, -36.1);
            glVertex3f(45.60, 23, -36.1);
            glVertex3f(45, 23, -36.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kanan 3 tembok 2
    glColor3f(0, 0, 0);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(1, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(45, 26, -36.1);
            glVertex3f(45.60, 26, -36.1);
            glVertex3f(45.60, 23, -36.1);
            glVertex3f(45, 23, -36.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(45.30, 26, -36.1);
            glVertex3f(45.30, 23, -36.1);
            glVertex3f(45, 25, -36.1);
            glVertex3f(45.60, 25, -36.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kanan 3 tembok 3
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(1, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(45, 26, -23.9);
            glVertex3f(45.60, 26, -23.9);
            glVertex3f(45.60, 23, -23.9);
            glVertex3f(45, 23, -23.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kanan 3 tembok 3
    glColor3f(0, 0, 0);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(1, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(45, 26, -23.9);
            glVertex3f(45.60, 26, -23.9);
            glVertex3f(45.60, 23, -23.9);
            glVertex3f(45, 23, -23.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(45.30, 26, -23.9);
            glVertex3f(45.30, 23, -23.9);
            glVertex3f(45, 25, -23.9);
            glVertex3f(45.60, 25, -23.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Atas Sayap Kanan 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(47, 38, -27);
    glVertex3i(53, 38, -27);
    glVertex3i(53, 38, -33);
    glVertex3i(47, 38, -33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(47, 38, -33);
    glVertex3i(47, 38, -27);
    glVertex3i(47, 28, -27);
    glVertex3i(47, 28, -33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(47, 38, -33);
    glVertex3i(53, 38, -33);
    glVertex3i(53, 28, -33);
    glVertex3i(47, 28, -33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(47, 38, -27);
    glVertex3i(53, 38, -27);
    glVertex3i(53, 28, -27);
    glVertex3i(47, 28, -27);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(53, 38, -27);
    glVertex3i(53, 38, -33);
    glVertex3i(53, 28, -33);
    glVertex3i(53, 28, -27);
    glEnd();
    //Garis Atas Sayap Kanan 3
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(47, 38, -27);
    glVertex3i(53, 38, -27);
    glVertex3i(53, 38, -33);
    glVertex3i(47, 38, -33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(47, 38, -33);
    glVertex3i(47, 38, -27);
    glVertex3i(47, 28, -27);
    glVertex3i(47, 28, -33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(47, 38, -33);
    glVertex3i(53, 38, -33);
    glVertex3i(53, 28, -33);
    glVertex3i(47, 28, -33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(47, 38, -27);
    glVertex3i(53, 38, -27);
    glVertex3i(53, 28, -27);
    glVertex3i(47, 28, -27);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(53, 38, -27);
    glVertex3i(53, 38, -33);
    glVertex3i(53, 28, -33);
    glVertex3i(53, 28, -27);
    glEnd();

    //Sayap Kanan 4 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(44, 28, 24);
    glVertex3i(56, 28, 24);
    glVertex3i(56, 28, 36);
    glVertex3i(44, 28, 36);
    glEnd();
    //Sayap Kanan 4 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(44, 28, 36);
    glVertex3i(44, 28, 24);
    glVertex3i(44, 0, 24);
    glVertex3i(44, 0, 36);
    glEnd();
    //Sayap Kanan 4 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(44, 28, 36);
    glVertex3i(56, 28, 36);
    glVertex3i(56, 0, 36);
    glVertex3i(44, 0, 36);
    glEnd();
    //Sayap Kanan 4 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(44, 28, 24);
    glVertex3i(56, 28, 24);
    glVertex3i(56, 0, 24);
    glVertex3i(44, 0, 24);
    glEnd();
    //Sayap Kanan 4 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(56, 28, 24);
    glVertex3i(56, 28, 36);
    glVertex3i(56, 0, 36);
    glVertex3i(56, 0, 24);
    glEnd();
    //Garis Kanan 4
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(44, 0, 30);
    glVertex3i(44, 28, 30);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(44, 0, 36);
    glVertex3i(44, 28, 36);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(56, 0, 36);
    glVertex3i(56, 28, 36);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(56, 0, 24);
    glVertex3i(56, 28, 24);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(50, 0, 24);
    glVertex3i(50, 28, 24);
    glEnd();

    //Jendela Sayap kanan 4 tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(1, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(45, 26, 36.1);
            glVertex3f(45.60, 26, 36.1);
            glVertex3f(45.60, 23, 36.1);
            glVertex3f(45, 23, 36.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kanan 4 tembok 2
    glColor3f(0, 0, 0);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(1, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(45, 26, 36.1);
            glVertex3f(45.60, 26, 36.1);
            glVertex3f(45.60, 23, 36.1);
            glVertex3f(45, 23, 36.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(45.30, 26, 36.1);
            glVertex3f(45.30, 23, 36.1);
            glVertex3f(45, 25, 36.1);
            glVertex3f(45.60, 25, 36.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kanan 4 tembok 3
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(1, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(45, 26, 23.9);
            glVertex3f(45.60, 26, 23.9);
            glVertex3f(45.60, 23, 23.9);
            glVertex3f(45, 23, 23.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kanan 4 tembok 3
    glColor3f(0, 0, 0);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(1, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(45, 26, 23.9);
            glVertex3f(45.60, 26, 23.9);
            glVertex3f(45.60, 23, 23.9);
            glVertex3f(45, 23, 23.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(45.30, 26, 23.9);
            glVertex3f(45.30, 23, 23.9);
            glVertex3f(45, 25, 23.9);
            glVertex3f(45.60, 25, 23.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Atas Sayap Kanan 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(47, 38, 27);
    glVertex3i(53, 38, 27);
    glVertex3i(53, 38, 33);
    glVertex3i(47, 38, 33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(47, 38, 33);
    glVertex3i(47, 38, 27);
    glVertex3i(47, 28, 27);
    glVertex3i(47, 28, 33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(47, 38, 33);
    glVertex3i(53, 38, 33);
    glVertex3i(53, 28, 33);
    glVertex3i(47, 28, 33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(47, 38, 27);
    glVertex3i(53, 38, 27);
    glVertex3i(53, 28, 27);
    glVertex3i(47, 28, 27);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(53, 38, 27);
    glVertex3i(53, 38, 33);
    glVertex3i(53, 28, 33);
    glVertex3i(53, 28, 27);
    glEnd();
    //Garis Atas Sayap Kanan 4
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(47, 38, 27);
    glVertex3i(53, 38, 27);
    glVertex3i(53, 38, 33);
    glVertex3i(47, 38, 33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(47, 38, 33);
    glVertex3i(47, 38, 27);
    glVertex3i(47, 28, 27);
    glVertex3i(47, 28, 33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(47, 38, 33);
    glVertex3i(53, 38, 33);
    glVertex3i(53, 28, 33);
    glVertex3i(47, 28, 33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(47, 38, 27);
    glVertex3i(53, 38, 27);
    glVertex3i(53, 28, 27);
    glVertex3i(47, 28, 27);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(53, 38, 27);
    glVertex3i(53, 38, 33);
    glVertex3i(53, 28, 33);
    glVertex3i(53, 28, 27);
    glEnd();

    //Garis Sayap Kanan 5-12
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(56, 18, 26); glVertex3i(76, 18, 26);
    glVertex3i(76, 18, 26); glVertex3i(76, 18, 38);
    glVertex3i(76, 18, 38); glVertex3i(90, 18, 38);
    glVertex3i(90, 18, 38); glVertex3i(90, 18, 40);
    glVertex3i(90, 18, 40); glVertex3i(94, 18, 40);
    glVertex3i(94, 18, 40); glVertex3i(94, 18, 42);
    glVertex3i(94, 18, 42); glVertex3i(90, 18, 42);
    glVertex3i(90, 18, 42); glVertex3i(90, 18, 44);
    glVertex3i(90, 18, 44); glVertex3i(66, 18, 44);
    glVertex3i(66, 18, 44); glVertex3i(66, 18, 38);
    glVertex3i(66, 18, 38); glVertex3i(68, 18, 38);
    glVertex3i(68, 18, 38); glVertex3i(68, 18, 34);
    glVertex3i(68, 18, 34); glVertex3i(56, 18, 34);
    glVertex3i(56, 18, 34); glVertex3i(56, 18, 26);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(56, 18, -26); glVertex3i(76, 18, -26);
    glVertex3i(76, 18, -26); glVertex3i(76, 18, -38);
    glVertex3i(76, 18, -38); glVertex3i(90, 18, -38);
    glVertex3i(90, 18, -38); glVertex3i(90, 18, -40);
    glVertex3i(90, 18, -40); glVertex3i(94, 18, -40);
    glVertex3i(94, 18, -40); glVertex3i(94, 18, -42);
    glVertex3i(94, 18, -42); glVertex3i(90, 18, -42);
    glVertex3i(90, 18, -42); glVertex3i(90, 18, -44);
    glVertex3i(90, 18, -44); glVertex3i(66, 18, -44);
    glVertex3i(66, 18, -44); glVertex3i(66, 18, -38);
    glVertex3i(66, 18, -38); glVertex3i(68, 18, -38);
    glVertex3i(68, 18, -38); glVertex3i(68, 18, -34);
    glVertex3i(68, 18, -34); glVertex3i(56, 18, -34);
    glVertex3i(56, 18, -34); glVertex3i(56, 18, -26);
    glEnd();

    //Sayap Kanan 5 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(56, 18, 26);
    glVertex3i(68, 18, 26);
    glVertex3i(68, 0, 26);
    glVertex3i(56, 0, 26);
    glEnd();
    //Sayap Kanan 5 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(56, 18, 34);
    glVertex3i(68, 18, 34);
    glVertex3i(68, 0, 34);
    glVertex3i(56, 0, 34);
    glEnd();
    //Sayap Kanan 5 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(56, 18, 34);
    glVertex3i(56, 18, 26);
    glVertex3i(68, 18, 26);
    glVertex3i(68, 18, 34);
    glEnd();
    //Garis Kanan 5
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(56, 0, 26);
    glVertex3i(56, 18, 26);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(56, 0, 34);
    glVertex3i(56, 18, 34);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(68, 0, 34);
    glVertex3i(68, 18, 34);
    glEnd();

    //Sayap Kanan 6 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(56, 18, -26);
    glVertex3i(68, 18, -26);
    glVertex3i(68, 0, -26);
    glVertex3i(56, 0, -26);
    glEnd();
    //Sayap Kanan 6 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(56, 18, -34);
    glVertex3i(68, 18, -34);
    glVertex3i(68, 0, -34);
    glVertex3i(56, 0, -34);
    glEnd();
    //Sayap Kanan 6 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(56, 18, -34);
    glVertex3i(56, 18, -26);
    glVertex3i(68, 18, -26);
    glVertex3i(68, 18, -34);
    glEnd();
    //Garis Kanan 6
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(56, 0, -26);
    glVertex3i(56, 18, -26);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(56, 0, -34);
    glVertex3i(56, 18, -34);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(68, 0, -34);
    glVertex3i(68, 18, -34);
    glEnd();

    //Sayap Kanan 7 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(68, 18, -38);
    glVertex3i(68, 18, -26);
    glVertex3i(68, 0, -26);
    glVertex3i(68, 0, -38);
    glEnd();
    //Sayap Kanan 7 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(76, 18, -38);
    glVertex3i(76, 18, -26);
    glVertex3i(76, 0, -26);
    glVertex3i(76, 0, -38);
    glEnd();
    //Sayap Kanan 7 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(68, 18, -26);
    glVertex3i(76, 18, -26);
    glVertex3i(76, 0, -26);
    glVertex3i(68, 0, -26);
    glEnd();
    //Sayap Kanan 7 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(68, 18, -26);
    glVertex3i(76, 18, -26);
    glVertex3i(76, 18, -38);
    glVertex3i(68, 18, -38);
    glEnd();
    //Garis Kanan 7
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(76, 0, -26);
    glVertex3i(76, 18, -26);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(76, 0, -38);
    glVertex3i(76, 18, -38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(68, 0, -38);
    glVertex3i(68, 18, -38);
    glEnd();

    //Sayap Kanan 8 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(68, 18, 38);
    glVertex3i(68, 18, 26);
    glVertex3i(68, 0, 26);
    glVertex3i(68, 0, 38);
    glEnd();
    //Sayap Kanan 8 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(76, 18, 38);
    glVertex3i(76, 18, 26);
    glVertex3i(76, 0, 26);
    glVertex3i(76, 0, 38);
    glEnd();
    //Sayap Kanan 8 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(68, 18, 26);
    glVertex3i(76, 18, 26);
    glVertex3i(76, 0, 26);
    glVertex3i(68, 0, 26);
    glEnd();
    //Sayap Kanan 8 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(68, 18, 26);
    glVertex3i(76, 18, 26);
    glVertex3i(76, 18, 38);
    glVertex3i(68, 18, 38);
    glEnd();
    //Garis Kanan 8
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(76, 0, 26);
    glVertex3i(76, 18, 26);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(76, 0, 38);
    glVertex3i(76, 18, 38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(68, 0, 38);
    glVertex3i(68, 18, 38);
    glEnd();

    //Sayap Kanan 9 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(66, 18, -38);
    glVertex3i(90, 18, -38);
    glVertex3i(90, 0, -38);
    glVertex3i(66, 0, -38);
    glEnd();
    //Sayap Kanan 9 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(66, 18, -44);
    glVertex3i(90, 18, -44);
    glVertex3i(90, 0, -44);
    glVertex3i(66, 0, -44);
    glEnd();
    //Sayap Kanan 9 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(66, 18, -38);
    glVertex3i(66, 18, -44);
    glVertex3i(66, 0, -44);
    glVertex3i(66, 0, -38);
    glEnd();
    //Sayap Kanan 9 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(90, 18, -44);
    glVertex3i(90, 18, -38);
    glVertex3i(90, 0, -38);
    glVertex3i(90, 0, -44);
    glEnd();
    //Sayap Kanan 9 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(66, 18, -44);
    glVertex3i(66, 18, -38);
    glVertex3i(90, 18, -38);
    glVertex3i(90, 18, -44);
    glEnd();
    //Garis Kanan 9
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(66, 0, -38);
    glVertex3i(66, 18, -38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(66, 0, -44);
    glVertex3i(66, 18, -44);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(90, 0, -38);
    glVertex3i(90, 18, -38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(90, 0, -44);
    glVertex3i(90, 18, -44);
    glEnd();

    //Jendela Sayap kanan 9 tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 1; j < 26; j++) {
        glPushMatrix();
        glTranslatef(0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 4; i++) {
            glPushMatrix();
            glTranslatef(0, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(66, 16, -44.1);
            glVertex3f(66.60, 16, -44.1);
            glVertex3f(66.60, 14, -44.1);
            glVertex3f(66, 14, -44.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kanan 9 tembok 2
    glColor3f(0, 0, 0);
    for (j = 1; j < 26; j++) {
        glPushMatrix();
        glTranslatef(0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 4; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(66, 16, -44.1);
            glVertex3f(66.60, 16, -44.1);
            glVertex3f(66.60, 14, -44.1);
            glVertex3f(66, 14, -44.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(66.3, 16, -44.1);
            glVertex3f(66.3, 14, -44.1);
            glVertex3f(66, 15.5, -44.1);
            glVertex3f(66.60, 15.5, -44.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kanan 10 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(66, 18, 38);
    glVertex3i(90, 18, 38);
    glVertex3i(90, 0, 38);
    glVertex3i(66, 0, 38);
    glEnd();
    //Sayap Kanan 10 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(66, 18, 44);
    glVertex3i(90, 18, 44);
    glVertex3i(90, 0, 44);
    glVertex3i(66, 0, 44);
    glEnd();
    //Sayap Kanan 10 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(66, 18, 38);
    glVertex3i(66, 18, 44);
    glVertex3i(66, 0, 44);
    glVertex3i(66, 0, 38);
    glEnd();
    //Sayap Kanan 10 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(90, 18, 44);
    glVertex3i(90, 18, 38);
    glVertex3i(90, 0, 38);
    glVertex3i(90, 0, 44);
    glEnd();
    //Sayap Kanan 10 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(66, 18, 44);
    glVertex3i(66, 18, 38);
    glVertex3i(90, 18, 38);
    glVertex3i(90, 18, 44);
    glEnd();
    //Garis Kanan 10
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(66, 0, 38);
    glVertex3i(66, 18, 38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(66, 0, 44);
    glVertex3i(66, 18, 44);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(90, 0, 38);
    glVertex3i(90, 18, 38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(90, 0, 44);
    glVertex3i(90, 18, 44);
    glEnd();

    //Jendela Sayap kanan 10 tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 1; j < 26; j++) {
        glPushMatrix();
        glTranslatef(0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 4; i++) {
            glPushMatrix();
            glTranslatef(0, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(66, 16, 44.1);
            glVertex3f(66.60, 16, 44.1);
            glVertex3f(66.60, 14, 44.1);
            glVertex3f(66, 14, 44.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kanan 10 tembok 2
    glColor3f(0, 0, 0);
    for (j = 1; j < 26; j++) {
        glPushMatrix();
        glTranslatef(0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 4; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(66, 16, 44.1);
            glVertex3f(66.60, 16, 44.1);
            glVertex3f(66.60, 14, 44.1);
            glVertex3f(66, 14, 44.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(66.3, 16, 44.1);
            glVertex3f(66.3, 14, 44.1);
            glVertex3f(66, 15.5, 44.1);
            glVertex3f(66.60, 15.5, 44.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kanan 11 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(90, 18, -42);
    glVertex3i(94, 18, -42);
    glVertex3i(94, 0, -42);
    glVertex3i(90, 0, -42);
    glEnd();
    //Sayap Kanan 11 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(94, 18, -42);
    glVertex3i(94, 18, -40);
    glVertex3i(94, 0, -40);
    glVertex3i(94, 0, -42);
    glEnd();
    //Sayap Kanan 11 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(94, 18, -40);
    glVertex3i(90, 18, -40);
    glVertex3i(90, 0, -40);
    glVertex3i(94, 0, -40);
    glEnd();
    //Sayap Kanan 11 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(90, 18, -42);
    glVertex3i(90, 18, -40);
    glVertex3i(94, 18, -40);
    glVertex3i(94, 18, -42);
    glEnd();
    //Garis Kanan 11
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(90, 0, -40);
    glVertex3i(90, 18, -40);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(90, 0, -42);
    glVertex3i(90, 18, -42);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(94, 0, -40);
    glVertex3i(94, 18, -40);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(94, 0, -42);
    glVertex3i(94, 18, -42);
    glEnd();

    //Jendela Sayap kanan 11 tembok 1 Belakang
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 2; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(90, 16, -42.1);
            glVertex3f(90.60, 16, -42.1);
            glVertex3f(90.60, 14, -42.1);
            glVertex3f(90, 14, -42.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kanan 11 tembok 1 dalam
    glColor3f(0, 0, 0);
    for (j = 0; j < 2; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-90, 16, -42.1);
            glVertex3f(-90.60, 16, -42.1);
            glVertex3f(-90.60, 14, -42.1);
            glVertex3f(-90, 14, -42.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(90.3, 16, -42.1);
            glVertex3f(90.3, 14, -42.1);
            glVertex3f(90, 15.5, -42.1);
            glVertex3f(90.60, 15.5, -42.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kanan 11 tembok 3
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 2; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(90, 16, -39.9);
            glVertex3f(90.60, 16, -39.9);
            glVertex3f(90.60, 14, -39.9);
            glVertex3f(90, 14, -39.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kanan 11 tembok 3
    glColor3f(0, 0, 0);
    for (j = 0; j < 2; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(90, 16, -39.9);
            glVertex3f(90.60, 16, -39.9);
            glVertex3f(90.60, 14, -39.9);
            glVertex3f(90, 14, -39.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(90.3, 16, -39.9);
            glVertex3f(90.3, 14, -39.9);
            glVertex3f(90, 15.5, -39.9);
            glVertex3f(90.60, 15.5, -39.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kanan 12 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(90, 18, 42);
    glVertex3i(94, 18, 42);
    glVertex3i(94, 0, 42);
    glVertex3i(90, 0, 42);
    glEnd();
    //Sayap Kanan 12 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(94, 18, 42);
    glVertex3i(94, 18, 40);
    glVertex3i(94, 0, 40);
    glVertex3i(94, 0, 42);
    glEnd();
    //Sayap Kanan 12 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(94, 18, 40);
    glVertex3i(90, 18, 40);
    glVertex3i(90, 0, 40);
    glVertex3i(94, 0, 40);
    glEnd();
    //Sayap Kanan 12 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(90, 18, 42);
    glVertex3i(90, 18, 40);
    glVertex3i(94, 18, 40);
    glVertex3i(94, 18, 42);
    glEnd();
    //Garis Kanan 12
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(90, 0, 40);
    glVertex3i(90, 18, 40);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(90, 0, 42);
    glVertex3i(90, 18, 42);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(94, 0, 40);
    glVertex3i(94, 18, 40);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(94, 0, 42);
    glVertex3i(94, 18, 42);
    glEnd();

    //Jendela Sayap kanan 12 tembok 1
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 2; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(90, 16, 42.1);
            glVertex3f(90.60, 16, 42.1);
            glVertex3f(90.60, 14, 42.1);
            glVertex3f(90, 14, 42.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kanan 12 tembok 1
    glColor3f(0, 0, 0);
    for (j = 0; j < 2; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(90, 16, 42.1);
            glVertex3f(90.60, 16, 42.1);
            glVertex3f(90.60, 14, 42.1);
            glVertex3f(90, 14, 42.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(90.3, 16, 42.1);
            glVertex3f(90.3, 14, 42.1);
            glVertex3f(90, 15.5, 42.1);
            glVertex3f(90.60, 15.5, 42.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kanan 12 tembok 3 depan
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 2; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(90, 16, 39.9);
            glVertex3f(90.60, 16, 39.9);
            glVertex3f(90.60, 14, 39.9);
            glVertex3f(90, 14, 39.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kanan 12 tembok 3 depan
    glColor3f(0, 0, 0);
    for (j = 0; j < 2; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(90, 16, 39.9);
            glVertex3f(90.60, 16, 39.9);
            glVertex3f(90.60, 14, 39.9);
            glVertex3f(90, 14, 39.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(90.3, 16, 39.9);
            glVertex3f(90.3, 14, 39.9);
            glVertex3f(90, 15.5, 39.9);
            glVertex3f(90.60, 15.5, 39.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kanan 13 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(94, 22, -50);
    glVertex3i(94, 22, -32);
    glVertex3i(94, 0, -32);
    glVertex3i(94, 0, -50);
    glEnd();
    //Sayap Kanan 13 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(100, 22, -50);
    glVertex3i(100, 22, -32);
    glVertex3i(100, 0, -32);
    glVertex3i(100, 0, -50);
    glEnd();
    //Sayap Kanan 13 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(94, 22, -50);
    glVertex3i(100, 22, -50);
    glVertex3i(100, 0, -50);
    glVertex3i(94, 0, -50);
    glEnd();
    //Sayap Kanan 13 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(100, 22, -32);
    glVertex3i(94, 22, -32);
    glVertex3i(94, 0, -32);
    glVertex3i(100, 0, -32);
    glEnd();
    //Sayap Kanan 13 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(94, 22, -32);
    glVertex3i(100, 22, -32);
    glVertex3i(100, 22, -50);
    glVertex3i(94, 22, -50);
    glEnd();
    //Garis Kanan 13
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(94, 22, -32); glVertex3i(100, 22, -32);
    glVertex3i(100, 22, -32); glVertex3i(100, 22, -50);
    glVertex3i(100, 22, -50); glVertex3i(94, 22, -50);
    glVertex3i(94, 22, -50); glVertex3i(94, 22, -32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(94, 0, -32);
    glVertex3i(94, 22, -32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(100, 0, -32);
    glVertex3i(100, 22, -32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(94, 0, -50);
    glVertex3i(94, 22, -50);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(100, 0, -50);
    glVertex3i(100, 22, -50);
    glEnd();

    //Jendela Sayap kanan 13 tembok 3 belakang
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(4, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(94, 20, -50.1);
            glVertex3f(94.60, 20, -50.1);
            glVertex3f(94.60, 18, -50.1);
            glVertex3f(94, 18, -50.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kanan 13 tembok 3 belakang
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(4, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(94, 20, -50.1);
            glVertex3f(94.60, 20, -50.1);
            glVertex3f(94.60, 18, -50.1);
            glVertex3f(94, 18, -50.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(94.30, 20, -50.1);
            glVertex3f(94.30, 18, -50.1);
            glVertex3f(94, 19.5, -50.1);
            glVertex3f(94.60, 19.5, -50.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kanan 13 tembok 4 belakang
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(4, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(94, 20, -31.9);
            glVertex3f(94.60, 20, -31.9);
            glVertex3f(94.60, 18, -31.9);
            glVertex3f(94, 18, -31.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kanan 13 tembok 3 belakang
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(4, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(94, 20, -31.9);
            glVertex3f(94.60, 20, -31.9);
            glVertex3f(94.60, 18, -31.9);
            glVertex3f(94, 18, -31.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(94.30, 20, -31.9);
            glVertex3f(94.30, 18, -31.9);
            glVertex3f(94, 19.5, -31.9);
            glVertex3f(94.60, 19.5, -31.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Atas Sayap Kanan 13
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(95.5, 28, -34);
    glVertex3f(98.5, 28, -34);
    glVertex3f(98.5, 28, -48);
    glVertex3f(95.5, 28, -48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(95.5, 28, -34);
    glVertex3f(98.5, 28, -34);
    glVertex3f(98.5, 22, -34);
    glVertex3f(95.5, 22, -34);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(98.5, 28, -34);
    glVertex3f(98.5, 28, -48);
    glVertex3f(98.5, 22, -48);
    glVertex3f(98.5, 22, -34);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(98.5, 28, -48);
    glVertex3f(95.5, 28, -48);
    glVertex3f(95.5, 22, -48);
    glVertex3f(98.5, 22, -48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(95.5, 28, -48);
    glVertex3f(95.5, 28, -34);
    glVertex3f(95.5, 22, -34);
    glVertex3f(95.5, 22, -48);
    glEnd();
    //Garis Atas Kanan 13
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(95.5, 28, -34);
    glVertex3f(98.5, 28, -34);
    glVertex3f(98.5, 28, -48);
    glVertex3f(95.5, 28, -48);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(95.5, 28, -34);
    glVertex3f(98.5, 28, -34);
    glVertex3f(98.5, 22, -34);
    glVertex3f(95.5, 22, -34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(98.5, 28, -34);
    glVertex3f(98.5, 28, -48);
    glVertex3f(98.5, 22, -48);
    glVertex3f(98.5, 22, -34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(98.5, 28, -48);
    glVertex3f(95.5, 28, -48);
    glVertex3f(95.5, 22, -48);
    glVertex3f(98.5, 22, -48);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(95.5, 28, -48);
    glVertex3f(95.5, 28, -34);
    glVertex3f(95.5, 22, -34);
    glVertex3f(95.5, 22, -48);
    glEnd();

    //Sayap Kanan 14 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(94, 22, 50);
    glVertex3i(94, 22, 32);
    glVertex3i(94, 0, 32);
    glVertex3i(94, 0, 50);
    glEnd();
    //Sayap Kanan 14 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(100, 22, 50);
    glVertex3i(100, 22, 32);
    glVertex3i(100, 0, 32);
    glVertex3i(100, 0, 50);
    glEnd();
    //Sayap Kanan 14 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(94, 22, 50);
    glVertex3i(100, 22, 50);
    glVertex3i(100, 0, 50);
    glVertex3i(94, 0, 50);
    glEnd();
    //Sayap Kanan 14 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(100, 22, 32);
    glVertex3i(94, 22, 32);
    glVertex3i(94, 0, 32);
    glVertex3i(100, 0, 32);
    glEnd();
    //Sayap Kanan 14 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(94, 22, 32);
    glVertex3i(100, 22, 32);
    glVertex3i(100, 22, 50);
    glVertex3i(94, 22, 50);
    glEnd();
    //Garis Kanan 14
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(94, 22, 32); glVertex3i(100, 22, 32);
    glVertex3i(100, 22, 32); glVertex3i(100, 22, 50);
    glVertex3i(100, 22, 50); glVertex3i(94, 22, 50);
    glVertex3i(94, 22, 50); glVertex3i(94, 22, 32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(94, 0, 32);
    glVertex3i(94, 22, 32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(100, 0, 32);
    glVertex3i(100, 22, 32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(94, 0, 50);
    glVertex3i(94, 22, 50);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(100, 0, 50);
    glVertex3i(100, 22, 50);
    glEnd();

    //Jendela Sayap kanan 14 tembok 3 depan
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(4, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(94, 20, 50.1);
            glVertex3f(94.60, 20, 50.1);
            glVertex3f(94.60, 18, 50.1);
            glVertex3f(94, 18, 50.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kanan 14 tembok 3 depan
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(4, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(94, 20, 50.1);
            glVertex3f(94.60, 20, 50.1);
            glVertex3f(94.60, 18, 50.1);
            glVertex3f(94, 18, 50.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(94.30, 20, 50.1);
            glVertex3f(94.30, 18, 50.1);
            glVertex3f(94, 19.5, 50.1);
            glVertex3f(94.60, 19.5, 50.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kanan 14 tembok 4 depan
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(4, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(94, 20, 31.9);
            glVertex3f(94.60, 20, 31.9);
            glVertex3f(94.60, 18, 31.9);
            glVertex3f(94, 18, 31.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kanan 14 tembok 4 depan
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(4, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(94, 20, 31.9);
            glVertex3f(94.60, 20, 31.9);
            glVertex3f(94.60, 18, 31.9);
            glVertex3f(94, 18, 31.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(94.30, 20, 31.9);
            glVertex3f(94.30, 18, 31.9);
            glVertex3f(94, 19.5, 31.9);
            glVertex3f(94.60, 19.5, 31.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Atas Sayap Kanan 14
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(95.5, 28, 34);
    glVertex3f(98.5, 28, 34);
    glVertex3f(98.5, 28, 48);
    glVertex3f(95.5, 28, 48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(95.5, 28, 34);
    glVertex3f(98.5, 28, 34);
    glVertex3f(98.5, 22, 34);
    glVertex3f(95.5, 22, 34);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(98.5, 28, 34);
    glVertex3f(98.5, 28, 48);
    glVertex3f(98.5, 22, 48);
    glVertex3f(98.5, 22, 34);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(98.5, 28, 48);
    glVertex3f(95.5, 28, 48);
    glVertex3f(95.5, 22, 48);
    glVertex3f(98.5, 22, 48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(95.5, 28, 48);
    glVertex3f(95.5, 28, 34);
    glVertex3f(95.5, 22, 34);
    glVertex3f(95.5, 22, 48);
    glEnd();
    //Garis Atas Kanan 14
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(95.5, 28, 34);
    glVertex3f(98.5, 28, 34);
    glVertex3f(98.5, 28, 48);
    glVertex3f(95.5, 28, 48);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(95.5, 28, 34);
    glVertex3f(98.5, 28, 34);
    glVertex3f(98.5, 22, 34);
    glVertex3f(95.5, 22, 34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(98.5, 28, 34);
    glVertex3f(98.5, 28, 48);
    glVertex3f(98.5, 22, 48);
    glVertex3f(98.5, 22, 34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(98.5, 28, 48);
    glVertex3f(95.5, 28, 48);
    glVertex3f(95.5, 22, 48);
    glVertex3f(98.5, 22, 48);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(95.5, 28, 48);
    glVertex3f(95.5, 28, 34);
    glVertex3f(95.5, 22, 34);
    glVertex3f(95.5, 22, 48);
    glEnd();

    //Sayap Kiri Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-12, 28, 6);
    glVertex3i(-40, 28, 6);
    glVertex3i(-40, 0, 6);
    glVertex3i(-12, 0, 6);
    glEnd();
    //Sayap Kiri Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-12, 28, -6);
    glVertex3i(-40, 28, -6);
    glVertex3i(-40, 0, -6);
    glVertex3i(-12, 0, -6);
    glEnd();
    //Sayap Kiri Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-12, 28, -6);
    glVertex3i(-12, 28, 6);
    glVertex3i(-40, 28, 6);
    glVertex3i(-40, 28, -6);
    glEnd();
    //Garis Kiri 1
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 28, 6);
    glVertex3i(-40, 28, 6);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-6, 28, -6);
    glVertex3i(-40, 28, -6);
    glEnd();

    //Jendela Sayap kiri tembok 1
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-18, 26, 6.1);
            glVertex3f(-19, 26, 6.1);
            glVertex3f(-19, 23, 6.1);
            glVertex3f(-18, 23, 6.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kiri tembok 1
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-18, 26, 6.1);
            glVertex3f(-19, 26, 6.1);
            glVertex3f(-19, 23, 6.1);
            glVertex3f(-18, 23, 6.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-18.5, 26, 6.1);
            glVertex3f(-18.5, 23, 6.1);
            glVertex3f(-18, 25, 6.1);
            glVertex3f(-19, 25, 6.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kiri tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-18, 26, -6.1);
            glVertex3f(-19, 26, -6.1);
            glVertex3f(-19, 23, -6.1);
            glVertex3f(-18, 23, -6.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kiri tembok 2
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-18, 26, -6.1);
            glVertex3f(-19, 26, -6.1);
            glVertex3f(-19, 23, -6.1);
            glVertex3f(-18, 23, -6.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-18.5, 26, -6.1);
            glVertex3f(-18.5, 23, -6.1);
            glVertex3f(-18, 25, -6.1);
            glVertex3f(-19, 25, -6.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kiri 2 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-40, 28, -30);
    glVertex3i(-40, 28, 30);
    glVertex3i(-40, 0, 30);
    glVertex3i(-40, 0, -30);
    glEnd();
    //Sayap Kiri 2 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-50, 28, -30);
    glVertex3i(-50, 28, 30);
    glVertex3i(-50, 0, 30);
    glVertex3i(-50, 0, -30);
    glEnd();
    //Sayap Kiri 2 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-50, 28, 30);
    glVertex3i(-40, 28, 30);
    glVertex3i(-40, 0, 30);
    glVertex3i(-50, 0, 30);
    glEnd();
    //Sayap Kiri 2 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-40, 28, -30);
    glVertex3i(-50, 28, -30);
    glVertex3i(-50, 0, -30);
    glVertex3i(-40, 0, -30);
    glEnd();
    //Sayap Kiri 2 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-40, 28, 30);
    glVertex3i(-50, 28, 30);
    glVertex3i(-50, 28, -30);
    glVertex3i(-40, 28, -30);
    glEnd();
    //Garis Kiri 2
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-40, 28, 6); glVertex3i(-40, 28, 30);
    glVertex3i(-40, 28, 30); glVertex3i(-44, 28, 30);
    glVertex3i(-44, 28, 30); glVertex3i(-44, 28, 36);
    glVertex3i(-44, 28, 36); glVertex3i(-56, 28, 36);
    glVertex3i(-56, 28, 36); glVertex3i(-56, 28, 24);
    glVertex3i(-56, 28, 24); glVertex3i(-50, 28, 24);
    glVertex3i(-50, 28, 24); glVertex3i(-50, 28, -24);
    glVertex3i(-50, 28, -24); glVertex3i(-56, 28, -24);
    glVertex3i(-56, 28, -24); glVertex3i(-56, 28, -36);
    glVertex3i(-56, 28, -36); glVertex3i(-44, 28, -36);
    glVertex3i(-44, 28, -36); glVertex3i(-44, 28, -30);
    glVertex3i(-44, 28, -30); glVertex3i(-40, 28, -30);
    glVertex3i(-40, 28, -6); glVertex3i(-40, 28, -30);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-40, 0, 6);
    glVertex3i(-40, 28, 6);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-40, 0, -6);
    glVertex3i(-40, 28, -6);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-40, 0, 30);
    glVertex3i(-40, 28, 30);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-40, 0, -30);
    glVertex3i(-40, 28, -30);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-50, 0, 24);
    glVertex3i(-50, 28, 24);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-50, 0, -24);
    glVertex3i(-50, 28, -24);
    glEnd();

    //Jendela Sayap kiri tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-18, 26, -6.1);
            glVertex3f(-19, 26, -6.1);
            glVertex3f(-19, 23, -6.1);
            glVertex3f(-18, 23, -6.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kiri tembok
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-18, 26, -6.1);
            glVertex3f(-19, 26, -6.1);
            glVertex3f(-19, 23, -6.1);
            glVertex3f(-18, 23, -6.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-18.5, 26, -6.1);
            glVertex3f(-18.5, 23, -6.1);
            glVertex3f(-18, 25, -6.1);
            glVertex3f(-19, 25, -6.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kiri 2 tembok 1
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 26; j++) {
        glPushMatrix();
        glTranslatef(0, 0, 2.3 * j); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-39.9, 24, -28);
            glVertex3f(-39.9, 24, -28.90);
            glVertex3f(-39.9, 21, -28.90);
            glVertex3f(-39.9, 21, -28);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kiri 2 tembok 1
    glColor3f(0, 0, 0);
    for (j = 0; j < 26; j++) {
        glPushMatrix();
        glTranslatef(0, 0, 2.3 * j); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-39.9, 24, -28);
            glVertex3f(-39.9, 24, -28.90);
            glVertex3f(-39.9, 21, -28.90);
            glVertex3f(-39.9, 21, -28);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-39.9, 24, -28.45);
            glVertex3f(-39.9, 21, -28.45);
            glVertex3f(-39.9, 23, -28);
            glVertex3f(-39.9, 23, -28.90);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kiri 2 tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 26; j++) {
        glPushMatrix();
        glTranslatef(0, 0, 2.3 * j); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-50.1, 24, -28);
            glVertex3f(-50.1, 24, -28.90);
            glVertex3f(-50.1, 21, -28.90);
            glVertex3f(-50.1, 21, -28);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kiri 2 tembok 2
    glColor3f(0, 0, 0);
    for (j = 0; j < 26; j++) {
        glPushMatrix();
        glTranslatef(0, 0, 2.3 * j); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-50.1, 24, -28);
            glVertex3f(-50.1, 24, -28.90);
            glVertex3f(-50.1, 21, -28.90);
            glVertex3f(-50.1, 21, -28);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-50.1, 24, -28.45);
            glVertex3f(-50.1, 21, -28.45);
            glVertex3f(-50.1, 23, -28);
            glVertex3f(-50.1, 23, -28.90);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kiri 3 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-44, 28, -24);
    glVertex3i(-56, 28, -24);
    glVertex3i(-56, 28, -36);
    glVertex3i(-44, 28, -36);
    glEnd();
    //Sayap Kiri 3 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-44, 28, -36);
    glVertex3i(-44, 28, -24);
    glVertex3i(-44, 0, -24);
    glVertex3i(-44, 0, -36);
    glEnd();
    //Sayap Kiri 3 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-44, 28, -36);
    glVertex3i(-56, 28, -36);
    glVertex3i(-56, 0, -36);
    glVertex3i(-44, 0, -36);
    glEnd();
    //Sayap Kiri 3 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-44, 28, -24);
    glVertex3i(-56, 28, -24);
    glVertex3i(-56, 0, -24);
    glVertex3i(-44, 0, -24);
    glEnd();
    //Sayap Kiri 3 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-56, 28, -24);
    glVertex3i(-56, 28, -36);
    glVertex3i(-56, 0, -36);
    glVertex3i(-56, 0, -24);
    glEnd();
    //Garis Kiri 3
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-44, 0, -30);
    glVertex3i(-44, 28, -30);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-44, 0, -36);
    glVertex3i(-44, 28, -36);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-56, 0, -36);
    glVertex3i(-56, 28, -36);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-56, 0, -24);
    glVertex3i(-56, 28, -24);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-50, 0, -24);
    glVertex3i(-50, 28, -24);
    glEnd();

    //Jendela Sayap kiri 3 tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(-1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(-1, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-45, 26, -36.1);
            glVertex3f(-45.60, 26, -36.1);
            glVertex3f(-45.60, 23, -36.1);
            glVertex3f(-45, 23, -36.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kiri 3 tembok 2
    glColor3f(0, 0, 0);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(-1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(-1, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-45, 26, -36.1);
            glVertex3f(-45.60, 26, -36.1);
            glVertex3f(-45.60, 23, -36.1);
            glVertex3f(-45, 23, -36.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-45.30, 26, -36.1);
            glVertex3f(-45.30, 23, -36.1);
            glVertex3f(-45, 25, -36.1);
            glVertex3f(-45.60, 25, -36.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kanan 3 tembok 3
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(-1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(-1, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-45, 26, -23.9);
            glVertex3f(-45.60, 26, -23.9);
            glVertex3f(-45.60, 23, -23.9);
            glVertex3f(-45, 23, -23.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kiri 3 tembok 3
    glColor3f(0, 0, 0);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(-1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(-1, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-45, 26, -23.9);
            glVertex3f(-45.60, 26, -23.9);
            glVertex3f(-45.60, 23, -23.9);
            glVertex3f(-45, 23, -23.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-45.30, 26, -23.9);
            glVertex3f(-45.30, 23, -23.9);
            glVertex3f(-45, 25, -23.9);
            glVertex3f(-45.60, 25, -23.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Atas Sayap Kiri 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-47, 38, -27);
    glVertex3i(-53, 38, -27);
    glVertex3i(-53, 38, -33);
    glVertex3i(-47, 38, -33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-47, 38, -33);
    glVertex3i(-47, 38, -27);
    glVertex3i(-47, 28, -27);
    glVertex3i(-47, 28, -33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-47, 38, -33);
    glVertex3i(-53, 38, -33);
    glVertex3i(-53, 28, -33);
    glVertex3i(-47, 28, -33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-47, 38, -27);
    glVertex3i(-53, 38, -27);
    glVertex3i(-53, 28, -27);
    glVertex3i(-47, 28, -27);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-53, 38, -27);
    glVertex3i(-53, 38, -33);
    glVertex3i(-53, 28, -33);
    glVertex3i(-53, 28, -27);
    glEnd();
    //Garis Atas Sayap Kiri 3
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-47, 38, -27);
    glVertex3i(-53, 38, -27);
    glVertex3i(-53, 38, -33);
    glVertex3i(-47, 38, -33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-47, 38, -33);
    glVertex3i(-47, 38, -27);
    glVertex3i(-47, 28, -27);
    glVertex3i(-47, 28, -33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-47, 38, -33);
    glVertex3i(-53, 38, -33);
    glVertex3i(-53, 28, -33);
    glVertex3i(-47, 28, -33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-47, 38, -27);
    glVertex3i(-53, 38, -27);
    glVertex3i(-53, 28, -27);
    glVertex3i(-47, 28, -27);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-53, 38, -27);
    glVertex3i(-53, 38, -33);
    glVertex3i(-53, 28, -33);
    glVertex3i(-53, 28, -27);
    glEnd();

    //Sayap Kiri 4 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-44, 28, 24);
    glVertex3i(-56, 28, 24);
    glVertex3i(-56, 28, 36);
    glVertex3i(-44, 28, 36);
    glEnd();
    //Sayap Kiri 4 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-44, 28, 36);
    glVertex3i(-44, 28, 24);
    glVertex3i(-44, 0, 24);
    glVertex3i(-44, 0, 36);
    glEnd();
    //Sayap Kiri 4 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-44, 28, 36);
    glVertex3i(-56, 28, 36);
    glVertex3i(-56, 0, 36);
    glVertex3i(-44, 0, 36);
    glEnd();
    //Sayap Kiri 4 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-44, 28, 24);
    glVertex3i(-56, 28, 24);
    glVertex3i(-56, 0, 24);
    glVertex3i(-44, 0, 24);
    glEnd();
    //Sayap Kiri 4 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-56, 28, 24);
    glVertex3i(-56, 28, 36);
    glVertex3i(-56, 0, 36);
    glVertex3i(-56, 0, 24);
    glEnd();
    //Garis Kiri 4
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-44, 0, 30);
    glVertex3i(-44, 28, 30);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-44, 0, 36);
    glVertex3i(-44, 28, 36);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-56, 0, 36);
    glVertex3i(-56, 28, 36);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-56, 0, 24);
    glVertex3i(-56, 28, 24);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-50, 0, 24);
    glVertex3i(-50, 28, 24);
    glEnd();

    //Jendela Sayap kiri 4 tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(-1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(-1, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-45, 26, 36.1);
            glVertex3f(-45.60, 26, 36.1);
            glVertex3f(-45.60, 23, 36.1);
            glVertex3f(-45, 23, 36.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kiri 4 tembok 2
    glColor3f(0, 0, 0);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(-1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(-1, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-45, 26, 36.1);
            glVertex3f(-45.60, 26, 36.1);
            glVertex3f(-45.60, 23, 36.1);
            glVertex3f(-45, 23, 36.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-45.30, 26, 36.1);
            glVertex3f(-45.30, 23, 36.1);
            glVertex3f(-45, 25, 36.1);
            glVertex3f(-45.60, 25, 36.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kiri 4 tembok 3
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(-1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(-1, -4 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-45, 26, 23.9);
            glVertex3f(-45.60, 26, 23.9);
            glVertex3f(-45.60, 23, 23.9);
            glVertex3f(-45, 23, 23.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela sayap kiri 4 tembok 3
    glColor3f(0, 0, 0);
    for (j = 0; j < 7; j++) {
        glPushMatrix();
        glTranslatef(-1.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(-1, -4 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-45, 26, 23.9);
            glVertex3f(-45.60, 26, 23.9);
            glVertex3f(-45.60, 23, 23.9);
            glVertex3f(-45, 23, 23.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-45.30, 26, 23.9);
            glVertex3f(-45.30, 23, 23.9);
            glVertex3f(-45, 25, 23.9);
            glVertex3f(-45.60, 25, 23.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Atas Sayap Kiri 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-47, 38, 27);
    glVertex3i(-53, 38, 27);
    glVertex3i(-53, 38, 33);
    glVertex3i(-47, 38, 33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-47, 38, 33);
    glVertex3i(-47, 38, 27);
    glVertex3i(-47, 28, 27);
    glVertex3i(-47, 28, 33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-47, 38, 33);
    glVertex3i(-53, 38, 33);
    glVertex3i(-53, 28, 33);
    glVertex3i(-47, 28, 33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-47, 38, 27);
    glVertex3i(-53, 38, 27);
    glVertex3i(-53, 28, 27);
    glVertex3i(-47, 28, 27);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-53, 38, 27);
    glVertex3i(-53, 38, 33);
    glVertex3i(-53, 28, 33);
    glVertex3i(-53, 28, 27);
    glEnd();
    //Garis Atas Sayap Kiri 4
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-47, 38, 27);
    glVertex3i(-53, 38, 27);
    glVertex3i(-53, 38, 33);
    glVertex3i(-47, 38, 33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-47, 38, 33);
    glVertex3i(-47, 38, 27);
    glVertex3i(-47, 28, 27);
    glVertex3i(-47, 28, 33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-47, 38, 33);
    glVertex3i(-53, 38, 33);
    glVertex3i(-53, 28, 33);
    glVertex3i(-47, 28, 33);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-47, 38, 27);
    glVertex3i(-53, 38, 27);
    glVertex3i(-53, 28, 27);
    glVertex3i(-47, 28, 27);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-53, 38, 27);
    glVertex3i(-53, 38, 33);
    glVertex3i(-53, 28, 33);
    glVertex3i(-53, 28, 27);
    glEnd();

    //Garis Sayap Kiri 5-12
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-56, 18, 26); glVertex3i(-76, 18, 26);
    glVertex3i(-76, 18, 26); glVertex3i(-76, 18, 38);
    glVertex3i(-76, 18, 38); glVertex3i(-90, 18, 38);
    glVertex3i(-90, 18, 38); glVertex3i(-90, 18, 40);
    glVertex3i(-90, 18, 40); glVertex3i(-94, 18, 40);
    glVertex3i(-94, 18, 40); glVertex3i(-94, 18, 42);
    glVertex3i(-94, 18, 42); glVertex3i(-90, 18, 42);
    glVertex3i(-90, 18, 42); glVertex3i(-90, 18, 44);
    glVertex3i(-90, 18, 44); glVertex3i(-66, 18, 44);
    glVertex3i(-66, 18, 44); glVertex3i(-66, 18, 38);
    glVertex3i(-66, 18, 38); glVertex3i(-68, 18, 38);
    glVertex3i(-68, 18, 38); glVertex3i(-68, 18, 34);
    glVertex3i(-68, 18, 34); glVertex3i(-56, 18, 34);
    glVertex3i(-56, 18, 34); glVertex3i(-56, 18, 26);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-56, 18, -26); glVertex3i(-76, 18, -26);
    glVertex3i(-76, 18, -26); glVertex3i(-76, 18, -38);
    glVertex3i(-76, 18, -38); glVertex3i(-90, 18, -38);
    glVertex3i(-90, 18, -38); glVertex3i(-90, 18, -40);
    glVertex3i(-90, 18, -40); glVertex3i(-94, 18, -40);
    glVertex3i(-94, 18, -40); glVertex3i(-94, 18, -42);
    glVertex3i(-94, 18, -42); glVertex3i(-90, 18, -42);
    glVertex3i(-90, 18, -42); glVertex3i(-90, 18, -44);
    glVertex3i(-90, 18, -44); glVertex3i(-66, 18, -44);
    glVertex3i(-66, 18, -44); glVertex3i(-66, 18, -38);
    glVertex3i(-66, 18, -38); glVertex3i(-68, 18, -38);
    glVertex3i(-68, 18, -38); glVertex3i(-68, 18, -34);
    glVertex3i(-68, 18, -34); glVertex3i(-56, 18, -34);
    glVertex3i(-56, 18, -34); glVertex3i(-56, 18, -26);
    glEnd();

    //Sayap Kiri 5 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-56, 18, 26);
    glVertex3i(-68, 18, 26);
    glVertex3i(-68, 0, 26);
    glVertex3i(-56, 0, 26);
    glEnd();
    //Sayap Kiri 5 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-56, 18, 34);
    glVertex3i(-68, 18, 34);
    glVertex3i(-68, 0, 34);
    glVertex3i(-56, 0, 34);
    glEnd();
    //Sayap Kiri 5 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-56, 18, 34);
    glVertex3i(-56, 18, 26);
    glVertex3i(-68, 18, 26);
    glVertex3i(-68, 18, 34);
    glEnd();
    //Garis Kiri 5
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-56, 0, 26);
    glVertex3i(-56, 18, 26);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-56, 0, 34);
    glVertex3i(-56, 18, 34);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-68, 0, 34);
    glVertex3i(-68, 18, 34);
    glEnd();

    //Sayap Kiri 6 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-56, 18, -26);
    glVertex3i(-68, 18, -26);
    glVertex3i(-68, 0, -26);
    glVertex3i(-56, 0, -26);
    glEnd();
    //Sayap Kiri 6 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-56, 18, -34);
    glVertex3i(-68, 18, -34);
    glVertex3i(-68, 0, -34);
    glVertex3i(-56, 0, -34);
    glEnd();
    //Sayap Kiri 6 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-56, 18, -34);
    glVertex3i(-56, 18, -26);
    glVertex3i(-68, 18, -26);
    glVertex3i(-68, 18, -34);
    glEnd();
    //Garis Kiri 6
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-56, 0, -26);
    glVertex3i(-56, 18, -26);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-56, 0, -34);
    glVertex3i(-56, 18, -34);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-68, 0, -34);
    glVertex3i(-68, 18, -34);
    glEnd();

    //Sayap Kiri 7 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-68, 18, -38);
    glVertex3i(-68, 18, -26);
    glVertex3i(-68, 0, -26);
    glVertex3i(-68, 0, -38);
    glEnd();
    //Sayap Kiri 7 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-76, 18, -38);
    glVertex3i(-76, 18, -26);
    glVertex3i(-76, 0, -26);
    glVertex3i(-76, 0, -38);
    glEnd();
    //Sayap Kiri 7 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-68, 18, -26);
    glVertex3i(-76, 18, -26);
    glVertex3i(-76, 0, -26);
    glVertex3i(-68, 0, -26);
    glEnd();
    //Sayap Kiri 7 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-68, 18, -26);
    glVertex3i(-76, 18, -26);
    glVertex3i(-76, 18, -38);
    glVertex3i(-68, 18, -38);
    glEnd();
    //Garis Kiri 7
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-76, 0, -26);
    glVertex3i(-76, 18, -26);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-76, 0, -38);
    glVertex3i(-76, 18, -38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-68, 0, -38);
    glVertex3i(-68, 18, -38);
    glEnd();

    //Sayap Kiri 8 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-68, 18, 38);
    glVertex3i(-68, 18, 26);
    glVertex3i(-68, 0, 26);
    glVertex3i(-68, 0, 38);
    glEnd();
    //Sayap Kiri 8 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-76, 18, 38);
    glVertex3i(-76, 18, 26);
    glVertex3i(-76, 0, 26);
    glVertex3i(-76, 0, 38);
    glEnd();
    //Sayap Kiri 8 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-68, 18, 26);
    glVertex3i(-76, 18, 26);
    glVertex3i(-76, 0, 26);
    glVertex3i(-68, 0, 26);
    glEnd();
    //Sayap Kiri 8 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-68, 18, 26);
    glVertex3i(-76, 18, 26);
    glVertex3i(-76, 18, 38);
    glVertex3i(-68, 18, 38);
    glEnd();
    //Garis Kiri 8
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-76, 0, 26);
    glVertex3i(-76, 18, 26);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-76, 0, 38);
    glVertex3i(-76, 18, 38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-68, 0, 38);
    glVertex3i(-68, 18, 38);
    glEnd();

    //Sayap Kiri 9 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-66, 18, -38);
    glVertex3i(-90, 18, -38);
    glVertex3i(-90, 0, -38);
    glVertex3i(-66, 0, -38);
    glEnd();
    //Sayap Kiri 9 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-66, 18, -44);
    glVertex3i(-90, 18, -44);
    glVertex3i(-90, 0, -44);
    glVertex3i(-66, 0, -44);
    glEnd();
    //Sayap Kiri 9 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-66, 18, -38);
    glVertex3i(-66, 18, -44);
    glVertex3i(-66, 0, -44);
    glVertex3i(-66, 0, -38);
    glEnd();
    //Sayap Kiri 9 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-90, 18, -44);
    glVertex3i(-90, 18, -38);
    glVertex3i(-90, 0, -38);
    glVertex3i(-90, 0, -44);
    glEnd();
    //Sayap Kiri 9 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-66, 18, -44);
    glVertex3i(-66, 18, -38);
    glVertex3i(-90, 18, -38);
    glVertex3i(-90, 18, -44);
    glEnd();
    //Garis Kiri 9
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-66, 0, -38);
    glVertex3i(-66, 18, -38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-66, 0, -44);
    glVertex3i(-66, 18, -44);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-90, 0, -38);
    glVertex3i(-90, 18, -38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-90, 0, -44);
    glVertex3i(-90, 18, -44);
    glEnd();

    //Jendela Sayap kiri 9 tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 1; j < 26; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 4; i++) {
            glPushMatrix();
            glTranslatef(0, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-66, 16, -44.1);
            glVertex3f(-66.60, 16, -44.1);
            glVertex3f(-66.60, 14, -44.1);
            glVertex3f(-66, 14, -44.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kiri 9 tembok 2
    glColor3f(0, 0, 0);
    for (j = 1; j < 26; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 4; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-66, 16, -44.1);
            glVertex3f(-66.60, 16, -44.1);
            glVertex3f(-66.60, 14, -44.1);
            glVertex3f(-66, 14, -44.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-66.3, 16, -44.1);
            glVertex3f(-66.3, 14, -44.1);
            glVertex3f(-66, 15.5, -44.1);
            glVertex3f(-66.60, 15.5, -44.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kiri 10 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-66, 18, 38);
    glVertex3i(-90, 18, 38);
    glVertex3i(-90, 0, 38);
    glVertex3i(-66, 0, 38);
    glEnd();
    //Sayap Kiri 10 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-66, 18, 44);
    glVertex3i(-90, 18, 44);
    glVertex3i(-90, 0, 44);
    glVertex3i(-66, 0, 44);
    glEnd();
    //Sayap Kiri 10 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-66, 18, 38);
    glVertex3i(-66, 18, 44);
    glVertex3i(-66, 0, 44);
    glVertex3i(-66, 0, 38);
    glEnd();
    //Sayap Kiri 10 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-90, 18, 44);
    glVertex3i(-90, 18, 38);
    glVertex3i(-90, 0, 38);
    glVertex3i(-90, 0, 44);
    glEnd();
    //Sayap Kiri 10 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-66, 18, 44);
    glVertex3i(-66, 18, 38);
    glVertex3i(-90, 18, 38);
    glVertex3i(-90, 18, 44);
    glEnd();
    //Garis Kiri 10
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-66, 0, 38);
    glVertex3i(-66, 18, 38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-66, 0, 44);
    glVertex3i(-66, 18, 44);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-90, 0, 38);
    glVertex3i(-90, 18, 38);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-90, 0, 44);
    glVertex3i(-90, 18, 44);
    glEnd();

    //Jendela Sayap kiri 10 tembok 2
    glColor3f(0.000, 0.749, 1.000);
    for (j = 1; j < 26; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 4; i++) {
            glPushMatrix();
            glTranslatef(0, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-66, 16, 44.1);
            glVertex3f(-66.60, 16, 44.1);
            glVertex3f(-66.60, 14, 44.1);
            glVertex3f(-66, 14, 44.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kiri 10 tembok 2
    glColor3f(0, 0, 0);
    for (j = 1; j < 26; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 4; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-66, 16, 44.1);
            glVertex3f(-66.60, 16, 44.1);
            glVertex3f(-66.60, 14, 44.1);
            glVertex3f(-66, 14, 44.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-66.3, 16, 44.1);
            glVertex3f(-66.3, 14, 44.1);
            glVertex3f(-66, 15.5, 44.1);
            glVertex3f(-66.60, 15.5, 44.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kiri 11 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-90, 18, -42);
    glVertex3i(-94, 18, -42);
    glVertex3i(-94, 0, -42);
    glVertex3i(-90, 0, -42);
    glEnd();
    //Sayap Kiri 11 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-94, 18, -42);
    glVertex3i(-94, 18, -40);
    glVertex3i(-94, 0, -40);
    glVertex3i(-94, 0, -42);
    glEnd();
    //Sayap Kiri 11 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-94, 18, -40);
    glVertex3i(-90, 18, -40);
    glVertex3i(-90, 0, -40);
    glVertex3i(-94, 0, -40);
    glEnd();
    //Sayap Kiri 11 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-90, 18, -42);
    glVertex3i(-90, 18, -40);
    glVertex3i(-94, 18, -40);
    glVertex3i(-94, 18, -42);
    glEnd();
    //Garis Kiri 11
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-90, 0, -40);
    glVertex3i(-90, 18, -40);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-90, 0, -42);
    glVertex3i(-90, 18, -42);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-94, 0, -40);
    glVertex3i(-94, 18, -40);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-94, 0, -42);
    glVertex3i(-94, 18, -42);
    glEnd();

    //Jendela Sayap kiri 11 tembok 1 Belakang
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-90, 16, -42.1);
            glVertex3f(-90.60, 16, -42.1);
            glVertex3f(-90.60, 14, -42.1);
            glVertex3f(-90, 14, -42.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kiri 11 tembok 1 dalam
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-90, 16, -42.1);
            glVertex3f(-90.60, 16, -42.1);
            glVertex3f(-90.60, 14, -42.1);
            glVertex3f(-90, 14, -42.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-90.3, 16, -42.1);
            glVertex3f(-90.3, 14, -42.1);
            glVertex3f(-90, 15.5, -42.1);
            glVertex3f(-90.60, 15.5, -42.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kiri 11 tembok 3
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-90, 16, -39.9);
            glVertex3f(-90.60, 16, -39.9);
            glVertex3f(-90.60, 14, -39.9);
            glVertex3f(-90, 14, -39.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kiri 11 tembok 3
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-90, 16, -39.9);
            glVertex3f(-90.60, 16, -39.9);
            glVertex3f(-90.60, 14, -39.9);
            glVertex3f(-90, 14, -39.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-90.3, 16, -39.9);
            glVertex3f(-90.3, 14, -39.9);
            glVertex3f(-90, 15.5, -39.9);
            glVertex3f(-90.60, 15.5, -39.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kiri 12 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-90, 18, 42);
    glVertex3i(-94, 18, 42);
    glVertex3i(-94, 0, 42);
    glVertex3i(-90, 0, 42);
    glEnd();
    //Sayap Kiri 12 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-94, 18, 42);
    glVertex3i(-94, 18, 40);
    glVertex3i(-94, 0, 40);
    glVertex3i(-94, 0, 42);
    glEnd();
    //Sayap Kiri 12 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-94, 18, 40);
    glVertex3i(-90, 18, 40);
    glVertex3i(-90, 0, 40);
    glVertex3i(-94, 0, 40);
    glEnd();
    //Sayap Kiri 12 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-90, 18, 42);
    glVertex3i(-90, 18, 40);
    glVertex3i(-94, 18, 40);
    glVertex3i(-94, 18, 42);
    glEnd();
    //Garis Kiri 12
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-90, 0, 40);
    glVertex3i(-90, 18, 40);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-90, 0, 42);
    glVertex3i(-90, 18, 42);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-94, 0, 40);
    glVertex3i(-94, 18, 40);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-94, 0, 42);
    glVertex3i(-94, 18, 42);
    glEnd();

    //Jendela Sayap kiri 12 tembok 1 depan
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-90, 16, 42.1);
            glVertex3f(-90.60, 16, 42.1);
            glVertex3f(-90.60, 14, 42.1);
            glVertex3f(-90, 14, 42.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kiri 12 tembok 1 depan
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-90, 16, 42.1);
            glVertex3f(-90.60, 16, 42.1);
            glVertex3f(-90.60, 14, 42.1);
            glVertex3f(-90, 14, 42.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(90.3, 16, 42.1);
            glVertex3f(90.3, 14, 42.1);
            glVertex3f(90, 15.5, 42.1);
            glVertex3f(90.60, 15.5, 42.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kiri 12 tembok 3 dalam
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-90, 16, 39.9);
            glVertex3f(-90.60, 16, 39.9);
            glVertex3f(-90.60, 14, 39.9);
            glVertex3f(-90, 14, 39.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kiri 12 tembok 3 dalam
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-1.7 * j, 0, 0); //Horizontal
        for (i = 0; i < 5; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(2.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-90, 16, 39.9);
            glVertex3f(-90.60, 16, 39.9);
            glVertex3f(-90.60, 14, 39.9);
            glVertex3f(-90, 14, 39.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-90.3, 16, 39.9);
            glVertex3f(-90.3, 14, 39.9);
            glVertex3f(-90, 15.5, 39.9);
            glVertex3f(-90.60, 15.5, 39.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kiri 13 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-94, 22, -50);
    glVertex3i(-94, 22, -32);
    glVertex3i(-94, 0, -32);
    glVertex3i(-94, 0, -50);
    glEnd();
    //Sayap Kiri 13 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-100, 22, -50);
    glVertex3i(-100, 22, -32);
    glVertex3i(-100, 0, -32);
    glVertex3i(-100, 0, -50);
    glEnd();
    //Sayap Kiri 13 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-94, 22, -50);
    glVertex3i(-100, 22, -50);
    glVertex3i(-100, 0, -50);
    glVertex3i(-94, 0, -50);
    glEnd();
    //Sayap Kiri 13 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-100, 22, -32);
    glVertex3i(-94, 22, -32);
    glVertex3i(-94, 0, -32);
    glVertex3i(-100, 0, -32);
    glEnd();
    //Sayap Kiri 13 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-94, 22, -32);
    glVertex3i(-100, 22, -32);
    glVertex3i(-100, 22, -50);
    glVertex3i(-94, 22, -50);
    glEnd();
    //Garis Kiri 13
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-94, 22, -32); glVertex3i(-100, 22, -32);
    glVertex3i(-100, 22, -32); glVertex3i(-100, 22, -50);
    glVertex3i(-100, 22, -50); glVertex3i(-94, 22, -50);
    glVertex3i(-94, 22, -50); glVertex3i(-94, 22, -32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-94, 0, -32);
    glVertex3i(-94, 22, -32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-100, 0, -32);
    glVertex3i(-100, 22, -32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-94, 0, -50);
    glVertex3i(-94, 22, -50);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-100, 0, -50);
    glVertex3i(-100, 22, -50);
    glEnd();

    //Atas Sayap Kiri 13
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-95.5, 28, -34);
    glVertex3f(-98.5, 28, -34);
    glVertex3f(-98.5, 28, -48);
    glVertex3f(-95.5, 28, -48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-95.5, 28, -34);
    glVertex3f(-98.5, 28, -34);
    glVertex3f(-98.5, 22, -34);
    glVertex3f(-95.5, 22, -34);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-98.5, 28, -34);
    glVertex3f(-98.5, 28, -48);
    glVertex3f(-98.5, 22, -48);
    glVertex3f(-98.5, 22, -34);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-98.5, 28, -48);
    glVertex3f(-95.5, 28, -48);
    glVertex3f(-95.5, 22, -48);
    glVertex3f(-98.5, 22, -48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-95.5, 28, -48);
    glVertex3f(-95.5, 28, -34);
    glVertex3f(-95.5, 22, -34);
    glVertex3f(-95.5, 22, -48);
    glEnd();
    //Garis Atas Kiri 13
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-95.5, 28, -34);
    glVertex3f(-98.5, 28, -34);
    glVertex3f(-98.5, 28, -48);
    glVertex3f(-95.5, 28, -48);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-95.5, 28, -34);
    glVertex3f(-98.5, 28, -34);
    glVertex3f(-98.5, 22, -34);
    glVertex3f(-95.5, 22, -34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-98.5, 28, -34);
    glVertex3f(-98.5, 28, -48);
    glVertex3f(-98.5, 22, -48);
    glVertex3f(-98.5, 22, -34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-98.5, 28, -48);
    glVertex3f(-95.5, 28, -48);
    glVertex3f(-95.5, 22, -48);
    glVertex3f(-98.5, 22, -48);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-95.5, 28, -48);
    glVertex3f(-95.5, 28, -34);
    glVertex3f(-95.5, 22, -34);
    glVertex3f(-95.5, 22, -48);
    glEnd();

    //Jendela Sayap kiri 14 tembok 3 depan
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(-1.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-94, 20, -50.1);
            glVertex3f(-94.60, 20, -50.1);
            glVertex3f(-94.60, 18, -50.1);
            glVertex3f(-94, 18, -50.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kiri 14 tembok 3 depan
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(-1.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-94, 20, -50.1);
            glVertex3f(-94.60, 20, -50.1);
            glVertex3f(-94.60, 18, -50.1);
            glVertex3f(-94, 18, -50.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-94.30, 20, -50.1);
            glVertex3f(-94.30, 18, -50.1);
            glVertex3f(-94, 19.5, -50.1);
            glVertex3f(-94.60, 19.5, -50.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kiri 13 tembok 4 belakang
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(-1.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-94, 20, -31.9);
            glVertex3f(-94.60, 20, -31.9);
            glVertex3f(-94.60, 18, -31.9);
            glVertex3f(-94, 18, -31.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kiri 13 tembok 4 belakang
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(-1.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-94, 20, -31.9);
            glVertex3f(-94.60, 20, -31.9);
            glVertex3f(-94.60, 18, -31.9);
            glVertex3f(-94, 18, -31.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-94.30, 20, -31.9);
            glVertex3f(-94.30, 18, -31.9);
            glVertex3f(-94, 19.5, -31.9);
            glVertex3f(-94.60, 19.5, -31.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Sayap Kiri 14 Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-94, 22, 50);
    glVertex3i(-94, 22, 32);
    glVertex3i(-94, 0, 32);
    glVertex3i(-94, 0, 50);
    glEnd();
    //Sayap Kiri 14 Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-100, 22, 50);
    glVertex3i(-100, 22, 32);
    glVertex3i(-100, 0, 32);
    glVertex3i(-100, 0, 50);
    glEnd();
    //Sayap Kiri 14 Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-94, 22, 50);
    glVertex3i(-100, 22, 50);
    glVertex3i(-100, 0, 50);
    glVertex3i(-94, 0, 50);
    glEnd();
    //Sayap Kiri 14 Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-100, 22, 32);
    glVertex3i(-94, 22, 32);
    glVertex3i(-94, 0, 32);
    glVertex3i(-100, 0, 32);
    glEnd();
    //Sayap Kiri 14 Atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-94, 22, 32);
    glVertex3i(-100, 22, 32);
    glVertex3i(-100, 22, 50);
    glVertex3i(-94, 22, 50);
    glEnd();
    //Garis Kiri 14
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-94, 22, 32); glVertex3i(-100, 22, 32);
    glVertex3i(-100, 22, 32); glVertex3i(-100, 22, 50);
    glVertex3i(-100, 22, 50); glVertex3i(-94, 22, 50);
    glVertex3i(-94, 22, 50); glVertex3i(-94, 22, 32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-94, 0, 32);
    glVertex3i(-94, 22, 32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-100, 0, 32);
    glVertex3i(-100, 22, 32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-94, 0, 50);
    glVertex3i(-94, 22, 50);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex3i(-100, 0, 50);
    glVertex3i(-100, 22, 50);
    glEnd();

    //Jendela Sayap kiri 14 tembok 3 depan
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(-1.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-94, 20, 50.1);
            glVertex3f(-94.60, 20, 50.1);
            glVertex3f(-94.60, 18, 50.1);
            glVertex3f(-94, 18, 50.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kiri 14 tembok 3 depan
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(-1.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-94, 20, 50.1);
            glVertex3f(-94.60, 20, 50.1);
            glVertex3f(-94.60, 18, 50.1);
            glVertex3f(-94, 18, 50.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-94.30, 20, 50.1);
            glVertex3f(-94.30, 18, 50.1);
            glVertex3f(-94, 19.5, 50.1);
            glVertex3f(-94.60, 19.5, 50.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Jendela Sayap kiri 14 tembok 4 depan
    glColor3f(0.000, 0.749, 1.000);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(-1.5, -3.1 * i, 0);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-94, 20, 31.9);
            glVertex3f(-94.60, 20, 31.9);
            glVertex3f(-94.60, 18, 31.9);
            glVertex3f(-94, 18, 31.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela Sayap kiri 14 tembok 4 depan
    glColor3f(0, 0, 0);
    for (j = 0; j < 4; j++) {
        glPushMatrix();
        glTranslatef(-0.90 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(-1.5, -3.1 * i, 0);//Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-94, 20, 31.9);
            glVertex3f(-94.60, 20, 31.9);
            glVertex3f(-94.60, 18, 31.9);
            glVertex3f(-94, 18, 31.9);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-94.30, 20, 31.9);
            glVertex3f(-94.30, 18, 31.9);
            glVertex3f(-94, 19.5, 31.9);
            glVertex3f(-94.60, 19.5, 31.9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Atas Sayap Kiri 14
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-95.5, 28, 34);
    glVertex3f(-98.5, 28, 34);
    glVertex3f(-98.5, 28, 48);
    glVertex3f(-95.5, 28, 48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-95.5, 28, 34);
    glVertex3f(-98.5, 28, 34);
    glVertex3f(-98.5, 22, 34);
    glVertex3f(-95.5, 22, 34);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-98.5, 28, 34);
    glVertex3f(-98.5, 28, 48);
    glVertex3f(-98.5, 22, 48);
    glVertex3f(-98.5, 22, 34);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-98.5, 28, 48);
    glVertex3f(-95.5, 28, 48);
    glVertex3f(-95.5, 22, 48);
    glVertex3f(-98.5, 22, 48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-95.5, 28, 48);
    glVertex3f(-95.5, 28, 34);
    glVertex3f(-95.5, 22, 34);
    glVertex3f(-95.5, 22, 48);
    glEnd();
    //Garis Atas Kiri 14
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-95.5, 28, 34);
    glVertex3f(-98.5, 28, 34);
    glVertex3f(-98.5, 28, 48);
    glVertex3f(-95.5, 28, 48);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-95.5, 28, 34);
    glVertex3f(-98.5, 28, 34);
    glVertex3f(-98.5, 22, 34);
    glVertex3f(-95.5, 22, 34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-98.5, 28, 34);
    glVertex3f(-98.5, 28, 48);
    glVertex3f(-98.5, 22, 48);
    glVertex3f(-98.5, 22, 34);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-98.5, 28, 48);
    glVertex3f(-95.5, 28, 48);
    glVertex3f(-95.5, 22, 48);
    glVertex3f(-98.5, 22, 48);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-95.5, 28, 48);
    glVertex3f(-95.5, 28, 34);
    glVertex3f(-95.5, 22, 34);
    glVertex3f(-95.5, 22, 48);
    glEnd();

    //Papan Tulis
    glBegin(GL_QUADS);
    glColor3ub(250,235,215);
    glVertex3f(-4, 8, -11.5);
    glVertex3f(4, 8,-11.5);
    glVertex3f(4, 3, -11.5);
    glVertex3f(-4, 3, -11.5);
    glEnd();
    //Bingkai Papan Tulis
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(139,69,19);
    glVertex3f(-4, 8, -11.5);
    glVertex3f(4, 8, -11.5);
    glVertex3f(4, 3, -11.5);
    glVertex3f(-4, 3, -11.5);
    glEnd();

    //Lemari
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 3, 4);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 3, -4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 3, 4);
    glVertex3i(8, 0, 4);
    glVertex3i(8, 0, -4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(8, 3, 4);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 0, 4);
    glVertex3i(8, 0, 4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 3, -4);
    glVertex3i(10, 0, -4);
    glVertex3i(10, 0, 4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(10, 3, -4);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 0, -4);
    glVertex3i(10, 0, -4);
    glEnd();
    //Garis Lemari
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 3, 4);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 3, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 3, 4);
    glVertex3i(8, 0, 4);
    glVertex3i(8, 0, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 3, 4);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 0, 4);
    glVertex3i(8, 0, 4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 3, -4);
    glVertex3i(10, 0, -4);
    glVertex3i(10, 0, 4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 3, -4);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 0, -4);
    glVertex3i(10, 0, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 0, -2);
    glVertex3i(8, 3, -2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 0, 0);
    glVertex3i(8, 3, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 0, 2);
    glVertex3i(8, 3, 2);
    glEnd();

    //Lemari 2
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 6, 4);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 6, -4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 6, 4);
    glVertex3i(-8, 0, 4);
    glVertex3i(-8, 0, -4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-8, 6, 4);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 0, 4);
    glVertex3i(-8, 0, 4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 6, -4);
    glVertex3i(-10, 0, -4);
    glVertex3i(-10, 0, 4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-10, 6, -4);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 0, -4);
    glVertex3i(-10, 0, -4);
    glEnd();
    //Garis Lemari
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 6, 4);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 6, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 6, 4);
    glVertex3i(-8, 0, 4);
    glVertex3i(-8, 0, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 6, 4);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 0, 4);
    glVertex3i(-8, 0, 4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 6, -4);
    glVertex3i(-10, 0, -4);
    glVertex3i(-10, 0, 4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 6, -4);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 0, -4);
    glVertex3i(-10, 0, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 0, -2);
    glVertex3i(-8, 6, -2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 0, 0);
    glVertex3i(-8, 6, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 0, 2);
    glVertex3i(-8, 6, 2);
    glEnd();

    //Meja
    //Kaki Meja 1
    glPushMatrix();
    glRotatef(-90.0, 0, -180.0, 0);
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(7, 2, -2);
    glVertex3i(5, 2, -2);
    glVertex3i(5, 0, -2);
    glVertex3i(7, 0, -2);
    glEnd();
    glPopMatrix();
    //Kaki Meja 2
    glPushMatrix();
    glRotatef(90.0, 0, -180.0, 0);
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-7, 2, -2);
    glVertex3i(-5, 2, -2);
    glVertex3i(-5, 0, -2);
    glVertex3i(-7, 0, -2);
    glEnd();
    glPopMatrix();
    //Alas Meja
    glBegin(GL_QUADS);
    glTranslatef(0, 0, 50.0);
    glColor3ub(47, 79, 79);
    glVertex3i(-2, 2, -7);
    glVertex3i(2, 2, -7);
    glVertex3i(2, 2, -5);
    glVertex3i(-2, 2, -5);
    glEnd();

    //Kursi
    //Kaki Belakang
    glBegin(GL_QUADS);;
    glColor3ub(160, 82, 45);
    glVertex3i(-0.5, 3, -3);
    glVertex3i(1, 3, -3);
    glVertex3i(1, 0, -3);
    glVertex3i(-0.5, 0, -3);
    glEnd();
    //Kaki Depan
    glBegin(GL_QUADS);;
    glColor3ub(160, 82, 45);
    glVertex3i(-0.5, 1.5, -4);
    glVertex3i(1, 1.5, -4);
    glVertex3i(1, 0, -4);
    glVertex3i(-0.5, 0, -4);
    glEnd();
    //Alas Kursi
    glBegin(GL_QUADS);
    glColor3ub(47,79,79);
    glVertex3i(0, 1.6, -4.5);
    glVertex3i(1, 1.6, -4.5);
    glVertex3i(1, 1.6, -3);
    glVertex3i(0, 1.6, -3);
    glEnd();

    //Kursi 2
    //Kaki Belakang
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(3.5, 3, -3);
    glVertex3i(4, 3, -3);
    glVertex3i(4, 0, -3);
    glVertex3i(3.5, 0, -3);
    glEnd();
    //Kaki Depan
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(3.5, 1.5, -4);
    glVertex3i(4, 1.5, -4);
    glVertex3i(4, 0, -4);
    glVertex3i(3.5, 0, -4);
    glEnd();
    //Alas Kursi
    glBegin(GL_QUADS);
    glColor3ub(47,79,79);
    glVertex3i(3, 1.6, -4.5);
    glVertex3i(4, 1.6, -4.5);
    glVertex3i(4, 1.6, -3);
    glVertex3i(3, 1.6, -3);
    glEnd();

    //Kursi 3
    //Kaki Belakang
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-3.5, 3, -3);
    glVertex3i(-2, 3, -3);
    glVertex3i(-2, 0, -3);
    glVertex3i(-3.5, 0, -3);
    glEnd();
    //Kaki Depan
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-3.5, 1.5, -4);
    glVertex3i(-2, 1.5, -4);
    glVertex3i(-2, 0, -4);
    glVertex3i(-3.5, 0, -4);
    glEnd();
    //Alas Kursi
    glBegin(GL_QUADS);
    glColor3ub(47,79,79);
    glVertex3i(-3, 1.6, -4.5);
    glVertex3i(-2, 1.6, -4.5);
    glVertex3i(-2, 1.6, -3);
    glVertex3i(-3, 1.6, -3);
    glEnd();

    //Laptop
    glBegin(GL_QUADS);
    glTranslatef(0, 0, 50.0);
    glColor3ub(0, 250, 154);
    glVertex3f(-0.5, 2.2, -6.6);
    glVertex3f(1.0, 2.2, -6.6);
    glVertex3f(1.0, 2, -5.5);
    glVertex3f(-0.5, 2, -5.5);
    glEnd();
    glBegin(GL_QUADS);
    glTranslatef(0, 0, 50.0);
    glColor3ub(0, 128, 128);
    glVertex3f(-0.5, 3, -7.3);
    glVertex3f(1.0, 3, -7.3);
    glVertex3f(1.0, 2, -6.4);
    glVertex3f(-0.5, 2, -6.4);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
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

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
        case 'A':
            glTranslatef(5.0, 0.0, 0.0);
            break;
        case 'd':
        case 'D':
            glTranslatef(-5.0, 0.0, 0.0);
            break;
        case 'w':
        case 'W':
            glTranslatef(0.0, 0.0, 5.0);
            break;
        case 's':
        case 'S':
            glTranslatef(0.0, 0.0, -5.0);
            break;
        case 'z':
        case 'Z':
            glTranslatef(0.0,3.0,0.0);
            break;
        case 'c':
        case 'C':
            glTranslatef(0.0,-3.0,0.0);
            break;
        case 'q':
        case 'Q':
            glRotatef(15, 0.0, 3.0, 0.0);
            break;
        case 'e':
        case 'E':
            glRotatef(15, 0.0, -3.0, 0.0);
            break;
        case '5':
            if (is_depth) {
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            } else {
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    Display();
}

void resize(int width, int height) {
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, width / height, 1.0, 600.0);
    glTranslatef(0.0, -10.0, -50.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Lomonosov Moscow State University di Rusia");
    Init();
    glutDisplayFunc(Display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
