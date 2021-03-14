#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/mman.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    pid_t fork1, fork2;
    if ((fork1 = fork()) == -1)
    {
        fprintf(stderr, "fork error");
        exit(1);
    }

    if (fork1 == 0){    //First Fork son       - 2nd process
        if ((fork2 = fork()) == -1)
        {
            fprintf(stderr, "fork error");
            exit(1);
        }
        
        if (fork2 == 0){    //Second Fork son  - 3rd process
        }
        else{}
    }
    else{

        pid_t sessi
    }
}