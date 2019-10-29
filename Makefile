EXE := spotifyPlusPlus
FLAGS := -g -w -O2 -std=c++17

all:
	g++ -c cod/*.cpp $(FLAGS)
	g++ -c cpp-utils/util/*.cpp $(FLAGS)
	g++ -c $(EXE).cpp $(FLAGS)
	g++ -o $(EXE) *.o $(FLAGS)
	rm *.o