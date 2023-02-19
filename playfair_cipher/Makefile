CFLAGS = -g -c -Wall
SRCS = cipher.cpp test_cipher.cpp
HDRS = cipher.hpp

cipher.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) cipher.cpp -o cipher.o
	$(CC) $(CFLAGS) test_cipher.cpp -o test_cipher.o

.PHONY: clean
clean:
	rm *o
