CC = g++
CFLAGS = -g -Wall
LIBS = -pthread -lgtest
EXEC_FILENAME = run_challenges

export CC

OBJS = msg_from_space/*.o islands/islands.o islands/class_island.o islands/test_islands.o anagrams/anagrams.o anagrams/test_anagrams.o

edabit_expert_cpp_challenges: main.cpp 
	make -C msg_from_space
	make -C islands
	make -C anagrams
	$(CC) main.cpp $(OBJS) $(CFLAGS) $(LIBS) -o $(EXEC_FILENAME)

clean:
	rm $(OBJS) $(EXEC_FILENAME)
