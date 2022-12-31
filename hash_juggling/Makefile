SRCS = hash_juggling.cpp test_hash_juggling.cpp
HDRS = hash_juggling.hpp

CFLAGS = -g -c -Wall

hash_juggling: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) hash_juggling.cpp -o hash_juggling.o
	$(CC) $(CFLAGS) test_hash_juggling.cpp -o test_hash_juggling.o


.PHONY: clean
clean:
	rm *.o
