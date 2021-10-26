EXEC = primes primes-i steg-decode
OBJS = error.o eratosthenes.o primes.o
CC = gcc
CFLAGS = -g -O2 -std=c11 -pedantic -Wall -Wextra
LDFLAGS = -lm
HEADS = bitset.h error.h eratosthenes.h

all: $(EXEC)

primes: $(OBJS)

primes-i: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) -DUSE_INLINE

steg-decode: error.o ppm.o eratosthenes.o steg-decode.o

eratosthenes.o: eratosthenes.c $(HEADS)

error.o: error.c

ppm.o: ppm.c error.h ppm.h

primes.o: primes.c $(HEADS)

steg-decode.o: steg-decode.c ppm.h $(HEADS)

.PHONY: clean

clean:
	rm -f *.o
	rm -f $(EXEC)

pack:
	zip xkrizo05.zip *.c *.h Makefile

run:
	make
	ulimit -s 125000 && ./primes ; ./primes-i
	./steg-decode du1-obrazek.ppm
