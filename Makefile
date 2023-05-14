CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -no-pie

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

Character.o: Character.cpp Object.hpp EnumOrientation.hpp Heart.hpp
	$(CPP) $(CPPFLAGS) -c Character.cpp

Player.o: Player.cpp Character.cpp Object.hpp EnumOrientation.hpp Heart.hpp Chest.hpp
	$(CPP) $(CPPFLAGS) -c Player.cpp 

GameGestion.o: GameGestion.cpp Object.hpp Player.hpp Character.hpp
	$(CPP) $(CPPFLAGS) -c GameGestion.cpp 

Map.o: Map.cpp Object.hpp Player.hpp Gain.hpp TexturesLib.hpp Tile.hpp Object.hpp Character.hpp Chest.hpp Ground.hpp TypeGround.hpp
	$(CPP) $(CPPFLAGS) -c Map.cpp 

Chest.o: Chest.cpp Gain.hpp Object.hpp Player.hpp Character.hpp Tile.hpp TexturesLib.hpp
	$(CPP) $(CPPFLAGS) -c Chest.cpp 




jeu_de_base: main.o Heart.o TexturesLib.o Object.o LifeWindow.o Character.o Player.o Map.o GameGestion.o GameWindow.o Chest.o
	$(LD) $(LDFLAGS) Chest.o Heart.o TexturesLib.o Object.o LifeWindow.o Character.o Player.o Map.o GameGestion.o GameWindow.o main.o -o jeu_de_base $(LIBS)


clean:
	rm -f *.o jeu_de_base