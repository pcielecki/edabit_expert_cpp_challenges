CC = g++
CFLAGS = -g -Wall
LIBS = -L/usr/lib -pthread -lgtest -lcrypto 
EXEC_FILENAME = run_challenges

export CC

OBJS = msg_from_space/*.o islands/islands.o islands/class_island.o islands/test_islands.o anagrams/anagrams.o anagrams/test_anagrams.o playfair_cipher/cipher.o playfair_cipher/test_cipher.o rotate_transform/rotate.o rotate_transform/test_rotate.o pilish/pilish.o pilish/test_pilish.o hash_juggling/hash_juggling.o hash_juggling/test_hash_juggling.o chain_reaction/chain_reaction.o chain_reaction/test_chain_reaction.o pwd_checker/pwd_checker.o pwd_checker/test_pwd_checker.o langtons_ant/ant.o langtons_ant/test_ant.o connect_four/connect_four.o connect_four/test_connect_four.o all_subsets/all_subsets.o all_subsets/test_all_subsets.o baconian/baconian.o baconian/test_baconian.o sudoku/sudoku.o sudoku/test_sudoku.o nico/nico.o nico/test_nico.o resistor/resistor.o resistor/test_resistor.o algebra/algebra.o algebra/test_algebra.o buckets/buckets.o buckets/test_buckets.o vowels/vowels.o vowels/test_vowels.o dartboard/dartboard.o dartboard/test_dartboard.o dartboard_combinations/dartboard_combinations.o dartboard_combinations/test_dartboard_combinations.o fractions/fractions.o fractions/test_fractions.o ing/ing.o ing/test_ing.o mana/mana.o mana/test_mana.o polynomials/polynomials.o polynomials/test_polynomials.o asteroids/asteroids.o asteroids/test_asteroids.o constrained_writing/writing.o constrained_writing/test_writing.o polybius2/polybius2.o polybius2/test_polybius2.o

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
	make -C baconian
	make -C sudoku
	make -C nico
	make -C resistor
	make -C algebra
	make -C buckets
	make -C vowels
	make -C dartboard
	make -C dartboard_combinations
	make -C fractions
	make -C ing
	make -C mana
	make -C polynomials
	make -C asteroids
	make -C constrained_writing
	make -C polybius2
	$(CC) main.cpp $(OBJS) $(CFLAGS) $(LIBS) -o $(EXEC_FILENAME)

clean:
	rm $(OBJS) $(EXEC_FILENAME)
