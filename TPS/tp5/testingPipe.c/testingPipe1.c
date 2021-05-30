
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

void readFromFIFO(char *myfifo){
    //Message message;
    char message[20];

    int fd = open(myfifo, O_RDONLY);
    fprintf(stderr,"oi");
    if (read(fd, message, sizeof(message)) == -1)
        fprintf(stderr,"error");
    fprintf(stderr,"alo");
    fprintf(stderr,"Message = %s\n", message);

  
    close(fd);
} 

int main(int argc, char *argv[])
{

    fprintf(stderr,"buhhh");
    readFromFIFO("fifo4332111");


    return 0;
}
