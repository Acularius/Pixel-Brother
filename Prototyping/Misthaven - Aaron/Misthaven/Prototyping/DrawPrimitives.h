#pragma once
#include "GL/glut.h"
#include <string>

/* 
*	-Convenience Functions to draw primitives in openGL
*	- Try to understand and modify them
*/

/* After calling this, the line is set to this width unless
* I call it again and give it a different value
*/
void setLineWidth(float width)
{
	glLineWidth(width);
}

/* sets the current colour to use when drawing anything afterwards */
void setColor(float red, float green, float blue)
{
	glColor3f(red,green,blue);
}

/* draws a line between two points in screen pixel values 
*(startX,startY) to (endX,endY) 
*/
void drawLine(float startX,float startY, float endX, float endY)
{
	glBegin(GL_LINES);
	glVertex3f(startX,startY,0);
	glVertex3f(endX,endY,0);
	glEnd();
}

void drawRectangle(bool filled, float cornerX, float cornerY, int width, int height, float theta)
{
	if(filled) glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	else glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glPushMatrix();
	glTranslatef(cornerX,cornerY,0);
	glRotatef(theta, 0,0,1);
	glBegin(GL_QUADS);
	glVertex3f(0,0,0);
	glVertex3f(0,height,0);
	glVertex3f(width, height,0);
	glVertex3f(width,0,0);
	glEnd();
	glPopMatrix();
}

void drawText(std::string s, float posX, float posY)
{
	glPushMatrix();
	glRasterPos2f(posX,posY);
	const char *text = s.c_str();
	for(int i=0;i<s.length();i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
	glPopMatrix();
}

void drawNum(int score, float posX, float posY)
{
	std::string s = std::to_string(score);
	glPushMatrix();
	glRasterPos2f(posX,posY);
	const char *text =s.c_str();
	for(int i=0;i<s.length();i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
	glPopMatrix();
}