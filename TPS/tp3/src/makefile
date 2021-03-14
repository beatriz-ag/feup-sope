#c compiler
CC := cc


CFLAGS := -Wall -o
all: ex1 ex2 ex2aux ex3


ex1: ex1.c
	$(CC) $(CFLAGS) ex1 ex1.c

ex2: ex2.c 
	$(CC) -pthread -Wall -o ex2 ex2.c

ex2aux: ex2aux.c
	$(CC) -pthread -Wall -o ex2aux ex2aux.c

ex3: ex3.c
	$(CC) $(CFLAGS) ex3 ex3.c


clean:
	rm -f ex1 ex2 ex2aux ex3