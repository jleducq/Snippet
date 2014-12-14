all: test crazy_boost crazy_algo

test: main_test.o
	g++ -o test main_test.o

main_test.o: main_test.cpp
	g++ -o main_test.o -c main_test.cpp -W -Wall -ansi -pedantic

crazy_boost: main_boost.o
	g++ -o crazy_boost main_boost.o

main_boost.o: main_boost.cpp
	g++ -o main_boost.o -c main_boost.cpp -W -Wall -ansi -pedantic
        
crazy_algo: main_algo.o
	g++ -o crazy_algo main_algo.o

main_algo.o: main_algo.cpp
	g++ -o main_algo.o -c main_algo.cpp -W -Wall -ansi -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf hello
