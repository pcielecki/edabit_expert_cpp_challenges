CFLAGS = -g -c -Wall
SRCS = pwd_checker.cpp test_pwd_checker.cpp
HDRS = pwd_checker.hpp

pwd_checker: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) pwd_checker.cpp -o pwd_checker.o
	$(CC) $(CFLAGS) test_pwd_checker.cpp -o test_pwd_checker.o

.PHONY: clean
clean:
	rm *.o
