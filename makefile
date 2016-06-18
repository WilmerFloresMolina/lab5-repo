pieza: Main.o pieza.o
	g++ Main.o pieza.o -o pieza -lncurses
Main.o: Main.cpp pieza.h
	g++ -c Main.cpp -lncurses
pieza.o:	pieza.cpp pieza.h
	g++ -c pieza.cpp
