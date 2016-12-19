CCC = g++
#CFLAGS= -Wall -g -std=c++11
CFLAGS = -I../include/
PROGRAM = Turn
SRC = .
SRC_OBJS = $(SRC)/main.o	$(SRC)/Colours.o $(SRC)/World/WorldBlocks/WorldBlock.o $(SRC)/World/WorldBlocks/Grass.o

## ADD YOUR TEST OBJECTS TO HERE

ALL_OBJS = $(SRC_OBJS)


# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) $(CFLAGS) -c $< -o $(patsubst %.cc,%.o,$<)

$(PROGRAM): $(ALL_OBJS)
	$(CCC) $(CFLAGS) -o $@ $^


clean:
	rm -rf *~ $(SRC_OBJS) $(SRC_OBS) 

clean-all: clean
	rm -f $(PROGRAM)

run:
	.\$(PROGRAM_TEST)