cmake_minimum_required(VERSION 3.7.1)
project (Turn2.0)
#Bring the headers, such as Student.h into the project
include_directories(include)
include_directories(include/window)


#FLAGS
if(APPLE)
set (CMAKE_SHARED_LINKER_FLAGS "-lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")
endif()


#########################################################
# FIND GLUT
#########################################################
#find_package(GLUT REQUIRED)
#include_directories(${GLUT_INCLUDE_DIRS})
#link_directories(${GLUT_LIBRARY_DIRS})
#add_definitions(${GLUT_DEFINITIONS})
#if(NOT GLUT_FOUND)
#    message(ERROR " GLUT not found!")
#endif(NOT GLUT_FOUND)


#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

#########################################################
# Include Files
#########################################################
#Can manually add the sources using the set command as follows:
set(SOURCES_RECURSE src/*.cc)
set(MAIN ./main.cc)
set(TEST ./tests/tests.cc)


#However, the file(GLOB...) allows for wildcard additions:
file(GLOB_RECURSE SOURCES src/*.cc)

add_executable(Turn ${MAIN} ${SOURCES})
add_executable(Test ${TEST} ${SOURCES})

########################################################
# Linking
#########################################################

  # create the program "test"
	target_link_libraries(Turn glfw ${GLFW_LIBRARIES})
	target_link_libraries(Test glfw ${GLFW_LIBRARIES})
	target_link_libraries(Turn ${OPENGL_LIBRARIES})
	target_link_libraries(Test ${OPENGL_LIBRARIES} ${GLFW_LIBRARY} )
