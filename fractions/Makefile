SRCS = fractions.cpp test_fractions.cpp
HDRS = fractions.hpp
CFLAGS = -g -c -Wall

fractions: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) fractions.cpp -o fractions.o
	$(CC) $(CFLAGS) test_fractions.cpp -o test_fractions.o

.PHONY: clean

clean:
	rm *o

