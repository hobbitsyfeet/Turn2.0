#ifndef GLVIEW_H
#define GLVIEW_H

#ifdef __APPLE__
#include "OpenGL/gl.h"
#include "OpenGL/glu.h"
#endif

#ifdef __WIN32__
#include "Windows.h"
#include "GL/gl.h"
#include "GL/glu.h"
#endif

#include <vector>

void generateShapes();

class shape {
public:
	virtual void draw() = 0;
	void position(float x, float y); //sets postion (according to first vertex)
	void translate(float x, float y); //changes position

	void multiply(float size); //multiplies size

	void rotate(float degree); // rotates clockwise
	void rotateCounter(float degree); //rotates counterclockwise

	void reflectVirtical();
	void reflectHorizontal();

	void addVertex(float x,float y);
	void getVertex(int vertexIndex);

	void setVertexColour(int vertexIndex, float r, float g, float b, float a);
	void setColour(float r,float g, float b, float a); //iterates every point and sets Colours


protected:
	float multiplier;
	std::vector< std::pair<float, float> > vertexArray;
	std::vector<float> colour; // matches colour for each vertex
};

class line : public shape{
public:
	line(float length);
	void draw();
private:
};

class rectangle : public shape {
public:
	rectangle(float width, float height);
	void draw();
private:
};

class circle : public shape {
public:
	circle(float radius);
	void draw();
private:
};

class triangle : public shape {
public:
	triangle(float edge_1, float edge_2, float edge_3);
	void draw();
private:
};

class polygon : public shape{
public:
	polygon();
	//polygon(float vertex[int]);
	void draw();
private:
};

#endif //GLVIEW_H
