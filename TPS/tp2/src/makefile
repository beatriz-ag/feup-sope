#c compiler
CC := cc


CFLAGS := -Wall -o
all: ex5 ex8 ex9 ex10 ex13


ex4: ex5.c
	$(CC) -static -o ex4 ex4.c

ex6: ex8.c
	$(CC) $(CFLAGS) ex8 ex8.c

ex10: ex9.c 
	$(CC) $(CFLAGS) ex9 ex9.c

ex11: ex10.c 
	$(CC) $(CFLAGS) ex10 ex10.c

ex12: ex13.c
	$(CC) $(CFLAGS)ex13 ex13.c

clean:
	rm -f ex5 ex8 ex9 ex10 ex13