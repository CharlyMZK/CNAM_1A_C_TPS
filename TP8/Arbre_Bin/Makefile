
all: arbre_bin1 arbre_bin2 arbre_bin_tri

clean:
	rm *.o arbre_bin1 arbre_bin2 arbre_bin_tri


arbre_bin1: arbre_bin1.c 
	gcc arbre_bin1.c -o arbre_bin1

arbre_bin_tri: arbre_bin_tri.c arbre_bin_tri.h
	gcc -O3 arbre_bin_tri.c -o arbre_bin_tri -lm


arbre_bin2: arbre_bin2.o file.o
	gcc arbre_bin2.o file.o -o arbre_bin2

arbre_bin.o: arbre_bin2.h arbre_bin2.c file.h
	gcc -c arbre_bin2.c

file.o: file.h file.c
	gcc -c file.c

