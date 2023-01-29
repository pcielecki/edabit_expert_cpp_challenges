SRCS = vowels.cpp test_vowels.cpp
HDRS = vowels.hpp
CFLAGS = -g -c -Wall

vowels: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) vowels.cpp -o vowels.o
	$(CC) $(CFLAGS) test_vowels.cpp -o test_vowels.o

.PHONY: clean

clean:
	rm *o
