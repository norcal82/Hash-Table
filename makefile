hash_tb:hash.o hash_function.o main.o
	g++ -o hash_tb hash.o hash_function.o main.o
hash.o: hash.cpp hash.h
	g++ -c hash.cpp -Wall -W -Werror -pedantic -g -D HASH_TABLE_SIZE=10
hash_function.o: hash_function.cpp hash.h
	g++ -c hash_function.cpp -Wall -W -Werror -pedantic -g -D HASH_TABLE_SIZE=10
main.o: main.cpp hash.h hash.cpp
	g++ -c main.cpp -Wall -W -Werror -pedantic -g -D HASH_TABLE_SIZE=10
clean:
	rm hash_tb *.o 
