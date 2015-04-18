all: test

test: main_test.o
	g++ -o test main_test.o

main_test.o: main_test.cpp
	g++ -o main_test.o -c main_test.cpp -W -Wall -ansi -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf hello
