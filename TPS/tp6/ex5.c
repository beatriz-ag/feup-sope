#include<stdio.h>

void main(){

    printf("file marker | char\n");

    printf("Random access:\n");
    FILE *fp;
    fp = fopen("ex5.txt", "r");
    if(fp == NULL){
        printf("Cannot open file\n");
        return;
    }

    char ch;
    int fd;
    
    while((ch = fgetc(fp))!=EOF){
        fseek(fp,5,SEEK_CUR);
        ch = fgetc(fp);
        fd = ftell(fp);
        printf("%d\t%c\n",fd,ch);
    } 
    
    fclose(fp);


    printf("Sequential access:\n");
    fp = fopen("ex5.txt", "r");

    while((ch = fgetc(fp))!=EOF){
        fd = ftell(fp);
        printf("%d\t%c\n",fd,ch);
    }
    
    fclose(fp);

}
