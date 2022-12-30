CC = g++
CFLAGS = -g -Wall
LIBS = -pthread -lgtest
EXEC_FILENAME = run_challenges

export CC

OBJS = msg_from_space/*.o islands/islands.o islands/class_island.o islands/test_islands.o anagrams/anagrams.o anagrams/test_anagrams.o playfair_cipher/cipher.o playfair_cipher/test_cipher.o rotate_transform/rotate.o rotate_transform/test_rotate.o

edabit_expert_cpp_challenges: main.cpp 
	make -C msg_from_space
	make -C islands
	make -C anagrams
	make -C playfair_cipher
	make -C rotate_transform
	$(CC) main.cpp $(OBJS) $(CFLAGS) $(LIBS) -o $(EXEC_FILENAME)

clean:
	rm $(OBJS) $(EXEC_FILENAME)
