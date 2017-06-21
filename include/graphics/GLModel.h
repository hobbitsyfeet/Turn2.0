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

#include "OpenGL/gl.h"
#include "OpenGL/glu.h"

class GLModel{
public:

	GLModel();
	//~GLModel();
	void init();			//** Initializes the scene (viewport, camera and lighting)
	void draw();			//**

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
