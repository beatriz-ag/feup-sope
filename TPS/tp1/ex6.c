#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


int main(int argn, char *argc[], char * envc[])
{
    int opening_result;
    
    printf("\nExc.6.a)\n");

    if ((opening_result = open(argc[1],O_RDONLY)) == -1){
        printf("%s\n","Error opening file.");
    }
    

    printf("\nExc.6.b)\n");
    
    if ((opening_result = open(argc[1],O_RDONLY)) == -1){
        fprintf(stderr,"%s","Error opening the file\n");
    }

    printf("\nExc.6.c)\n");

    if ((opening_result = open(argc[1],O_RDONLY)) == -1){
        perror("hello");
    }
    

}