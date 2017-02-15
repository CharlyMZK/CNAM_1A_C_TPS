
# Optimization/debug flag: debug -g / optim -O3
CFLAGS = -g

all: test_liste_simple test_liste_double test_liste_tableau bench_liste_simple bench_liste_double bench_liste_tableau

clean:
	rm test_liste_simple test_liste_double test_liste_tableau bench_liste_simple bench_liste_double bench_liste_tableau liste_simple.o liste_double.o liste_tableau.o


liste_simple.o: liste_simple.c liste_simple.h
	gcc $(CFLAGS) -c liste_simple.c
	
test_liste_simple: test_liste_simple.c liste_simple.h liste_simple.o
	gcc $(CFLAGS) test_liste_simple.c liste_simple.o -o test_liste_simple

liste_double.o: liste_double.c liste_double.h
	gcc $(CFLAGS) -c liste_double.c
	
test_liste_double: test_liste_double.c liste_double.h liste_double.o
	gcc $(CFLAGS) test_liste_double.c liste_double.o -o test_liste_double


liste_tableau.o: liste_tableau.c liste_tableau.h
	gcc $(CFLAGS) -c liste_tableau.c
	
test_liste_tableau: test_liste_tableau.c liste_tableau.h liste_tableau.o
	gcc $(CFLAGS) test_liste_tableau.c liste_tableau.o -o test_liste_tableau


bench_liste_simple: bench_liste.c liste_simple.h liste_simple.o
	gcc $(CFLAGS) -D SIMPLE=1 bench_liste.c liste_simple.o -o bench_liste_simple

bench_liste_double: bench_liste.c liste_double.h liste_double.o
	gcc $(CFLAGS) -D DOUBLE=1 bench_liste.c liste_double.o -o bench_liste_double

bench_liste_tableau: bench_liste.c liste_tableau.h liste_tableau.o
	gcc $(CFLAGS) -D TABLEAU=1 bench_liste.c liste_tableau.o -o bench_liste_tableau
