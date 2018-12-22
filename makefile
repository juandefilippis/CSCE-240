CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g         # produce debugging information

LINK = $(CC) $(FLAGS) -o
COMPILE = $(CC) $(FLAGS) -c

test_stat_tracker: test_stat_tracker.o
	$(LINK) $@ $^

test_stat_tracker.o : test_stat_tracker.cc stat_tracker.cc stat_tracker.h
	$(COMPILE) $<

clean:
	@rm -f *.o test_stack test_stat_tracker test_ppt search
