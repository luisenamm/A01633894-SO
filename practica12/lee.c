#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <fcntl.h>





int main(int argn,char **argv){
    char *fileName=argv[1];
    char buffer;
    int fd =open(fileName,O_RDONLY);
    if(fd<0){
        printf("No se puede abrir \n");
        exit(1);
    }
    while(read(fd,&buffer, 1)){
        printf("%d ",buffer);
    }
    close(fd);
    exit(0);
}