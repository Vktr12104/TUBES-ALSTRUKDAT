all: run clean

test: main.c 
	gcc -o main main.c 

run: test
	./main.exe

clean:
	del main.exe