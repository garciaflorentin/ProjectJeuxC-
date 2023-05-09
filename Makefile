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

Sword.o: Sword.cpp
	$(CPP) $(CPPFLAGS) -c Sword.cpp

Player.o: Player.cpp Character.hpp Sword.hpp Chest.hpp
	$(CPP) $(CPPFLAGS) -c Player.cpp

Gain.o: Gain.cpp TexturesLib.hpp
	$(CPP) $(CPPFLAGS) -c Gain.cpp

Tile.o: Tile.cpp Object.hpp 
	$(CPP) $(CPPFLAGS) -c Tile.cpp

Character.o: Character.cpp Object.hpp EnumOrientation.hpp Heart.hpp
	$(CPP) $(CPPFLAGS) -c Character.cpp

Chest.o : Chest.cpp Player.hpp Gain.hpp TexturesLib.hpp 
	$(CPP) $(CPPFLAGS) -c Chest.cpp

Map.o: Map.cpp Player.hpp Gain.hpp TexturesLib.hpp Tile.hpp Object.hpp Character.hpp Chest.hpp
	$(CPP) $(CPPFLAGS) -c Map.cpp

GameGestion.o: GameGestion.cpp Object.hpp Map.hpp
	$(CPP) $(CPPFLAGS) -c GameGestion.cpp 

Monster.o: Monster.cpp Monster.hpp Character.hpp Player.hpp 
	$(CPP) $(CPPFLAGS) -c Monster.cpp


jeu_de_base: main.o Heart.o LifeWindow.o GameWindow.o TexturesLib.o Object.o GameGestion.o Map.o Character.o Monster.o 
	$(LD) $(LDFLAGS) main.o Heart.o LifeWindow.o GameWindow.o TexturesLib.o Object.o GameGestion.o  Map.o Character.o Monster.o -o jeu_de_base $(LIBS)


clean:
	rm -f *.o all