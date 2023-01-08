CC = g++
CFLAGS = -Wall -g -pedantic
OBJECTS = obj/main.o obj/battlefield.o obj/character.o obj/weapon.o
TARGET = melee

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

obj/main.o: src/main.cpp obj/battlefield.o obj/character.o obj/weapon.o
	$(CC) -c src/main.cpp -o obj/main.o


obj/battlefield.o: src/battlefield.h obj/character.o
	$(CC) -c src/battlefield.cpp -o obj/battlefield.o

obj/character.o: src/character.h obj/weapon.o
	$(CC) -c src/character.cpp -o obj/character.o

obj/weapon.o: src/weapon.h
	$(CC) -c src/weapon.cpp -o obj/weapon.o

clean:
	-rm obj/*.o

install:
	@echo Compiling Melee Warrior...
	make