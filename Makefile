all: main geometry

main: main.c
	gcc -Wall -Werror -o main main.c

geometry: geometry.c
	gcc -Wall -Werror -o geometry geometry.c
