/*
    @autor: Marabely Alvarado Tenorio
    Dibujando un paisaje con OpenGL y C.
*/

#include<stdio.h>
#include<stdlib.h>
#include <glut.h>
#include<math.h>

GLfloat CoordX = 0.0; //COORDENADAS GENERALES
GLfloat CoordY = 0.0;

void teclasDireccionales(int key, int x, int y) {
    glutPostRedisplay();
    switch (key) {
    case GLUT_KEY_LEFT:
        CoordX -= 0.04;
        break;
    case GLUT_KEY_UP:
        CoordY += 0.04;
        break;
    case GLUT_KEY_DOWN:
        CoordY -= 0.04;
        break;
    }
}

float genRan() { //Generando coordenadas para las estrellas
    float rNUM = (-1) + (float)rand() / ((float)RAND_MAX / (1 - (-1)));
    return rNUM;
}

void dibujoSOL() {
    float PI = 3.1416;
    float formula = 2 * PI / 100;
    float radio = 0.2;
    glBegin(GL_POLYGON); //0.28, 0.50
    glColor3f(0.658824f, 0.658824f, 0.658824f); //lightgray
    for (float i = 0.0; i < 100; i++) {
        float x = -0.6 - (float)sin(i * formula) * radio;
        float y = 0.5 - (float)cos(i * formula) * radio;
        glVertex2f(x, y);
    }
    glEnd();
}

void dibujoMAR() {
    glBegin(GL_POLYGON); //MAR
    glColor3f(0.0f, 0.1f, 1.0f);//COLOR blue
    glVertex3f(1.0, -0.5, 0.0);
    glColor3f(0.74902f, 0.847059f, 0.847059); //color light blue
    glVertex3f(-1.0, -0.5, 0.0);
    glColor3f(0.196078f, 0.196078f, 0.8); //color mediumblue
    glVertex3f(-1.0, -1.0, 0.0);
    glColor3f(0.137255f, 0.137255f, 0.556863); //color navy blue
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
}

void dibujoDelfin() {
    // DELFIN
    glBegin(GL_POLYGON);
    glColor3f(0.419608, 0.137255, 0.556863); //darkslateblue
    glVertex2f(0.989, -0.966);
    glVertex2f(0.941, -0.96);
    glVertex2f(0.773, -0.946);
    glVertex2f(0.76, -0.94);
    glVertex2f(0.761, -0.935);
    glVertex2f(0.783, -0.93);
    glVertex2f(0.8, -0.91); //c2
    glVertex2f(0.85333, -0.8989); //b2
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);    //aletas del animal
    glColor3f(0.419608, 0.137255, 0.556863); //darkslateblue
    glVertex2f(0.989, -0.966);
    glVertex2f(0.941, -0.96);
    glVertex2f(0.96204, -0.954);
    glVertex2f(0.96, -0.915);
    glEnd();

    glBegin(GL_TRIANGLES); //ALETA 1RA
    glVertex2f(0.84506, -0.96762);
    glVertex2f(0.82115, -0.94654);
    glVertex2f(0.85333, -0.8989);
    glEnd();

    glBegin(GL_TRIANGLES); //ALETA arriba
    glVertex2f(0.84, -0.9);
    glVertex2f(0.86302, -0.87855);
    glVertex2f(0.86921, -0.90667);
    glEnd();

    glBegin(GL_POINTS); //Ojito
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(7);
    glVertex2f(0.807, -0.924);
    glEnd();
}

void Display(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //DIBUJANDO LAS ESTRELLAS
    glBegin(GL_POINTS);
    for (int i = 0; i < 2000; i++) {
        if (i % 2 == 0) { //par
            glColor3f(0.87, 0.58, 0.98);
            glPointSize(1);
        }
        else {//impar
            glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
            glPointSize(5);
        }
        glVertex2f(genRan(), genRan());
    }
    glEnd();

    dibujoSOL();
    dibujoMAR();

    float ejeX1 = -0.2, ejeY1 = 0.1, ejeX2copia = -0.1; //dibujando ventanas horizontales DEL 1 EDIFICIO
    glBegin(GL_QUADS);
    for (int i = 0; i < 25; i++) {
        if (i % 2 == 0) { //par
            glColor3f(0.36, 0.25, 0.20); //cafe oscuro
        }
        else {//impar
            glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
        }
        glVertex2f(ejeX1, ejeY1); //P1 X1, Y1
        glVertex2f(ejeX2copia, ejeY1); //P2 X2, Y1

        ejeY1 -= 0.02;
        glVertex2f(ejeX2copia, ejeY1); //P3 X2, Y2
        glVertex2f(ejeX1, ejeY1);//P4 X1, Y2
    }
    glEnd();

    //TERCER EDIFICIO  
    float ejeX1Q = -0.05, ejeY1Q = 0.23, ejeX2copiaQ = 0.33; //VENTANAS EN HORIZONTAL
    glBegin(GL_QUADS);
    //glColor3f(0.30, 0.30, 1.00);
    for (int i = 0; i < 30; i++) {
        if (i % 2 == 0) { //par
            glColor3f(0.52, 0.37, 0.26); //DARKWOOD
        }
        else {//impar
            glColor3f(0.439216f, 0.858824f, 0.576471); //aquamarine
        }
        glVertex2f(ejeX1Q, ejeY1Q); //P1 X1, Y1
        glVertex2f(ejeX2copiaQ, ejeY1Q); //P2 X2, Y1
        ejeY1Q -= 0.02;
        glVertex2f(ejeX2copiaQ, ejeY1Q); //P3 X2, Y2
        glVertex2f(ejeX1Q, ejeY1Q);//P4 X1, Y2
    }
    glEnd();

    float ejeX1V = -0.05, ejeY1V = 0.23, ejeY2copiaV = -0.47; // VENTANAS VERTICAL
    glBegin(GL_LINES);
    for (int i = 0; i < 18; i++) {
        if (i % 2 == 0) { //par
            glColor3f(0.52, 0.37, 0.26); //DARKWOOD
        }
        else {//impar
            glColor3f(0.439216f, 0.858824f, 0.576471); //aquamarine
        }
        glVertex2f(ejeX1V, ejeY1V); //P1 X1, Y1
        glVertex2f(ejeX1V, ejeY2copiaV);//P4 X1, Y2
        ejeX1V += 0.02;
        glVertex2f(ejeX1V, ejeY2copiaV); //P3 X2, Y2
        glVertex2f(ejeX1V, ejeY1V); //P2 X2, Y1
    }
    glEnd();

    //DIBUJANDO 2NDO EDIFICIO
    float ejeX1T = -0.08, ejeY1T = -0.1, ejeX2copiaT = -0.0137; //Y1 DEBE VARIAR DECREMENTAR EN 0.02
    glBegin(GL_QUADS);
    for (int i = 0; i < 20; i++) {
        if (i % 2 == 0) { //par
            glColor3f(0.35, 0.16, 0.14);
        }
        else {//impar
            glColor3f(1.0f, 0.5f, 1.0f);//baby Blue
        }
        glVertex2f(ejeX1T, ejeY1T); //P1 X1, Y1
        glVertex2f(ejeX2copiaT, ejeY1T); //P2 X2, Y1
        ejeY1T -= 0.02;
        glVertex2f(ejeX2copiaT, ejeY1T); //P3 X2, Y2
        glVertex2f(ejeX1T, ejeY1T);//P4 X1, Y2

    }
    glEnd();

    glBegin(GL_POLYGON); //MOUNTAIN
    glColor3f(0.0f, 0.1f, 0.0f);//Forest Green
    glVertex3f(-1.0, -0.5, 0.0);//inicio
    glVertex3f(-1, -0.26, 0.0);
    glVertex3f(-0.93, -0.3, 0.0);
    glVertex3f(-0.92, -0.33, 0.0);
    glVertex3f(-0.86, -0.34, 0.0);
    glVertex3f(-0.825, -0.40, 0.0);
    glVertex3f(-0.77, -0.407, 0.0);
    glVertex3f(-0.75, -0.437, 0.0);
    glVertex3f(-0.63, -0.31, 0.0);
    glVertex3f(-0.62, -0.35, 0.0);
    glVertex3f(-0.43, -0.18, 0.0);
    glVertex3f(-0.43, -0.18, 0.0);
    glVertex3f(-0.28, -0.24, 0.0);
    glVertex3f(-0.17, -0.42, 0.0);
    glVertex3f(-0.025, -0.465, 0.0);
    glVertex3f(0.151, -0.405, 0.0);
    glVertex3f(0.23, -0.34, 0.0);
    glVertex3f(0.277, -0.26, 0.0);
    glVertex3f(0.439, -0.36, 0.0);
    glVertex3f(0.47, -0.34, 0.0);
    glVertex3f(0.61, -0.46, 0.0);
    glVertex3f(0.76, -0.299, 0.0);
    glVertex3f(1.0, -0.45, 0.0);
    glVertex3f(1.0, -0.5, 0.0);
    glEnd();

    dibujoMAR();
    glLoadIdentity();
    glPushMatrix();
    glTranslated(CoordX, CoordY, 0.0);
   // dibujoDelfin();
    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Laboratorio 2nd PG");
    glutDisplayFunc(Display);
    glutSpecialFunc(teclasDireccionales);
    glutMainLoop();
}
