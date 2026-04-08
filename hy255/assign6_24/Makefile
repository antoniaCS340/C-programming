CC = gcc
CFLAGS = -Wall -ansi -pedantic -g

all: data3 data6 data9
data3: src/createdata3.o
	$(CC) $(CFLAGS) $^ -o $@
	./data3
	-rm -f $@
data6: src/createdata6.o
	$(CC) $(CFLAGS) $^ -o $@
	./data6
	-rm -f $@
data9: src/createdata9.o
	$(CC) $(CFLAGS) $^ -o $@
	./data9
%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-rm -f ./src/*.o
	-rm -f data3.in data6.in data9.in