#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int stop = 1;

void sigusr1Handler(int signo) {  
    fprintf(stderr, "\nSIGUSR1 handler\n");
    stop =0;
}

void sigInHandler(int signo) {  
    fprintf(stderr, "\nSIGINT handler\n");
    stop = 0;
}

int main(int argc, char *argv[])
{
    struct sigaction new, old,new2, old2;
	sigset_t smask;	

    // prepare struct sigaction
    if (sigemptyset(&smask)==-1)	
	    perror ("sigsetfunctions");

    new.sa_handler = sigInHandler;
    new.sa_mask = smask;
    new.sa_flags = 0;	

    if(sigaction(SIGINT, &new, &old) == -1)
	    perror ("sigaction");

    new2.sa_handler = sigusr1Handler;
    new2.sa_mask = smask;
    new2.sa_flags = 0;

    if(sigaction(SIGUSR1, &new2, &old2) == -1)
	    perror ("sigaction");

    int status;
    pid_t fork1, fork2;
    
    if ((fork1 = fork()) == 0){ 
        
        if ((fork2 = fork()) == 0){   
            pid_t sess = getsid(getpid());
            pid_t grp = getpgrp();
            pid_t pid = getpid();
            printf("PID: %d  ; GROUP ID: %d ; SESSION ID: %d\n",pid,grp,sess);
        }
        else{
            wait(&status);
            pid_t sess = getsid(getpid());
            pid_t grp = getpgrp();
            pid_t pid = getpid();
            printf("PID: %d  ; GROUP ID: %d ; SESSION ID: %d\n",pid,grp,sess);   //First Fork son       - 2nd process
        }
    }
    else{

        wait(&status);
        pid_t sess = getsid(getpid());
        pid_t grp = getpgrp();
        pid_t pid = getpid();
        printf("PID: %d  ; GROUP ID: %d ; SESSION ID: %d\n",pid,grp,sess);
		
    }

    while(stop);  //All processes receive both signals
    
    return 0;
}