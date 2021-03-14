#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/mman.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void readDirFIle(const char *path)
{
    DIR *directory;

    if ((directory = opendir(path)) == NULL)
    {
        printf("Error openning directory\n");
    }

    struct dirent *file;
    struct stat s;
    while ((file = readdir(directory)) != NULL)
    {
        if (!strcmp(file->d_name, ".") || !strcmp(file->d_name, ".."))
            continue;

        char *nextPath = malloc(sizeof(path) + 1 + sizeof(file->d_name));
        strcpy(nextPath, path);
        strcat(nextPath, "/");
        strcat(nextPath, file->d_name);
        stat(nextPath, &s);

        if (S_ISDIR(s.st_mode))
        {
            int pid = fork();
            if (pid == 0)
            {
                readDirFIle(nextPath);
                exit(0);
            }
            else
                wait(pid);
        }
        else
        {
            stat(file->d_name, &s);
            printf("file name: %s - ", file->d_name);
            printf(" size: %ld\n", s.st_size);
        }
    }
    closedir(directory);
}
int main(int argc, char *argv[])
{

    if (argc == 1)
        fprintf(stderr, "missing args\n");
    readDirFIle(argv[1]);
}