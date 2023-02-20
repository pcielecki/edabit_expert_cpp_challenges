SRCS = polybius2.cpp test_polybius2.cpp
HDRS = polybius2.hpp
CFLAGS = -g -c -Wall

polybius2.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) polybius2.cpp -o polybius2.o
	$(CC) $(CFLAGS) test_polybius2.cpp -o test_polybius2.o

.PHONY: clean

clean:
	rm *o
