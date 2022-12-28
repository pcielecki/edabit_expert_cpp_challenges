CC = g++
CFLAGS = -g -Wall
LIBS = -pthread -lgtest
EXEC_FILENAME = run_challenges

export CC

objs = msg_from_space/msg_from_space.o msg_from_space/test_msg_from_space.o islands/*o

edabit_expert_cpp_challenges: main.cpp 
	make -C msg_from_space
	make -C islands
	$(CC) main.cpp $(objs) $(CFLAGS) $(LIBS) -o $(EXEC_FILENAME)

clean:
	rm $(objs) $(EXEC_FILENAME)
