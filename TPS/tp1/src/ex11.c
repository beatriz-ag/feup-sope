#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int a(int argc, char *argv[]){

    int file1,file2;

    if ((file1 = open(argv[1],O_RDONLY)) == -1){
        printf("Error opening file1\n");
        return 1;
    }

    if ((file2 = open(argv[2],O_WRONLY)) == -1){
        printf("Error opening file2\n");
        return 1;
    }
    
    char buf[1024];
    int reader;
    while((reader = read(file1,buf,1024)) > 0)
    {
        if(write(file2,buf,1024) == -1)
        {
            printf("Error writting to file2.\n");
            return 1;
        }
    }

    close(file1);
    close(file2);
    return 0;
}

int b(int argc, char *argv[]){
    FILE *file1, *file2;

    if ((file1 = fopen(argv[1],"r"))==NULL){
        printf("Error opening file1.\n");
        return 1;
    }

    if ((file2 = fopen(argv[2],"w"))==NULL){
        printf("Error opening file2.\n");
        return 1;
    }

    char c;

    c = fgetc(file1);

    while(c != EOF)
    {
        fputc(c,file2);
        c = fgetc(file1);
    }

    fclose(file1);
    fclose(file2);
    return 0;
}

int c(int argc, char *argv[]){
 //Changing 11.b

 FILE *file1, *file2;

    if ((file1 = fopen(argv[1],"r"))==NULL){
        printf("Error opening file1.\n");
        return 1;
    }

 char c;

    if ((file2 = fopen(argv[2],"w"))==NULL){

    c = fgetc(file1);

    while(c != EOF)
    {
        printf("%d\n",c);
        c = fgetc(file1);
    }

    fclose(file1);

    }


    c = fgetc(file1);

    while(c != EOF)
    {
        fputc(c,file2);
        c = fgetc(file1);
    }

    fclose(file1);
    fclose(file2);
    return 0;
}

int main(int argc, char *argv[]){
    a(argc,argv);
    b(argc,argv);
    c(argc,argv);
    return 0;

}
