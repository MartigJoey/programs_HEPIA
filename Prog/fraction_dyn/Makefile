CC:=gcc
CFLAGS:=-g -O3 -Wall -Wextra
LDFLAGS:=-lm
VPATH:=fraction

frac: main.o fraction.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -lSDL2

fraction.o: fraction.h

clean:
	rm -f *.o frac
