SRCS = nico.cpp test_nico.cpp
HDRS = nico.hpp
CFLAGS = -c -g -Wall

nico: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) nico.cpp -o nico.o
	$(CC) $(CFLAGS) test_nico.cpp -o test_nico.o

.PHONY: clean

clean:
	rm *o
