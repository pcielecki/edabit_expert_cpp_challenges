CFLAGS = -g -c -Wall

SRCS = islands.cpp test_islands.cpp class_island.cpp
HDRS = islands.hpp class_island.hpp

test_islands: $(SRCS) $(HRRS)
	$(CC) $(CFLAGS) islands.cpp -o islands.o
	$(CC) $(CFLAGS) class_island.cpp -o class_island.o
	$(CC) $(CFLAGS) test_islands.cpp -o test_islands.o

.PHONY: clean
clean:
	rm *.o
