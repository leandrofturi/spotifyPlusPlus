EXE := spotifyPlusPlus
FLAGS := -g -w -O3

all:
	#g++ -c cod/*.cpp
	#g++ -c cpp-utils/util/*.cpp
	g++ -c $(EXE).cpp
	g++ -o $(EXE) *.o $(FLAGS)
	#rm *.o

teste:
	./$(EXE)

val:
	valgrind ./$(EXE)