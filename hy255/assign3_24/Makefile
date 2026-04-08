###################################################
#
# file: Makefile
#
# @Author:   Iacovos G. Kolokasis
# @Version:  10-02-2022
# @email:    kolokasis@csd.uoc.gr
#
# Makefile
#
####################################################

CFLAGS = -ansi -pedantic -Wall

all: list.exe hash.exe

list.exe: src/main.o src/symtablelist.o
	gcc $(CFLAGS) $^ -o $@

hash.exe: src/main.o src/symtablehash.o
	gcc $(CFLAGS) $^ -o $@

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	-rm -f *.exe ./src/*.o
