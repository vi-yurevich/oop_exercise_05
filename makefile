CC=g++
CFLAGS=-std=c++14 -pedantic
OUTPUT=oop_exercise_05

all:
	$(CC) $(CFLAGS) Rhombus.h List.h main.cpp -o $(OUTPUT)
run:
	./$(OUTPUT)