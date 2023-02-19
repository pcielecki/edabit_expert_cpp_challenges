SRCS = buckets.cpp test_buckets.cpp
HDRS = buckets.hpp
CFLAGS = -g -c -Wall

buckets.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) buckets.cpp -o buckets.o
	$(CC) $(CFLAGS) test_buckets.cpp -o test_buckets.o

.PHONY: clean
	
clean:
	rm *o
