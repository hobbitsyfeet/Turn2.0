CCC = g++
#CFLAGS= -Wall -g -std=c++11
CFLAGS = -I../include/
PROGRAM_TEST = tests
SRC = ../src
WORLD = $(SRC)/World/World.o
WBLKS = $(SRC)/World/WorldBlocks
UNITS = $(SRC)/Units/Unit.o
SRC_WBLKS_OBJS = $(WBLKS)/WorldBlock.o $(WBLKS)/Grass.o $(WBLKS)/ShallowWater.o $(WBLKS)/DeepWater.o
SRC_OBJS = $(SRC)/Coord.o 	$(SRC)/Colours.o $(SRC)/UI.o $(SRC)/Inventory.o $(SRC)/Item.o
## ADD YOUR TEST OBJECTS TO HERE
TEST_OBJS = main.o

ALL_OBJS = $(TEST_OBJS) $(SRC_OBJS) $(UNITS) $(WORLD) $(SRC_WBLKS_OBJS)


# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) $(CFLAGS) -c $< -o $(patsubst %.cc,%.o,$<)

$(PROGRAM_TEST): $(ALL_OBJS)
	$(CCC) $(CFLAGS) -o $@ $^


clean:
	rm -rf *~ $(ALL_OBJS)

clean-all: clean
	rm -f $(PROGRAM_TEST) *.exe

run:
	.\$(PROGRAM_TEST)