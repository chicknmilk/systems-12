all: main.c
	gcc -o ls main.c

run:
	./ls