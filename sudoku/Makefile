SRCS = sudoku.cpp test_sudoku.cpp
HDRS = sudoku.hpp
CFLAGS = -c -g -Wall

sudoku.o:
	$(CC) $(CFLAGS) sudoku.cpp -o sudoku.o
	$(CC) $(CFLAGS) test_sudoku.cpp -o test_sudoku.o

.PHONY: clean

clean:
	rm *o
