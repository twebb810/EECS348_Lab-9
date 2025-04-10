all: lab9

lab9: main.o
	g++ -std=c++17 -o lab9 main.o

main.o: main.cpp
	g++ -std=c++17 -c main.cpp

clean:
	rm -f *.o lab9
