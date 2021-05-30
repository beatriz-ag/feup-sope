#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i = 1234567;

    int fd = open("ex4.txt",O_WRONLY);
    write (fd, &i, sizeof (i));

    printf("\n%d", i);
    return 0;
}
