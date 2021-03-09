#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define NTHREADS 2

struct info{
    char *string;
    int id;
    int *done;
};


void *printMessage(void *a) {
    struct info* infoP = (struct info*)a;
    if (infoP->id == 0){ 
        printf("%s ",infoP->string);
        *infoP->done = 1;
    }
    else {
        while(!*infoP->done);
        printf(" %s",infoP->string);
    } 

	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

    if (argc < 3) return -1;

    struct info infoT1, infoT2;
    pthread_t thread1,thread2;
    int d = 0;

    infoT1.id = 0;
    infoT1.string = argv[1];
    infoT1.done = &d;
   

    infoT2.id = 1;
    infoT2.string = argv[2];
    infoT2.done = &d;
    

    if (pthread_create(&thread1, NULL, printMessage, &infoT1 )!= 0)
    	exit(-1);	
    if (pthread_create(&thread2, NULL, printMessage,&infoT2 )!= 0)
        exit(-1);	
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);	

    pthread_exit(NULL);	// here, not really necessary...
    return 0;	// will not run this!
}