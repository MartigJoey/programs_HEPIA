CC:=gcc
CFLAGS:=-g -O3 -Wall -Wextra -fsanitize=address
LDFLAGS:=-lm
VPATH:=array_uni

array_uni: main.o tableau_uni.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -lSDL2

tableau_uni.o: tableau_uni.h

clean:
	rm -f *.o array_uni
