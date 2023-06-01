CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-g -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -no-pie


all: the_game 


main.o: main.cpp GameWindow.hpp GameGestion.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

GameWindow.o: GameWindow.cpp GameGestion.hpp LifeWindow.hpp KeyWindow.hpp UserInterface.hpp
	$(CPP) $(CPPFLAGS) -c GameWindow.cpp

GameGestion.o: GameGestion.cpp ColisionInterface.hpp Player.hpp Map.hpp
	$(CPP) $(CPPFLAGS) -c GameGestion.cpp

LifeWindow.o: LifeWindow.cpp Heart.hpp
	$(CPP) $(CPPFLAGS) -c LifeWindow.cpp

KeyWindow.o: KeyWindow.cpp Player.hpp
	$(CPP) $(CPPFLAGS) -c KeyWindow.cpp

UserInterface.o: UserInterface.cpp TexturesLib.hpp SoundsLib.hpp
	$(CPP) $(CPPFLAGS) -c UserInterface.cpp

Player.o: Player.cpp Character.hpp Arrow.hpp Monster.hpp SoundsLib.hpp
	$(CPP) $(CPPFLAGS) -c Player.cpp

Map.o: Map.cpp Object.hpp Monster.hpp Door.hpp DoorWall.hpp Ground.hpp GoldenChest.hpp WallZone.hpp FinalBoss.hpp MeleeMonster.hpp DemonDogMonster.hpp RangedMonster.hpp FlyMonster.hpp MiniFrogMonster.hpp MiniOgre.hpp GuerrierOgre.hpp
	$(CPP) $(CPPFLAGS) -c Map.cpp

Heart.o: Heart.cpp TexturesLib.hpp
	$(CPP) $(CPPFLAGS) -c Heart.cpp

TexturesLib.o: TexturesLib.cpp 
	$(CPP) $(CPPFLAGS) -c TexturesLib.cpp

Object.o: Object.cpp TexturesLib.hpp SoundsLib.hpp
	$(CPP) $(CPPFLAGS) -c Object.cpp

Character.o: Character.cpp Object.hpp EnumOrientation.hpp Heart.hpp Chest.hpp
	$(CPP) $(CPPFLAGS) -c Character.cpp

Arrow.o: Arrow.cpp Projectile.hpp Player.hpp
	$(CPP) $(CPPFLAGS) -c Arrow.cpp

Monster.o: Monster.cpp Player.hpp
	$(CPP) $(CPPFLAGS) -c Monster.cpp

Door.o:	Door.cpp Wall.hpp Player.hpp
	$(CPP) $(CPPFLAGS) -c Door.cpp

DoorWall.o: DoorWall.cpp Door.hpp
	$(CPP) $(CPPFLAGS) -c DoorWall.cpp

GoldenChest.o: GoldenChest.cpp Chest.hpp
	$(CPP) $(CPPFLAGS) -c GoldenChest.cpp

FinalBoss.o: FinalBoss.cpp Monster.hpp Fireball.hpp
	$(CPP) $(CPPFLAGS) -c FinalBoss.cpp

MeleeMonster.o: MeleeMonster.cpp Monster.hpp
	$(CPP) $(CPPFLAGS) -c MeleeMonster.cpp

RangedMonster.o: RangedMonster.cpp Monster.hpp Fireball.hpp
	$(CPP) $(CPPFLAGS) -c RangedMonster.cpp

FlyMonster.o: FlyMonster.cpp MeleeMonster.hpp
	$(CPP) $(CPPFLAGS) -c FlyMonster.cpp

MiniFrogMonster.o: MiniFrogMonster.cpp MeleeMonster.hpp
	$(CPP) $(CPPFLAGS) -c MiniFrogMonster.cpp

MiniOgre.o: MiniOgre.cpp MeleeMonster.hpp
	$(CPP) $(CPPFLAGS) -c MiniOgre.cpp

GuerrierOgre.o: GuerrierOgre.cpp MeleeMonster.hpp
	$(CPP) $(CPPFLAGS) -c GuerrierOgre.cpp

Chest.o: Chest.cpp Tile.hpp Prise.hpp Projectile.hpp Character.hpp
	$(CPP) $(CPPFLAGS) -c Chest.cpp

Projectile.o: Projectile.cpp Object.hpp
	$(CPP) $(CPPFLAGS) -c Projectile.cpp

Wall.o: Wall.cpp Tile.hpp TypeWall.hpp Projectile.hpp SoundsLib.hpp
	$(CPP) $(CPPFLAGS) -c Wall.cpp

Fireball.o: Fireball.cpp Projectile.hpp Character.hpp Player.hpp
	$(CPP) $(CPPFLAGS) -c Fireball.cpp

SoundsLib.o: SoundsLib.cpp
	$(CPP) $(CPPFLAGS) -c SoundsLib.cpp


the_game: main.o GameWindow.o GameGestion.o LifeWindow.o KeyWindow.o UserInterface.o Player.o Map.o Heart.o TexturesLib.o Object.o Character.o Arrow.o Monster.o Door.o DoorWall.o GoldenChest.o FinalBoss.o MeleeMonster.o RangedMonster.o FlyMonster.o MiniFrogMonster.o MiniOgre.o GuerrierOgre.o Chest.o Projectile.o Wall.o Fireball.o SoundsLib.o
	$(LD) $(LDFLAGS) main.o GameWindow.o GameGestion.o LifeWindow.o KeyWindow.o UserInterface.o Player.o Map.o Heart.o TexturesLib.o Object.o Character.o Arrow.o Monster.o Door.o DoorWall.o GoldenChest.o FinalBoss.o MeleeMonster.o RangedMonster.o FlyMonster.o MiniFrogMonster.o MiniOgre.o GuerrierOgre.o Chest.o Projectile.o Wall.o Fireball.o SoundsLib.o -o the_game $(LIBS)


clean:
	rm -f *.o the_game