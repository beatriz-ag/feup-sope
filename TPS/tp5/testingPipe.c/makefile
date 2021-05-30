#c compiler
CC := cc


CFLAGS := -Wall -o
all: testingPipe1 testingPipe2


testingPipe1: testingPipe1.c
	$(CC) $(CFLAGS) testingPipe1 testingPipe1.c

testingPipe2: testingPipe2.c 
	$(CC)  $(CFLAGS) testingPipe2 testingPipe2.c

clean:
	rm -f testingPipe1 testingPipe2 