CFLAGS = -g -c -Wall
SRCS = rotate.cpp test_rotate.cpp
HDRS = rotate.hpp

rotate: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) rotate.cpp -o rotate.o
	$(CC) $(CFLAGS) test_rotate.cpp -o test_rotate.o

.PHONY: clean
clean:
	rm *.o
