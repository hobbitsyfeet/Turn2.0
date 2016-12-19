CCC = g++
#CFLAGS= -Wall -g -std=c++11
CFLAGS = -I../include/
PROGRAM = Turn
SRC = .
WRLDBLKS = $(SRC)/World/WorldBlocks
WORLD_OBJS = $(WRLDBLKS)/WorldBlock.o $(WRLDBLKS)/Grass.o $(WRLDBLKS)/ShallowWater.o $(WRLDBLKS)/DeepWater.o $(WRLDBLKS)/OccupyBlock.o
SRC_OBJS = $(SRC)/main.o	$(SRC)/Colours.o $(SRC)/Units/Unit.o $(SRC)/Combat.o $(WORLD_OBJS)

## ADD YOUR TEST OBJECTS TO HERE

ALL_OBJS = $(SRC_OBJS)


# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) $(CFLAGS) -c $< -o $(patsubst %.cc,%.o,$<)

$(PROGRAM): $(ALL_OBJS)
	$(CCC) $(CFLAGS) -o $@ $^


clean:
	rm -rf *~ $(SRC_OBJS)

clean-all: clean
	rm -f $(PROGRAM)

run:
	.\$(PROGRAM)