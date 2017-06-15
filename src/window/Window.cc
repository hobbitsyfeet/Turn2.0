#include "Window.h"

Window::Window(int width, int height, std::string title){
  running = true;
	Window_Width = width;
	Window_Height = height;
	this->Title = title;
}


bool Window::setRunning(bool running){
  return this->running = running;
}
void Window::setWidth(int width){
	Window_Width = width;
}
void Window::setHeight(int height){
	Window_Height = height;
}

bool Window::getRunning(){
  return running;
}
int Window::getHeight(){
	return Window_Height;
}
int Window::getWidth(){
	return Window_Width;
}

void CallBackRenderScene(){
	// Clear the color and depth buffers.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

void CallBackResizeScene(int Width, int Height)
{
   // Let's not core dump, no matter what.
   if (Height == 0)
      Height = 1;

   glViewport(0, 0, Width, Height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);

   glMatrixMode(GL_MODELVIEW);

}
void WindowInit(int Width, int Height)
{
	// Color to clear color buffer to.
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

	// Depth to clear depth buffer to; type of test.
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);

	// Enables Smooth Color Shading; try GL_FLAT for (lack of) fun.
	glShadeModel(GL_SMOOTH);

	// Load up the correct perspective matrix; using a callback directly.
	CallBackResizeScene(Width,Height);
}
