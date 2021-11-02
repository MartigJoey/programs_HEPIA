CC:=gcc
CFLAGS:=-g -O3 -Wall -Wextra
LDFLAGS:=-lm
VPATH:=bissection

biss: main.o bissection.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

bissection.o: bissection.h

clean:
	rm -f *.o biss
