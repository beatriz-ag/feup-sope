#c compiler
CC := cc

#directories
BIN := ../bin

CFLAGS := -Wall -o
all: ex4 ex5 ex6 ex10 ex11 ex12


ex4: ex4.c
	$(CC) -static -o $(BIN)/ex4 ex4.c

ex5: ex5.c
	$(CC) $(CFLAGS) $(BIN)/ex5 ex5.c

ex6: ex6.c
	$(CC) $(CFLAGS) $(BIN)/ex6 ex6.c

ex10: ex10.c 
	$(CC) $(CFLAGS) $(BIN)/ex10 ex10.c

ex11: ex11.c 
	$(CC) $(CFLAGS) $(BIN)/ex11 ex11.c

ex12: ex12.c
	$(CC) $(CFLAGS) $(BIN)/ex12 ex12.c

clean:
	rm -f $(BIN)/ex4 $(BIN)/ex5 $(BIN)/ex6 $(BIN)/ex10 $(BIN)/ex11 $(BIN)/ex12