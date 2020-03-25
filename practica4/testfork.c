#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    printf("Cuantas veces\n");
    int pid=fork();
    if (pid==0) 
        printf("Soy el proceso hijo\n");
    
    else 
        printf("Soy el proceso padre\n");
    fork();
    fork();
    printf("cuantas veces se imprime otra vez\n");
}
