SRCS = mana.cpp test_mana.cpp
HDRS = mana.hpp
CFLAGS = -g -c -Wall

mana.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) mana.cpp -o mana.o
	$(CC) $(CFLAGS) test_mana.cpp -o test_mana.o

.PHONY: clean

clean:
	rm *o
