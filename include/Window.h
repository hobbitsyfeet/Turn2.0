#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
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
	GLFWwindow* getWindow();

	void createWindow();
	void RenderScene();
	void draw();
	void resize(int size);
	void ResizeScene();
	void WindowInit();
private:

	bool running;
	int Window_Width;
	int Window_Height;
	std::string Title;
	GLFWwindow* window;
};



#endif //WINDOW_H
