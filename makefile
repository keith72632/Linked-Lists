main: main.c
	gcc -o main main.c
debug:
	gcc -g -o main main.c
	gdb main