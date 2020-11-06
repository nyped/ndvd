CC := gcc
CFLAGS := -Wall -g -Wall -Werror -pedantic

all: Ndvd

%.o: %.c
	${CC} -c ${CFLAGS} $<

Ndvd: Ndvd.o dvd.o
	gcc -lncurses *.o -o $@

.PHONY: test clean

test: Ndvd
	./$^

clean:
	rm Ndvd *.o
