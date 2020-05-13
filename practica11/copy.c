#include <unistd.h>
#include <stdio.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc,char ** argv){
    int origin,destination,line,readline,writeline;
    char buf[512];
    char *originFilename=argv[1];
    char *dstFilename=argv[2];
    printf("%s %s\n", originFilename,dstFilename);

    if((origin=open(originFilename,O_RDONLY))<0){
        printf("El archivo %s no existe.\n",originFilename);
        return 1;
    }
    if((destination=creat(dstFilename,0666))<0){
        printf("Error creando el archivo %s.\n",dstFilename);
        return 2;
    }

    while ((readline=read(origin,buf,sizeof(buf)))!=0) {
        if(readline<0){
            printf("Error leyendo el archivo %s.\n",originFilename);
            return 3;
        }
        writeline=0;
        do{
            if((line=write(destination,&buf[writeline],readline-writeline))<0){
                printf("Error escribiendo al archivo %s.\n",dstFilename);
                return 4;
            }
            writeline+=line;
        }while(writeline<readline);
    }
    close(origin);
    close(destination);
}