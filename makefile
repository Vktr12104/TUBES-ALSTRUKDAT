all: run clean

test: main.c Source/ADT/ADT_Mesin-Kata/mesinkata.c Source/ADT/ADT_MesinKarakter/mesinkarakter.c Source/ADT/ADT_List/liststatis.c Source/ADT/ADT_List/listdinamis.c Source/ADT/ADT_LinkedList/listb.c Source/ADT/ADT_Detail/isilagu.c Source/ADT/ADT_Set/set.c Source/ADT/ADT_Map/map.c Source/command/start.c Source/command/playlist.c Source/ADT/ADT_Queue/circular_queue.c Source/console.c Source/ADT/ADT_Stack/stack.c
	gcc -o main main.c Source/ADT/ADT_Mesin-Kata/mesinkata.c Source/ADT/ADT_MesinKarakter/mesinkarakter.c Source/ADT/ADT_List/liststatis.c Source/ADT/ADT_List/listdinamis.c Source/ADT/ADT_LinkedList/listb.c Source/ADT/ADT_Detail/isilagu.c Source/ADT/ADT_Set/set.c Source/ADT/ADT_Map/map.c Source/command/start.c  Source/command/playlist.c Source/command/list.c Source/ADT/ADT_Queue/circular_queue.c Source/console.c Source/ADT/ADT_Stack/stack.c 

run: test
	./main.exe

clean:
	del main.exe