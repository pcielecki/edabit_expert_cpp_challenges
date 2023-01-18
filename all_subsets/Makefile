CFLAGS = -g -c -Wall
SRS = all_subsets.cpp test_all_subsets.cpp
HDRS = all_subsets.hpp

all_subsets: $(SRC) $(HDRS)
	$(CC) $(CFLAGS) all_subsets.cpp -o all_subsets.o
	$(CC) $(CFLAGS) test_all_subsets.cpp -o test_all_subsets.o


.PHONY: clean
clean:
	rm *o
