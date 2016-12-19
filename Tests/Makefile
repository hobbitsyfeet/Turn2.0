CCC = g++
#CFLAGS= -Wall -g -std=c++11
CFLAGS = -I../include/
PROGRAM_TEST = tests
SRC = ../src
WRLDBLKS = $(SRC)/World/WorldBlocks
SRC_OBJS =	$(SRC)/Colours.o $(WRLDBLKS)/WorldBlock.o $(WRLDBLKS)/Grass.o $(WRLDBLKS)/ShallowWater.o $(WRLDBLKS)/DeepWater.o

## ADD YOUR TEST OBJECTS TO HERE
TEST_OBJS = main.o

ALL_OBJS = $(TEST_OBJS) $(SRC_OBJS)


# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) $(CFLAGS) -c $< -o $(patsubst %.cc,%.o,$<)

$(PROGRAM_TEST): $(ALL_OBJS)
	$(CCC) $(CFLAGS) -o $@ $^


clean:
	rm -rf *~ $(SRC_OBJS) $(TEST_OBJS) $(SRC_OBS)

clean-all: clean
	rm -f $(PROGRAM_TEST) *.exe

run:
	.\$(PROGRAM_TEST)