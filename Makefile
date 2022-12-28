CC = g++
CFLAGS = -g -Wall
LIBS = -pthread -lgtest
EXEC_FILENAME = run_challenges

export CC

OBJS = msg_from_space/*.o islands/*o anagrams.*o

edabit_expert_cpp_challenges: main.cpp 
	make -C msg_from_space
	make -C islands
	make -C anagrams
	$(CC) main.cpp $(OBJS) $(CFLAGS) $(LIBS) -o $(EXEC_FILENAME)

clean:
	rm $(OBJS) $(EXEC_FILENAME)
