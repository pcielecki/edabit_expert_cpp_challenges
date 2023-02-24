SRCS = s_string.cpp test_s_string.cpp
HDRS = s_string.hpp
CFLAGS = -g -c -Wall

s_string.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) s_string.cpp -o s_string.o
	$(CC) $(CFLAGS) test_s_string.cpp -o test_s_string.o

.PHONY: clean

clean:
	rm *o
