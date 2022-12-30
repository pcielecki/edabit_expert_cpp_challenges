CFLAGS = -g -c -Wall
SRCS = pilish.cpp test_pilish.cpp
HDRS = pilish.hpp

pilish: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) pilish.cpp -o pilish.o
	$(CC) $(CFLAGS) test_pilish.cpp -o test_pilish.o

.PHONY: clean
clean:
	rm *.o
