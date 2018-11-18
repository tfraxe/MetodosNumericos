makefile all: programa

matriz.o: matriz.cpp 
	g++ -g -c matriz.cpp

sistemas.o: sistemas.cpp
	g++ -g -c sistemas.cpp
programa.o: programa.cpp
	g++ -g -c programa.cpp

programa: programa.o sistemas.o matriz.o
	g++ programa.o sistemas.o matriz.o -o programa

clear:
	rm -f programa
	rm -f *.o
