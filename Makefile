

.PHONY: all

all: main

main: main.c
	gcc -Wall main.c -o main
