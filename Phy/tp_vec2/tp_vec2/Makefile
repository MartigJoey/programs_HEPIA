#The compiler
CC:=gcc
#The flags passed to the compiler
CFLAGS:=-g -O3 -Wall -Wextra -fsanitize=address -fsanitize=leak -std=gnu11
#The flags passed to the linker
LDFLAGS:=-lm
#Path to the lib Vec2
VPATH:=vec2 gfx

run_tests: tests
	./$<

main: main.o vec2.o gfx.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -lSDL2

tests: vec_tests.o vec2.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

vec2.o: vec2.h

gfx.o: gfx.h

clean:
	rm -f *.o main tests
