CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

all: jeu_de_base

jeu_de_base: main.o GameWindow.o Object.o GameGestion.o 
	$(LD) $(LDFLAGS) main.o GameWindow.o Object.o GameGestion.o -o testrectangle $(LIBS)

main.o: main.cpp GameWindow.hpp Object.hpp GameGestion.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

GameWindow.o: GameWindow.cpp LifeWindow.hpp GameGestion.hpp Heart.hpp 
	$(CPP) $(CPPFLAGS) -c GameWindow.cpp 

Object.o: Object.cpp TexturesLib.hpp 
	$(CPP) $(CPPFLAGS) -c Object.cpp

GameGestion.o: GameGestion.cpp Object.hpp 
	$(CPP) $(CPPFLAGS) -c GameGestion.cpp 

clean:
	rm -f *.o all