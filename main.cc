
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

#include"Window.h"

int main(int argc, char **argv) {
	Window* window = new Window(400,400, "Turn");
	   glutInit(&argc, argv);

	   // To see OpenGL drawing, take out the GLUT_DOUBLE request.
	   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	   // The following is for window creation.
	   // Set Window size
	   glutInitWindowSize(window->getWidth(), window->getHeight());
	   // Create and Open a window with its title.
		 glutCreateWindow("Turn");
	   // Register and install the callback function to do the drawing.
	   glutDisplayFunc(&CallBackRenderScene);

	   // If there's nothing to do, draw.
	   //glutIdleFunc(&CallBackRenderScene);

	   // It's a good idea to know when our window's resized.
	   glutReshapeFunc(&CallBackResizeScene);
	   // OK, OpenGL's ready to go.  Let's call our own init function.
	   WindowInit(window->getWidth(), window->getHeight());

	   glEnable(GL_DEPTH_TEST);
	   // Above functions represents those you will do to set up your
	   // application program.
	   // Now pass off control to OpenGL.
	   glutMainLoop();
	   // Never returns.
	   return 1;
}
