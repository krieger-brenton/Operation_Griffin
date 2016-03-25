CC = g++
CFLAGS = -g -Wall -std=c++11

windows: Main.cpp Item.o Armor.o Character.o Enemy.o EventHandler.o GameData.o GameLogic.o Map.o Random.o mtrand.o Store.o Weapon.o
	$(CC) $(CFLAGS) -DWINDOWS -o griffin.out Main.cpp Item.o Armor.o Character.o Enemy.o EventHandler.o GameData.o GameLogic.o Map.o Random.o mtrand.o Store.o Weapon.o

linux: Main.cpp Item.o Armor.o Character.o Enemy.o EventHandler.o GameData.o GameLogic.o Map.o Random.o mtrand.o Store.o Weapon.o
	$(CC) $(CFLAGS) -DLINUX -o griffin.out Main.cpp Item.o Armor.o Character.o Enemy.o EventHandler.o GameData.o GameLogic.o Map.o Random.o mtrand.o Store.o Weapon.o

Item.o: Item.cpp Item.h
	$(CC) $(CFLAGS) -c Item.cpp

Armor.o: Armor.cpp Armor.h Item.o
	$(CC) $(CFLAGS) -c Armor.cpp

Character.o: Character.cpp Character.h GameData.o Weapon.o Armor.o CPoint.h
	$(CC) $(CFLAGS) -c Character.cpp 

Enemy.o: Enemy.cpp Character.o GameData.o GameLogic.o
	$(CC) $(CFLAGS) -c Enemy.cpp

EventHandler.o: EventHandler.cpp EventHandler.h GameData.o Event.h
	$(CC) $(CFLAGS) -c EventHandler.cpp

GameData.o: GameData.cpp GameData.h Character.o Map.o Store.o
	$(CC) $(CFLAGS) -c GameData.cpp

GameLogic.o: GameLogic.cpp GameLogic.h EventHandler.o
	$(CC) $(CFLAGS) -c GameLogic.cpp

Map.o: Map.cpp Map.h Character.o CPoint.h
	$(CC) $(CFLAGS) -c Map.cpp

Random.o: Random.cpp Random.h
	$(CC) $(CFLAGS) -c Random.cpp

mtrand.o: mtrand.cpp mtrand.h
	$(CC) $(CFLAGS) -c mtrand.cpp

Store.o:	Store.cpp Store.o Armor.o Weapon.o mtrand.o Item.o
	$(CC) $(CFLAGS) -c Store.cpp

Weapon.o: Weapon.cpp Weapon.h Item.o
	$(CC) $(CFLAGS) -c Weapon.cpp

clean:
	rm *.o *.out
