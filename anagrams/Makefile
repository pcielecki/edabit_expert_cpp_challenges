CFLAGS = -c -g -Wall

SRCS = anagrams.cpp test_anagrams.cpp
HDRS = anagrams.hpp

anagrams: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) anagrams.cpp -o anagrams.o
	$(CC) $(CFLAGS) anagrams.cpp -o anagrams.o


.PHONY: clean
clean:
	rm *.o
