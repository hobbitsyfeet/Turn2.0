#ifndef WINDOW_H
#define WINDOW_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GL/freeglut.h>
#else
#ifdef _WIN32
  #include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <string>
class Window {
public:
	Window(int width, int height, std::string title);

	void setWidth(int width);
	void setHeight(int height);
	bool setRunning(bool running);

	bool getRunning();
	int getWidth();
	int getHeight();
	std::string getTitle();
private:

	bool running;
	int Window_Width;
	int Window_Height;
	std::string Title;
};

void CallBackRenderScene();
void CallBackResizeScene(int height, int width);
void WindowInit(int height, int width);

#endif //WINDOW_H
