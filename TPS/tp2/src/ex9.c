#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

#define NTHREADS 3

void *rot(void *a) {
	printf("\n\t In thread PID: %d ; TID: %lu.", getpid(), (unsigned long) pthread_self());
    *(int*) a *= *(int*)a;
    printf("Creation number:  %d\n", *(int *)a);
    

	pthread_exit(a);
	}

int main() {

	int i;	// thread counter
	pthread_t ids[NTHREADS];	// storage of (system) Thread Identifiers
    

    setbuf (stdout, NULL);	// only for debugging
    printf("\nMain thread PID: %d ; TID: %lu.\n", getpid(), (unsigned long) pthread_self());

    // new threads creation
    for(i=0; i<NTHREADS; i++) {
        int *a = malloc(sizeof(int));
        *a = i;
    	if (pthread_create(&ids[i], NULL, rot,(void*)a )!= 0)
    		exit(-1);	// here, we decided to end process
    	else
    		printf("\nNew thread %d ; TID: %lu.", i, (unsigned long) ids[i]);
	}

    // wait for finishing of created threads
    for(i=0; i<NTHREADS; i++) {
        void* returnI;
	    pthread_join(ids[i], &returnI);	// Note: threads give no termination code
	    printf("\nTermination of thread %d: %lu.\n Creation number squared: %d.\n", i, (unsigned long)ids[i], *(int*)returnI);
	}

    printf("\n");
    pthread_exit(NULL);	// here, not really necessary...
    return 0;	// will not run this!
}