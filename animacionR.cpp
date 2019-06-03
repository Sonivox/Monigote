//
// Created by fernando9825 on 06-02-19.
//

#include "animacionR.h"

float tx2 = 0.0f;    //X-axis translation varaible
float ty2 = 0.0f;    //Y-axis translation varaible
float giftTanslat2 = 0.0;  //Translation varaible for gift Box
float giftMov2 = 0.00575;   //Translation increament value (speed)
float Maxtx2 = 6.0f;
float forwardIncrmt2 = 0.0015f;
bool forwardTrans2 = false;
float backwardIncrmt2 = 0.0013f;        //backward movement speed
float maxTheta2 = 35.0f;                    //maximum rotation angle
float movTheta2 = 0.0f;
float incTheta2 = 1.5f;
bool forwardMov2 = false;
int timer2 = 30;
int counter2;
float Cx2 = 0.0f;
float Cincrmt2 = 0.03f;

void animacionPulsarR() {
    glPushMatrix();
    glTranslatef(1.0, 0.25, 0.0);
    glScalef(5.5, 1.0, 1.0);
    road2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.0f, 0.05f, 0.5f);
    glScalef(2.0f, 2.0f, 2.0f);
    front2();
    Door2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.45f, 0.02f, 0.5f);
    giftBoxMov2();
    giftBox2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.8f, -1.77f, 0.0f);
    glScalef(0.7, 0.7, 1.0);
    drawStickman2();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(3.0f, 0.05f, 0.5f);
    glScalef(2.0f, 2.0f, 2.0f);
    drawHouse2();
    logo2();
    glPopMatrix();

    //cloud2
    glPushMatrix();
    cloud2Mov2();
    think2();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-3.0, 3.0, 0.0);
    chopperMovement2();
    chopper2();
    ads2();
    glPopMatrix();

    roadMark2();
}

void circle2(float rad, float xx, float yy) {

    float thetha = 2 * 3.1415 / 20;
    float x, y;
    glColor3f(1.1, 1.1, 1.10);
    glLineWidth(1.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 20; i++) {
        x = rad * cos(i * thetha) + xx;
        y = rad * sin(i * thetha) + yy;
        float z = -5.0f;
        glVertex3f(x, y, z);
    }
    glEnd();
}

void head2() {
    circle2(0.08, -1.0f, 0.97f);

}

void print2(float x, float y, float z, char *string) {
    glRasterPos3f(x, y, z);
    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {

        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
}

void cloud2(float rad, float xx, float yy) {

    float thetha = 2 * 3.1415 / 20;
    float x, y;
    glColor3f(1.1, 1.1, 1.10);
    glLineWidth(1.0);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 20; i++) {
        x = rad * cos(i * thetha) + xx;
        y = rad * sin(i * thetha) + yy;
        float z = -5.0f;
        glVertex3f(x, y, z);
    }
    glEnd();
}


void think2() {
    glColor3f(1.1, 1.1, 1.1);
    cloud2(0.4, -0.90f, 0.97f);
    cloud2(0.4, -1.4f, 0.97f);
    cloud2(0.4, -2.0f, 0.97f);
    cloud2(0.4, -1.5f, 0.67f);
    cloud2(0.2, -1.3, 0.1);
    cloud2(0.1, -1.0, -0.1);
    cloud2(0.05, -0.8, -0.3);
    glColor3ub(25, 10, 91);

    const char *message = "     \xa8Ofertas?";
    print2(-2.4, 0.95, -5.0, const_cast<char *>(message));
    glRasterPos3f(-3.5, 1.5, -5.0);
}

void front2() {
    glColor3ub(153, 0, 76);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.7f, -1.5f, -5.0f);
    glVertex3f(0.1f, -1.5f, -5.0f);
    glVertex3f(0.1f, -0.5f, -5.0f);
    glVertex3f(-0.7f, -0.5f, -5.0f);
    glEnd();
}

void Door2() {
    //door
    glColor3ub(223, 255, 214);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.65f, -1.5f, -5.0f);
    glVertex3f(0.05f, -1.5f, -5.0f);
    glVertex3f(0.05f, -1.0f, -5.0f);
    glVertex3f(-0.65f, -1.0f, -5.0f);
    glEnd();
    glColor3f(0.80, 0.70, 0.60);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.65f, -1.5f, -5.0f);
    glVertex3f(-0.45f, -1.4f, -5.0f);
    glVertex3f(-0.45f, -1.1f, -5.0f);
    glVertex3f(-0.65f, -1.0f, -5.0f);
    glEnd();
    glColor3f(0.80, 0.70, 0.60);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(0.05f, -1.5f, -5.0f);
    glVertex3f(-0.15f, -1.4f, -5.0f);
    glVertex3f(-0.15f, -1.1f, -5.0f);
    glVertex3f(0.05f, -1.0f, -5.0f);
    glEnd();
}

void drawHouse2() {


    //side
    glColor3f(0.1, 0.1, 1.0);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(0.1f, -0.5f, -5.0f);
    glVertex3f(0.1f, -1.5, -5.0f);
    glVertex3f(1.5f, -1.5f, -5.0f);
    glVertex3f(1.5f, -0.5f, -5.0f);
    glEnd();

    //roof
    glLineWidth(5.0);
    glColor3ub(229.0, 229.0, 214.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.8f, -0.5f, -5.0f);
    glVertex3f(-0.3f, 0.5f, -5.0f);
    glVertex3f(0.10f, -0.5f, -5.0f);
    glEnd();
    //roof2
    glLineWidth(5.0);
    glColor3ub(98.0, 98.0, 8.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.3f, 0.5f, -5.0f);
    glVertex3f(0.15f, -0.6f, -5.0f);
    glVertex3f(1.60f, -0.6f, -5.0f);
    glVertex3f(1.10f, 0.5f, -5.0f);
    glEnd();



    //window1
    glColor3f(0.80, 0.70, 0.60);
    glBegin(GL_QUADS);
    glVertex3f(0.35, -0.8, -5.0);
    glVertex3f(0.35, -1.1, -5.0);
    glVertex3f(0.75, -1.1, -5.0);
    glVertex3f(0.75, -0.8, -5.0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.35, -0.8, -5.0);
    glVertex3f(0.75, -1.1, -5.0);
    glEnd();
    //window2
    glColor3f(0.80, 0.70, 0.60);
    glBegin(GL_QUADS);
    glVertex3f(0.85, -0.8, -5.0);
    glVertex3f(0.85, -1.1, -5.0);
    glVertex3f(1.25, -1.1, -5.0);
    glVertex3f(1.25, -0.8, -5.0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.85, -0.8, -5.0);
    glVertex3f(1.25, -1.1, -5.0);
    glEnd();
}

void giftBox2() {
    //giftBox2
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(0.15, -1.1, -5.0);
    glVertex3f(0.15, -1.2, -5.0);
    glVertex3f(0.25, -1.2, -5.0);
    glVertex3f(0.25, -1.1, -5.0);
    glEnd();

    glColor3f(1.0, 0.2, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(0.15, -1.1, -5.0);
    glVertex3f(0.2, -1.05, -5.0);
    glVertex3f(0.3, -1.05, -5.0);
    glVertex3f(0.25, -1.1, -5.0);
    glEnd();
    glColor3f(1.1, 0.1, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(0.25, -1.1, -5.0);
    glVertex3f(0.25, -1.2, -5.0);
    glVertex3f(0.3, -1.15, -5.0);
    glVertex3f(0.3, -1.05, -5.0);
    glEnd();


}

void road2() {
    glColor3ub(0, 0, 0);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(-1.5f, -1.8f, -5.0f);
    glVertex3f(-1.6f, -2.1f, -5.0f);
    glVertex3f(0.5f, -2.1f, -5.0f);
    glVertex3f(0.6f, -1.80f, -5.0f);
    glEnd();
}

//road2 mark(white)
void roadMark2() {

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(3.0);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(5, 0x1C47);  /*  draw dash/dot/dash lines  */
    drawOneLine(-5.95, -1.70, 5.50, -1.70);
    glDisable(GL_LINE_STIPPLE);
}

void neck() {
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.9f, -5.0f);
    glVertex3f(-1.0f, 0.8f, -5.0f);
    glEnd();
}

void body2() {
    glColor3f(0.1, 1.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.8f, -5.0f);
    glVertex3f(-1.0f, 0.5f, -5.0f);
    glEnd();
}

void leftHand2() {
    glColor3f(1.1, 1.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.8f, -5.0f);
    glVertex3f(-1.01f, 0.6f, -5.0f);
    glEnd();
}

void rightHand2() {
    glColor3f(1.1, 1.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.8f, -5.0f);
    glVertex3f(-0.99f, 0.6f, -5.0f);
    glEnd();
}

void leftArm2() {
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.01f, 0.6f, -5.0f);
    glVertex3f(-1.02f, 0.5f, -5.0f);
    glEnd();
}

void rightArm2() {
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-0.99f, 0.6f, -5.0f);
    glVertex3f(-0.98f, 0.5f, -5.0f);
    glEnd();
}

void leftLeg2() {
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.5f, -5.0f);
    glVertex3f(-1.01f, 0.4f, -5.0f);
    glEnd();
}

void rightLeg2() {
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.5f, -5.0f);
    glVertex3f(-0.99f, 0.4f, -5.0f);
    glEnd();
}

void leftShin2() {
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.4f, -5.0f);
    glVertex3f(-1.01f, 0.3f, -5.0f);
    glEnd();
}

void rightShine2() {
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.4f, -5.0f);
    glVertex3f(-0.99f, 0.3f, -5.0f);
    glEnd();
}

void drawEllipse(float radX, float radY) {
    int i;
    glColor3ub(24, 236, 66);
    glLineWidth(4.0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 360; i++) {
        float rad = i * (3.14159 / 180);
        glVertex3f(cos(rad) * radX, sin(rad) * radY, -5.0f);
    }
    glEnd();
}

void chopper2() {

    drawEllipse(1.0f, 0.5f);
    //centre line
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex3f(1.0f, 0.0f, -5.0f);
    glVertex3f(-0.30f, 0.0f, -5.0f);
    glEnd();
    //perpendicular line
    glBegin(GL_LINES);
    glVertex3f(-0.30f, 0.0f, -5.0f);
    glVertex3f(-0.30f, 0.5f, -5.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-1.0f, 0.1f, -5.0f);
    glVertex3f(-1.50f, 0.1f, -5.0f);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-1.0f, -0.1f, -5.0f);
    glVertex3f(-1.50f, -0.1f, -5.0f);
    glEnd();
    //wing stand
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(-0.1f, 0.5f, -5.0f);
    glVertex3f(-0.1f, 0.7f, -5.0f);
    glEnd();
    //wing
    glBegin(GL_LINES);
    glVertex3f(-0.6f, 0.7f, -5.0f);
    glVertex3f(0.4f, 0.7f, -5.0f);
    glEnd();

    //tail
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.5f, 0.1f, -5.0f);
    glVertex3f(-1.7f, 0.2f, -5.0f);
    glVertex3f(-1.7f, -0.2f, -5.0f);
    glVertex3f(-1.5f, -0.1f, -5.0f);
    glEnd();
    //banner-
    glBegin(GL_LINES);
    glVertex3f(-1.7f, 0.0f, -5.0f);
    glVertex3f(-2.1f, 0.0f, -5.0f);
    glEnd();
    //banner
    glColor3f(1.2, 1.2, 0.1);
    glLineWidth(2.0);

    glBegin(GL_LINE_LOOP);
    glVertex3f(-2.1f, 0.3f, -5.0f);
    glVertex3f(-4.8f, 0.3f, -5.0f);
    glVertex3f(-4.8f, -0.3f, -5.0f);
    glVertex3f(-2.1f, -0.3f, -5.0f);
    glEnd();

}

void ads2() {
    glColor3f(1.0, 0.0, 0.0);

    const char *message = "50% de descuento en FM";
    print2(-4.50, 0.0, -5.0, const_cast<char *>(message));

}

void logo2() {
    glColor3ub(10, 10, 9);
    const char *message = "Tienda FM";
    print2(-0.60, -0.3, -5.0, const_cast<char *>(message));
    glRasterPos3f(-0.75, 0.0, -5.0);
}

void chopperMovement2() {
    glTranslatef(Cx2, 0.0, 0.0);
    Cx2 = Cx2 + Cincrmt2;
    counter2++;
    if (Cx2 >= 15.5) {
        Cx2 = -6;
    }
}

void bodyMovement2() {
    if (counter2 <= 5500) {
        glTranslatef(tx2, 0.0, 0.0);
        tx2 = tx2 + forwardIncrmt2;
        counter2++;
    } else if (counter2 > 5500 && counter2 <= 9000) {
        glTranslatef(tx2, 0.0, 0.0);
        counter2++;
    } else if (counter2 > 9000 && counter2 <= 15000) {
        glTranslatef(tx2, 0.0, 0.0);
        tx2 = tx2 + forwardIncrmt2;
        counter2++;
    } else if (counter2 > 15000 && counter2 <= 16500) {
        glTranslatef(tx2, 0.0, 0.0);
        counter2++;

    } else {
        glTranslatef(tx2, 0.0, 0.0);
        tx2 = tx2 - backwardIncrmt2;
    }
}

void leftHandMovement2() {
    if (counter2 <= 5500) {
        glTranslatef(-1.0, 0.8, -5.0);
        glRotatef(movTheta2, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.8, 5.0);
    } else if (counter2 > 5500 && counter2 <= 9000) {
        glTranslatef(-1.0, 0.8, -5.0);
        glRotatef(-15, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.8, 5.0);
    } else if (counter2 > 9000 && counter2 <= 15000) {
        glTranslatef(-1.0, 0.8, -5.0);
        glRotatef(movTheta2, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.8, 5.0);
    } else if (counter2 > 15000) {
        glTranslatef(-1.0f, 0.8f, -5.0f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.0f, -0.8f, 5.0f);
    }
}

void rightHandMovement2() {
    if (counter2 <= 5500) {
        glTranslatef(-1.0f, 0.8f, -5.0f);
        glRotatef(-movTheta2, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.0f, -0.8f, 5.0f);
    } else if (counter2 > 5500 && counter2 <= 9000) {
        glTranslatef(-1.0, 0.8, -5.0);
        glRotatef(120, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.8, 5.0);
    } else if (counter2 > 9000 && counter2 <= 15000) {
        glTranslatef(-1.0f, 0.8f, -5.0f);
        glRotatef(-movTheta2, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.0f, -0.8f, 5.0f);
    } else if (counter2 > 15000) {
        glTranslatef(-1.0f, 0.8f, -5.0f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.0f, -0.8f, 5.0f);
    }
}

void leftArmMovement2() {
    if (counter2 <= 5500) {
        glTranslatef(-1.01f, 0.6f, -5.0f);
        glRotatef(-movTheta2, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.01f, -0.6f, 5.0f);
    } else if (counter2 > 5500 && counter2 <= 9000) {
        glTranslatef(-1.01f, 0.6f, -5.0f);
        glRotatef(15, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.01f, -0.6f, 5.0f);
    } else if (counter2 > 9000 && counter2 <= 15000) {
        glTranslatef(-1.01f, 0.6f, -5.0f);
        glRotatef(-movTheta2, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.01f, -0.6f, 5.0f);
    } else if (counter2 > 15000) {
        glTranslatef(-1.01f, 0.6f, -5.0f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.01f, -0.6f, 5.0f);
    }

}

void rightArmMovement2() {
    if (counter2 <= 5500) {
        glTranslatef(-0.99f, 0.6f, -5.0f);
        glRotatef(-movTheta2, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.99f, -0.6f, 5.0f);
    } else if (counter2 > 5500 && counter2 <= 7800) {

        glTranslatef(-0.99f, 0.6f, -5.0f);
        glRotatef(120, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.99f, -0.6f, 5.0f);

    } else if (counter2 > 7800 && counter2 <= 9000) {
        glTranslatef(-0.99f, 0.6f, -5.0f);
        glRotatef(180, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.99f, -0.6f, 5.0f);
    } else if (counter2 > 9000 && counter2 <= 15000) {
        glTranslatef(-0.99f, 0.6f, -5.0f);
        glRotatef(-movTheta2, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.99f, -0.6f, 5.0f);
    } else if (counter2 > 15000) {
        glTranslatef(-0.99f, 0.6f, -5.0f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.99f, -0.6f, 5.0f);

    }
}

void leftLegMovement2() {
    if (counter2 <= 5500) {
        glTranslatef(-1.0, 0.5, -5.0);
        glRotatef(-movTheta2, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.5, 5.0);
    } else if (counter2 > 5500 && counter2 <= 9000) {
        glTranslatef(-1.0, 0.5, -5.0);
        glRotatef(15, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.5, 5.0);
    } else {
        glTranslatef(-1.0, 0.5, -5.0);
        glRotatef(-movTheta2, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.5, 5.0);
    }
}

void rightLegMovement2() {
    if (counter2 <= 5500) {
        glTranslatef(-1.0f, 0.5f, -5.0f);
        glRotatef(movTheta2, 0.0, 0.0, 1.0);
        glTranslatef(1.0f, -0.5f, 5.0f);
    } else if (counter2 > 5500 && counter2 <= 9000) {
        glTranslatef(-1.0, 0.5, -5.0);
        glRotatef(-15, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.5, 5.0);
    } else {
        glTranslatef(-1.0f, 0.5f, -5.0f);
        glRotatef(movTheta2, 0.0, 0.0, 1.0);
        glTranslatef(1.0f, -0.5f, 5.0f);
    }
}

void giftBoxMov2() {
    if (counter2 < 16400) {
        glTranslatef(giftTanslat2, 0.0, 0.0);
        counter2++;
    } else {
        glTranslatef(giftTanslat2, 0.0, 0.0);
        giftTanslat2 = giftTanslat2 - giftMov2;
    }
}

void cloud2Mov2() {
    if (counter2 < 5500) {
        glTranslatef(15, 25, -5.0);

    } else if (counter2 > 5000 && counter2 <= 7800) {


        glTranslatef(-2.9, -0.80, 0.0);
        glScalef(0.4, 0.4, 1.0);


    } else {
        glTranslatef(-2.9, -0.80, 0.0);
        glTranslatef(0.0, ty2, 0.0);
        glScalef(0.4, 0.4, 1.0);
        ty2 = ty2 + 0.005;
    }
}


void angleTheta2() {
    if (forwardMov2) {
        movTheta2 += incTheta2;
        if (movTheta2 > maxTheta2)
            forwardMov2 = false;
    } else if (!forwardMov2) {
        movTheta2 -= incTheta2;
        if (movTheta2 < -maxTheta2)

            forwardMov2 = true;

    }
}


void drawStickman2() {
    //body
    glPushMatrix();
    bodyMovement2();
    body2();
    head2();
    neck();
    glPopMatrix();
    //leftHand
    glPushMatrix();
    bodyMovement2();
    leftHandMovement2();
    leftHand2();
    glPopMatrix();
    //leftArm
    glPushMatrix();
    bodyMovement2();
    leftHandMovement2();
    leftArmMovement2();
    leftArm2();
    glPopMatrix();


    //rightHand
    glPushMatrix();
    bodyMovement2();
    rightHandMovement2();
    rightHand2();
    glPopMatrix();

    //rightarm
    glPushMatrix();
    bodyMovement2();
    rightHandMovement2();
    rightArmMovement2();
    rightArm2();
    glPopMatrix();

    //leftLeg2()
    glPushMatrix();
    bodyMovement2();
    leftLegMovement2();
    leftLeg2();
    leftShin2();
    glPopMatrix();

    //rightLeg
    glPushMatrix();
    bodyMovement2();
    rightLegMovement2();
    rightLeg2();
    rightShine2();
    glPopMatrix();

    angleTheta2();

}