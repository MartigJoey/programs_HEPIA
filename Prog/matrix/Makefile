CC:=gcc
CFLAGS:=-g -O3 -fsanitize=address
LDFLAGS:=-lm

matrix: main.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -lSDL2

matrix.o: matrix.h

clean:
	rm -f *.o matrix
