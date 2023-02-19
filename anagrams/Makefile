CFLAGS = -c -g -Wall

SRCS = anagrams.cpp test_anagrams.cpp
HDRS = anagrams.hpp

anagrams.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) anagrams.cpp -o anagrams.o
	$(CC) $(CFLAGS) test_anagrams.cpp -o test_anagrams.o


.PHONY: clean
clean:
	rm *.o
