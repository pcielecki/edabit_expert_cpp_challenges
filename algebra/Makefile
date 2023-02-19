SRCS = algebra.cpp test_algebra.cpp
HDRS = algebra.hpp
CFLAGS = -g -c -Wall

algebra.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) algebra.cpp -o algebra.o
	$(CC) $(CFLAGS) test_algebra.cpp -o test_algebra.o

.PHONY: clean

clean:
	rm *o
