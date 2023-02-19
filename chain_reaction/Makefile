CFLAGS = -g -c -Wall
SRCS = chain_reaction.cpp test_chain_reaction.cpp
HDRS = chain_reaction.hpp

chain_reaction.o: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) chain_reaction.cpp -o chain_reaction.o
	$(CC) $(CFLAGS) test_chain_reaction.cpp -o test_chain_reaction.o

.PHONY: clean
clean:
	rm *.o
