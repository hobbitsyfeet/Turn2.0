CCC = g++
#CFLAGS= -Wall -g -std=c++11
PROGRAM_TEST = tests
SRC = ../src
SRC_OBJS =	../src/Colours.o

## ADD YOUR TEST OBJECTS TO HERE
TEST_OBJS = TestColours.o ../src/Colours.o

ALL_OBJS = $(TEST_OBJS) $(SRC_OBJS)


# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) -c $< -o $(patsubst %.cc,%.o,$<)

$(PROGRAM_TEST): $(ALL_OBJS)
	$(CCC) -o $@ $^


clean:
	rm -rf *~ $(SRC_OBJS) $(TEST_OBJS) $(SRC_OBS)

clean-all: clean
	rm -f $(PROGRAM_TEST)

run:
	.\$(PROGRAM_TEST)