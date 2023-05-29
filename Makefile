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

Player.o: Player.cpp Character.hpp Object.hpp EnumOrientation.hpp Heart.hpp Chest.hpp
	$(CPP) $(CPPFLAGS) -c Player.cpp 

GameGestion.o: GameGestion.cpp Object.hpp Player.hpp Character.hpp
	$(CPP) $(CPPFLAGS) -c GameGestion.cpp 

Map.o: Map.cpp Object.hpp Player.hpp Gain.hpp TexturesLib.hpp Tile.hpp Object.hpp Character.hpp Chest.hpp Ground.hpp TypeGround.hpp MeleeMonster.hpp RangedMonster.hpp FinalBoss.hpp
	$(CPP) $(CPPFLAGS) -c Map.cpp 

Chest.o: Chest.cpp Gain.hpp Object.hpp Character.hpp Player.hpp  Tile.hpp TexturesLib.hpp
	$(CPP) $(CPPFLAGS) -c Chest.cpp 

Projectile.o: Projectile.cpp Object.hpp Player.hpp TexturesLib.hpp Monster.hpp Projectile.hpp 
	$(CPP) $(CPPFLAGS) -c Projectile.cpp 

Fireball.o: Fireball.cpp Projectile.hpp
	$(CPP) $(CPPFLAGS) -c Fireball.cpp

UserInterface.o: UserInterface.cpp
	$(CPP) $(CPPFLAGS) -c UserInterface.cpp 

GoldenChest.o: GoldenChest.cpp Chest.hpp
	$(CPP) $(CPPFLAGS) -c GoldenChest.cpp 

Monster.o: Monster.cpp Player.hpp
	$(CPP) $(CPPFLAGS) -c Monster.cpp 

KeyWindow.o: KeyWindow.cpp Player.hpp
	$(CPP) $(CPPFLAGS) -c KeyWindow.cpp 
MeleeMonster.o: MeleeMonster.cpp Monster.hpp
	$(CPP) $(CPPFLAGS) -c MeleeMonster.cpp

Door.o: Door.cpp Wall.hpp Player.hpp
	$(CPP) $(CPPFLAGS) -c Door.cpp 

RangedMonster.o: RangedMonster.cpp Player.hpp Fireball.hpp
	$(CPP) $(CPPFLAGS) -c RangedMonster.cpp

FinalBoss.o: FinalBoss.cpp Monster.hpp Fireball.hpp
	$(CPP) $(CPPFLAGS) -c FinalBoss.cpp



jeu_de_base: main.o  Door.o KeyWindow.o GoldenChest.o UserInterface.o Monster.o Projectile.o Heart.o TexturesLib.o Object.o LifeWindow.o Character.o Player.o Map.o GameGestion.o GameWindow.o Chest.o Fireball.o MeleeMonster.o RangedMonster.o FinalBoss.o
	$(LD) $(LDFLAGS) Door.o KeyWindow.o GoldenChest.o UserInterface.o Monster.o Projectile.o Chest.o Heart.o TexturesLib.o Object.o LifeWindow.o Character.o Player.o Map.o GameGestion.o GameWindow.o Fireball.o MeleeMonster.o RangedMonster.o FinalBoss.o main.o -o jeu_de_base $(LIBS)


clean:
	rm -f *.o jeu_de_base