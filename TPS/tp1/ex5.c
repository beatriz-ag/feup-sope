#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argn, char *argc[],char *envc[]){
    printf("Exc.5.a)\n");

    //command line arguments
    for (int i = 0; i < argn; i++)
    {
        printf("%s\n",argc[i]);
    }

    //environment variables
    char *env;
    for (int i = 0; (env = envc[i])!= NULL;i++)
    {
        printf("%s\n",envc[i]);
    }

    printf("Exc.5.b)\n");

    for(int i = 0; i < argn; i++)
    {
        char *env;
        for (int j = 0; (env = envc[j])!= NULL; j++){
            
            if(strcmp(env,argc[i]) == 0){
                printf("%s\n",env);
            }
        }
    }

    return 0;
}