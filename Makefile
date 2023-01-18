CC = g++
CFLAGS = -g -Wall
LIBS = -L/usr/lib -pthread -lgtest -lcrypto 
EXEC_FILENAME = run_challenges

export CC

OBJS = msg_from_space/*.o islands/islands.o islands/class_island.o islands/test_islands.o anagrams/anagrams.o anagrams/test_anagrams.o playfair_cipher/cipher.o playfair_cipher/test_cipher.o rotate_transform/rotate.o rotate_transform/test_rotate.o pilish/pilish.o pilish/test_pilish.o hash_juggling/hash_juggling.o hash_juggling/test_hash_juggling.o chain_reaction/chain_reaction.o chain_reaction/test_chain_reaction.o pwd_checker/pwd_checker.o pwd_checker/test_pwd_checker.o langtons_ant/ant.o langtons_ant/test_ant.o connect_four/connect_four.o connect_four/test_connect_four.o all_subsets/all_subsets.o all_subsets/test_all_subsets.o

edabit_expert_cpp_challenges: main.cpp 
	make -C msg_from_space
	make -C islands
	make -C anagrams
	make -C playfair_cipher
	make -C rotate_transform
	make -C pilish
	make -C hash_juggling
	make -C chain_reaction
	make -C pwd_checker
	make -C langtons_ant
	make -C connect_four
	make -C all_subsets
	$(CC) main.cpp $(OBJS) $(CFLAGS) $(LIBS) -o $(EXEC_FILENAME)

clean:
	rm $(OBJS) $(EXEC_FILENAME)
