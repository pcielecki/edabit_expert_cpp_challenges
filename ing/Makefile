SRCS = ing.cpp test_ing.cpp
HDRS = ing.hpp
CFLAGS = -g -c -Wall

ing.o: $(SRCS) $(HDRS) 
	$(CC) $(CFLAGS) -c ing.cpp -o ing.o	
	$(CC) $(CFLAGS) -c test_ing.cpp -o test_ing.o	


.PHONY: clean

clean:
	rm *o
