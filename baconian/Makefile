SRCS = baconian.cpp test_baconian.cpp
HDRS = baconian.hpp
CFLAGS = -c -g -Wall

baconian: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) baconian.cpp -o baconian.o
	$(CC) $(CFLAGS) test_baconian.cpp -o test_baconian.o

.PHONY: clean
clean:
	rm *o
