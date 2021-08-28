CC ?= gcc
CFLAGS ?= -Wall -g -Wall -Werror -pedantic
DESTDIR ?= /usr

.PHONY: test clean all install uninstall

all:
	@echo available recipes: ndvd test clean {,un}install

%.o: %.c
	@${CC} -c ${CFLAGS} $<

ndvd.bin: src/ndvd.o src/dvd.o
	@${CC} -lncurses *.o -o $@

test: ndvd.bin
	@./$^

install: ndvd.bin
	@install -vDm0755 ndvd.bin "${DESTDIR}/bin/ndvd"

uninstall:
	@rm -v "${DESTDIR}/ndvd"

clean:
	@rm -v ndvd *.o
