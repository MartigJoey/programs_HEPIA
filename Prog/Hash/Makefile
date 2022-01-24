CC:=gcc
CFLAGS:=-g -O3 -Wextra -pedantic -fsanitize=address
LDFLAGS:=-lm
NAME:=hash

main: main.o $(NAME).o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -lSDL2

tests: $(NAME)_tests.o $(NAME).o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)make

$(NAME).o: $(NAME).h

clean:
	rm -f *.o $(NAME) tests main
