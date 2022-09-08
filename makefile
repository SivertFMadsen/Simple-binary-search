FLAGS = -g -Wall -Wextra -std=gnu11
VFLAGS = --track-origins=yes --malloc-fill=0x40 --leak-check=full --show-leak-kinds=all

all: binaersoek

binaersoek: binaersoek.c
	gcc $(FLAGS) binaersoek.c -o binaersoek

run: binaersoek
	./binaersoek

valgrind: binaersoek
	valgrind $(VFLAGS) ./binaersoek