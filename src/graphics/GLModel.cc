/*******************************
*
GLModel.cc
OpenGL Model Source:
------------------------------
Author: Justin Petluk
*
*******************************/
#include "GLModel.h"

GLModel::GLModel(){}
//GLModel::~GLModel(){}

void GLModel::init(){
	glShadeModel(GL_SMOOTH);                        // shading mathod: GL_SMOOTH or GL_FLAT
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);          // 4-byte pixel alignment

	// enable /disable features
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	//glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	//glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	//glEnable(GL_TEXTURE_2D);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);

	// track material ambient and diffuse from surface color, call it before glEnable(GL_COLOR_MATERIAL)
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(0, 0, 0, 0);                       // background color
	glClearStencil(0);                              // clear stencil buffer
	glClearDepth(1.0f);                             // 0 is near, 1 is far
	glDepthFunc(GL_LEQUAL);

	initLights();
	setCamera(0, 0, 10, 0, 0, 0);


}

void GLModel::draw(){

	// clear buffer
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

// save the initial ModelView matrix before modifying ModelView matrix
glPushMatrix();

// tramsform camera
glTranslatef(0, 0, cameraZoom);
glRotatef(cameraAngleX, 1, 0, 0);   // pitch
glRotatef(cameraAngleY, 0, 1, 0);   // heading

// draw a triangle
glBegin(GL_TRIANGLES);
		glNormal3f(0, 0, 1);
		glColor3f(1, 0, 0);
		glVertex3f(3, -2, 0);
		glColor3f(0, 1, 0);
		glVertex3f(0, 2, 0);
		glColor3f(0, 0, 1);
		glVertex3f(-3, -2, 0);
glEnd();

glPopMatrix();

}

void GLModel::setCamera(float posX, float posY, float posZ, float lookAtX, float lookAtY, float lookAtZ){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(posX, posY, posZ, lookAtX, lookAtY, lookAtZ, 0, 1, 0); // eye(x,y,z), at(x,y,z), up(x,y,z)
}


void GLModel::initLights()
{
	// set up light colors (ambient, diffuse, specular)
	GLfloat lightKa[] = {.2f, .2f, .2f, 1.0f};      // ambient light
	GLfloat lightKd[] = {.7f, .7f, .7f, 1.0f};      // diffuse light
	GLfloat lightKs[] = {1, 1, 1, 1};               // specular light
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightKa);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightKd);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightKs);

	// position the light
	float lightPos[4] = {0, 0, 20, 1}; // positional light
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glEnable(GL_LIGHT0);                            // MUST enable each light source after configuration
}


void GLModel::setViewport(int width, int height){
	// set viewport to be the entire window
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	// set perspective viewing frustum
	float aspectRatio = (float)width / height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0f, (float)(width)/height, 0.1f, 20.0f); // FOV, AspectRatio, NearClip, FarClip

	// switch to modelview matrix in order to set scene
	glMatrixMode(GL_MODELVIEW);
}
