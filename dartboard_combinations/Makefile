SRCS = dartboard_combinations.cpp test_dartboard_combinations.cpp
HDRS = dartboard_combinations.hpp
CFLAGS = -g -c -Wall

dartboard_combinations.o:
	$(CC) $(CFLAGS) dartboard_combinations.cpp -o dartboard_combinations.o
	$(CC) $(CFLAGS) test_dartboard_combinations.cpp -o test_dartboard_combinations.o

.PHONY: clean

clean:
	rm *o
