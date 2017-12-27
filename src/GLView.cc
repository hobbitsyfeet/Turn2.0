#include "GLView.h"

float i = -5;
float i2= 1.5;

void generateShapes(){


		rectangle rect(1,1);

		rectangle rect2(1,1);

		bool toggle = false;

		i += 0.1;
		i2 -=0.01;
		//rect2.multiply(i2);
		glColor3f(1,0,0);
		rect2.draw();


	//	rect.translate(i,0);
		glColor3f(1,1,0);
		rect.draw();


}

void shape::position(float x, float y){

}

void shape::translate(float x, float y){
	glTranslatef(x,y,0);
}

void shape::multiply(float size){
	for(int i = 0; i < vertexArray.size(); i++){
		vertexArray[i].first *= size;
		vertexArray[i].second *= size;
	}
}

void shape::rotate(float degree) {}
void shape::rotateCounter(float degree){}

void shape::reflectVirtical(){}
void shape::reflectHorizontal(){}

void shape::setVertexColour(int vertexIndex, float r, float g, float b, float a){}
void shape::setColour(float r,float g, float b, float a){}

void shape::addVertex(float x, float y){
	std::pair <float,float> temp;
	temp.first = x;
	temp.second = y;
	vertexArray.push_back (temp);
}



rectangle::rectangle(float width, float height){
	//generates clockwise starting top left

addVertex( -width/2, height /2);
addVertex( width /2, height/2);
addVertex( width /2, -height/2);
addVertex( -width/2, -height/2);

}
void rectangle::draw(){
	glBegin(GL_POLYGON);
	for(int i = 0; i < vertexArray.size(); i++){
		glVertex2f(vertexArray[i].first, vertexArray[i].second);
	}
	glEnd();
}
