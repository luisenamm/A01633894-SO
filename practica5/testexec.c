#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    
    int pid=fork();
    if (pid==0) 
        execlp("ls", "ls","-a","/", (char *)NULL);
    
    else 
        printf("Soy el proceso padre\n");
    printf("adiós\n") ;
    
}
