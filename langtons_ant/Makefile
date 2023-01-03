CFLAGS = -g -c -Wall
SRCS = ant.cpp test_ant.cpp
HDRS = ant.hpp

langtons_ant: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) ant.cpp -o ant.o
	$(CC) $(CFLAGS) test_ant.cpp -o test_ant.o

.PHONY: clean
clean:
	rm *.o
