all: run clean

test: main.c ADT/ADT_Mesin-Kata/mesinkata.c ADT/ADT_MesinKarakter/mesinkarakter.c
	gcc -o main main.c ADT/ADT_Mesin-Kata/mesinkata.c ADT/ADT_MesinKarakter/mesinkarakter.c

run: test
	./main.exe

clean:
	del main.exe