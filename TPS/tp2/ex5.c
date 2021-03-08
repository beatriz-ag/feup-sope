#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    //a.
    pid_t pid;
    pid = fork();

    if (pid < 0)
        printf("fork error\n");
    else if (pid == 0)
        printf("Hello ");
    else
    {
        wait(&pid);
        printf("World!\n");
    }

    //Não há garantia que o pai escreva primeiro que o filho.
    //O filho nao sabe o que o pai esta a fazer mas o pai sabe do 
    //comportamento do filho.
   
}
