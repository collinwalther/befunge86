SRCS = Cell.cpp Befunge.cpp Board.cpp
OBJS = $(SRCS:.cpp=.o)
VPATH = src/
CC = g++
CFLAGS = -Wall -I src/

%.o:%.cpp
	$(CC) $(CFLAGS) $< -c -o $@

all:        src test build

clean:
	rm $(OBJS) befunge

src:        $(OBJS)
# TODO: put sources in src/, tests in tst/, and binaries in src/, redo makefile to work with this layout
test:       test_cell 

test_cell:
	$(CC) $(CFLAGS) -o cell_test cell_test.cpp $(OBJS)
	./cell_test
	rm cell_test

build:
	$(CC) $(CFLAGS) -o befunge main.cpp $(OBJS)

