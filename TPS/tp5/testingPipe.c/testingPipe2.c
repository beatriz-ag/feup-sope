
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct {
	int rid; 										// request id
	pid_t pid; 										// process id
	pthread_t tid;									// thread id
	int tskload;									// task load
	int tskres;										// task result
} Message;

void initFIFO(char *myfifo){
    if(mkfifo(myfifo,0777) == -1){
        printf("ERRO\n");
    }
}


int writeToFIFO(char* message, char *fifo){
    int fd  = open(fifo, O_WRONLY);
    if(fd == -1){
        fprintf(stderr, "Error opening FIFO \n");
        return -1;
    }
    printf("oi");
        fprintf(stderr,"Message = %s\n", message);

    write(fd, message, sizeof(message));
    printf("qaaa");


    close(fd);
    return 1;
}

int main(int argc, char *argv[])
{
    Message message;
    message.rid = 1;
    message.pid = 2;
    message.tid = 3;
    message.tskload = 4;
    message.tskres = 5;
    char* msg = "testing";
    fprintf(stderr,"Message = %s\n", msg);

   while (1){
    if (writeToFIFO(msg,"fifo4332111") != -1)
        break;
   }

    return 0;
}