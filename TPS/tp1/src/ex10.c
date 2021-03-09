#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int main(){
    clock_t begin = clock();

    for (int x = 0; x < 100000; x++)
    {
        printf("Hello World\n");
    }

    clock_t end = clock();

    double duration = (double)(end-begin) / CLOCKS_PER_SEC;

    printf("Program's duration was %f seconds.\n",duration);
}