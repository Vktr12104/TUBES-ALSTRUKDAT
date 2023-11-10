all: run clean

test: main.c Source/ADT/ADT_Mesin-Kata/mesinkata.c Source/ADT/ADT_MesinKarakter/mesinkarakter.c Source/ADT/ADT_Map/map.c Source/ADT/ADT_Set/set.h
	gcc -o main main.c Source/ADT/ADT_Mesin-Kata/mesinkata.c Source/ADT/ADT_MesinKarakter/mesinkarakter.c Source/ADT/ADT_Map/map.c Source/ADT/ADT_Set/set.h

run: test
	./main.exe

clean:
	del main.exe