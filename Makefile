CC ?= gcc
CFLAGS ?= -Wall -g -Wall -Werror -pedantic
DESTDIR ?= /usr/bin

.PHONY: test clean all install uninstall

all:
	@echo available recipes: ndvd test clean

%.o: %.c
	@${CC} -c ${CFLAGS} $<

ndvd: src/ndvd.o src/dvd.o
	@${CC} -lncurses *.o -o $@

test: ndvd
	@./$^

install: ndvd
	@install -vDm0755 ndvd "${DESTDIR}/ndvd"

uninstall:
	@rm -v "${DESTDIR}/ndvd"

clean:
	@rm -v ndvd *.o
