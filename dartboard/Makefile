SRCS = dartboard.cpp test_dartboard.cpp
HDRS = dartboard.hpp
CFLAGS = -g -c -Wall

dartboard.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) dartboard.cpp -o dartboard.o
	$(CC) $(CFLAGS) test_dartboard.cpp -o test_dartboard.o

.PHONY: clean

clean:
	rm *o
