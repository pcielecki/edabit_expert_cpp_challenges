CFLAGS = -g -c -Wall
SRCS = connect_four.cpp test_connect_four.cpp
HDRS = connect_four.hpp

connect_four: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) connect_four.cpp -o connect_four.o
	$(CC) $(CFLAGS) test_connect_four.cpp -o test_connect_four.o

.PHONY: clean
clean:
	rm *o

