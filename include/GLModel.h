/*******************************
*
	GLModel.h
	OpenGL Model:
	------------------------------
	Author: Justin Petluk
*
*******************************/
#ifndef GLMODEL_H
#define GLMODEL_H

#ifdef __APPLE__
#include "OpenGL/gl.h"
#include "OpenGL/glu.h"
#endif

#ifdef __WIN32__
#include "Windows.h"
#include "GL/gl.h"
#include "GL/glu.h"
#endif

class GLModel{
public:

	GLModel();
	//~GLModel();
	void init();			//** Initializes the scene (viewport, camera and lighting)
	void display();			//**

	void rotateCamera(float horizontal, float vertical);
	void zoomCamera(float distance);

	//**
	void setCamera(float posX, float posY, float posZ, float lookAtX, float lookAtY, float lookAtZ);
	void setViewport(int width, int height);



private:

	void initLights();

	float cameraPosX;
	float cameraPosY;
	float cameraPosZ;

	float cameraAngleX;
	float cameraAngleY;
	float cameraZoom;
};

#endif //GLMODEL_H
