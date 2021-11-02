CC:=gcc
CFLAGS:=-g -O3 -Wall
LDFLAGS:=-lm
VPATH:=tableau_uni

t_uni: main.o tableau_uni.o histogrammes.o compute.o sort.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

tableau_uni.o: tableau_uni.h
histogrammes.o: tableau_uni.h
compute.o: tableau_uni.h
sort.o: tableau_uni.h

clean:
	rm -f *.o t_uni
