cmake_minimum_required(VERSION 3.7.1)
enable_language(CXX)
project (Turn)

include_directories(include)
include_directories(./resources/include/)
link_directories(./resources/lib-mingw/)

#FLAGS
if(APPLE)
set (CMAKE_SHARED_LINKER_FLAGS "-lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")
endif()

if(WIN32)
set (CMAKE_SHARED_LINKER_FLAGS "-lglfw3 -lgdi32 -lopengl32")
endif()





#########################################################
# GLFW
#########################################################
add_subdirectory(./resources/glfw-3.2.1)
include_directories(./resources/glfw-3.2.1/include/)
#set(GLFW_LIBRARIES ./resources/glfw-3.2.1/)


#add_subdirectory(/MinGW/include)
#find_package(glfw3 3.2 REQUIRED)
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
  target_link_libraries(Turn glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})
	target_link_libraries(Turn ${OPENGL_LIBRARIES})
  target_link_libraries(Test glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})
  target_link_libraries(Test ${OPENGL_LIBRARIES})
