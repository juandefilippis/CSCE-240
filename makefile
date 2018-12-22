CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

test : test.cc max_heap.o
	$(LINK) $@ $^

max_heap.o : max_heap.cc max_heap.h
	$(COMPILE) $< 

clean:
	@rm test *.o
