CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

all: jeu_de_base


main.o: main.cpp GameWindow.hpp Object.hpp GameGestion.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

Heart.o: Heart.cpp
	$(CPP) $(CPPFLAGS) -c Heart.cpp 

LifeWindow.o: LifeWindow.cpp Heart.hpp Object.hpp
	$(CPP) $(CPPFLAGS) -c LifeWindow.cpp

GameWindow.o: GameWindow.cpp LifeWindow.hpp GameGestion.hpp Heart.hpp 
	$(CPP) $(CPPFLAGS) -c GameWindow.cpp 

TexturesLib.o: TexturesLib.cpp 
	$(CPP) $(CPPFLAGS) -c TexturesLib.cpp 

Object.o: Object.cpp TexturesLib.hpp 
	$(CPP) $(CPPFLAGS) -c Object.cpp

GameGestion.o: GameGestion.cpp Object.hpp 
	$(CPP) $(CPPFLAGS) -c GameGestion.cpp 


jeu_de_base: main.o Heart.o LifeWindow.o GameWindow.o TexturesLib.o Object.o GameGestion.o
	$(LD) $(LDFLAGS) main.o Heart.o LifeWindow.o GameWindow.o TexturesLib.o Object.o GameGestion.o -o jeu_de_base $(LIBS)


clean:
	rm -f *.o all