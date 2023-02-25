SRCS = casino.cpp test_casino.cpp
HDRS = casino.hpp
CFLAGS = -g -c -Wall

casino.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) casino.cpp -o casino.o
	$(CC) $(CFLAGS) test_casino.cpp -o test_casino.o

.PHONY: clean

clean:
	rm *o
