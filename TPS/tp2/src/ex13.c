#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int ex13a(){
    pid_t pid;
    int pp[2];
    char msg[1024];

    if (pipe(pp) == -1 ){perror("pipe()"); exit(1);}

    if ((pid = fork())== -1){perror("fork()");exit(2);}

    if (pid == 0){ //child
        close(pp[1]);
        read(pp[0],msg,1024);
        printf("%s Systems",msg);
        close(pp[0]);
    }
    else{
        close(pp[0]);
        write(pp[1],"Operating",10);
    }

    return 0;
}

int ex13b(){
    int np;
    pid_t pid;
    char msg[10];

    if (mkfifo("np",0666) < 0) perror ("mkfifo");

    if ((pid = fork())== -1){perror("fork()");exit(2);}

    if (pid == 0){ //child
        while((np = open("np",O_RDONLY))< 0);
        read(np,msg,10);
        printf("%s Systems",msg);
        close(np);
    }
    else{
        while((np = open("np",O_WRONLY))< 0);
        write(np,"Operating",10);
        close(np);
    }

    return 0;
}


int ex13c(){
    pid_t pid;
    int pp[2];
    char msg[1024];

    if (pipe(pp) == -1 ){perror("pipe()"); exit(1);}

    if ((pid = fork())== -1){perror("fork()");exit(2);}

    if (pid == 0){ //child
        read(pp[0],msg,10);
        close(pp[0]);
        printf("Child: %s Systems\n",msg);
        write(pp[1], "Systems",8);
        close(pp[1]);

        write(pp[1], "Systems",8);
        close(pp[1]);
        
    }
    else{

        write(pp[1],"Operating",10);
        close(pp[1]);
        wait(&pid);
        read(pp[0], msg,8);
        close(pp[0]);
        printf("Parent: Operating %s\n",msg);
    }

    return 0;
}

int ex13d(){
    int np1;
    pid_t pid;
    char msg[10];

    if (mkfifo("np1",0777) < 0) perror ("mkfifo");

    if ((pid = fork())== -1){perror("fork()");exit(2);}

    if (pid == 0){ //child
        while((np1 = open("np1",O_WRONLY))<= 0);
        write(np1,"Systems",8);
        close(np1);

        while((np1 = open("np1",O_RDONLY))< 0);
        read(np1,msg,10);
        close(np1);
        printf("%s Systems\n",msg);

    
    }
    else{
        while((np1 = open("np1",O_RDONLY))< 0);
        read(np1,msg,8);
        printf("Operating %s\n",msg);
        close(np1);

        while((np1 = open("np1",O_WRONLY))< 0);
        write(np1,"Operating",10);
        close(np1); 
        
    }

    return 0;
}



int main(){
    //ex13a();
    //ex13b();
    //ex13c();
   ex13d();
}