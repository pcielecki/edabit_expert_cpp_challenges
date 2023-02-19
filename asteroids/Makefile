SRCS = asteroids.cpp test_asteroids.cpp
HDRS = asteroids.hpp
CFLAGS = -c -g -Wall

asteroids.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) asteroids.cpp -o asteroids.o
	$(CC) $(CFLAGS) test_asteroids.cpp -o test_asteroids.o


.PHONY: clean

clean:
	rm *o
