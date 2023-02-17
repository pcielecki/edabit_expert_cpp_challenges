SRCS = writing.cpp test_writing.cpp
HDRS = writing.hpp
CFLAGS = -g -c -Wall

constrained_writing: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) writing.cpp -o writing.o
	$(CC) $(CFLAGS) test_writing.cpp -o test_writing.o

.PHONY: clean

clean:
	rm *o
