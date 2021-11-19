CC:=gcc
CFLAGS:=-g -O3 -fsanitize=address
LDFLAGS:=-lm

matrix: matrix_compute.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -lSDL2

tests: matrix_test.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

matrix.o: matrix.h

clean:
	rm -f *.o matrix tests
