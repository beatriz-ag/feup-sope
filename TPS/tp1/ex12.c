#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc,char *argv[]){
    DIR* directory ;
    
    if(( directory = opendir(argv[1])) == NULL){
        printf("Error openning directory\n");
        return 1;
    }

    struct dirent* entry;
    struct stat s;
    while((entry = readdir(directory)) != NULL)
    {
        printf("file name: %s - ", entry->d_name);
        stat(entry->d_name,&s);
        printf(" size: %ld\n",s.st_size);
    }
    closedir(directory);

}