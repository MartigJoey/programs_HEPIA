CC:=gcc
CFLAGS:=-g -O3 -Wall -Wextra
LDFLAGS:=-lm
VPATH:=fraction calcul_de_pi

frac: main.o fraction.o calcul_de_pi.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

fraction.o: fraction.h
calcul_de_pi.o: fraction.h

clean:
	rm -f *.o frac
