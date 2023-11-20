all: run clean

test: main.c Source/ADT/ADT_Mesin-Kata/mesinkata.c Source/ADT/ADT_MesinKarakter/mesinkarakter.c Source/ADT/ADT_List/liststatis.c Source/ADT/ADT_Set/set.c Source/ADT/ADT_Map/map.c Source//command/start.c Source/ADT/ADT_Queue/circular_queue.c Source/console.c
	gcc -o main main.c Source/ADT/ADT_Mesin-Kata/mesinkata.c Source/ADT/ADT_MesinKarakter/mesinkarakter.c Source/ADT/ADT_List/liststatis.c Source/ADT/ADT_Set/set.c Source/ADT/ADT_Map/map.c Source/command/start.c Source/command/list.c Source/ADT/ADT_Queue/circular_queue.c Source/console.c

run: test
	./main.exe

clean:
	del main.exe