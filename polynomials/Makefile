SRCS = polynomials.cpp test_polynomials.cpp
HDRS = polynomials.hpp

CFLAGS = -g -c -Wall

polynomials: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) polynomials.cpp -o polynomials.o
	$(CC) $(CFLAGS) test_polynomials.cpp -o test_polynomials.o


.PHONY: clean

clean:
	rm *o
