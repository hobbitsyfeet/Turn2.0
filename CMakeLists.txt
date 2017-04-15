cmake_minimum_required(VERSION 3.7.1)
project (Turn2.0)
#Bring the headers, such as Student.h into the project
include_directories(include)

#FLAGS

#Can manually add the sources using the set command as follows:
set(SOURCES src/*.cc src/World/*.cc src/World/WorldBlocks/*.cc)
set(MAIN ./main.cc)
set(TEST ./tests/tests.cc)


#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES src/*.cc src/World/*.cc src/World/WorldBlocks/*.cc src/Units/*.cc)

add_executable(Turn ${MAIN} ${SOURCES})
add_executable(Test ${TEST} ${SOURCES})
