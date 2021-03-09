#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>



int main(int argc, char * argn[])
{

    if (argc != 3) return 1;

    int fd;

    if ((fd = open(argn[1],O_RDONLY))== -1) return 1;

    size_t n = (size_t)atoi(argn[2]);

    void *buf = malloc(sizeof(n));

    n = read(fd,buf,n);

    for(size_t i = 0; i < n; i++) printf("%c", ((char*)buf)[i]);
    
    return 0;
}