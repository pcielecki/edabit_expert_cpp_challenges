SRCS = msg_from_space.cpp test_msg_from_space.cpp
HDRS = msg_from_space.hpp
CFLAGS = -g -c -Wall

test_msg_from_space: test_msg_from_space.cpp
	$(CC) $(CFLAGS) test_msg_from_space.cpp -o test_msg_from_space.o
	$(CC) $(CFLAGS) msg_from_space.cpp -o msg_from_space.o

.PHONY: clean
clean:
	rm *.o
