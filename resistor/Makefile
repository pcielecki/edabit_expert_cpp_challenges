SRCS = resistor.cpp test_resistor.cpp
HDRS = resistor.hpp
CFLAGS = -g -c -Wall

resistor.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) resistor.cpp -o resistor.o
	$(CC) $(CFLAGS) test_resistor.cpp -o test_resistor.o

.PHONY: clean

clean:
	rm *o
