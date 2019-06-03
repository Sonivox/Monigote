//
// Created by fernando9825 on 06-02-19.
//

#ifndef MONIGOTE_ANIMACIONR_H
#define MONIGOTE_ANIMACIONR_H

#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include "GL/glut.h"
#include<stdlib.h>
#include <cmath>
#include <string.h>

#define drawOneLine(x1, y1, x2, y2)  glBegin(GL_LINES);  \
   glVertex3f ((x1),(y1),(-5.0)); glVertex3f ((x2),(y2),(-5.0)); glEnd();   //draw...dotted line


static float zoomFactor2 = 1.0; /* Global, if you want. Modified by user input. Initially 1.0 */
/* A routine for setting the projection matrix. May be called from a resize event handler in a typical application.
 * Takes integer width and height dimensions of the drawing area.
 * Creates a projection matrix with correct aspect ratio and zoom factor. */

static float zNear2 = 1.0, zFar2 = 200.0;

// function to create stickyman scene with R button
void animacionPulsarS();

// dependencias
void road2();

void front2();

void Door2();

void giftBoxMov2();

void giftBox2();

void drawStickman2();

void drawHouse2();

void logo2();

void cloud2Mov2();

void think2();

void chopperMovement2();

void chopper2();

void ads2();

void roadMark2();


#endif //MONIGOTE_ANIMACIONR_H
