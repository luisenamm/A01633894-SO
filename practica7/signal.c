#include <signal.h>
#include <stdio.h>
#include <unistd.h> 

void proccessSignal(int s){
    printf("Recibí señal %d\n",s);
}

void proccessSignal2(int s){
    printf("No me puedes matar\n");
}

int main(){
    signal(10,proccessSignal);
    signal(15,proccessSignal2);
    while(1){
        sleep(3);
        printf("Trabajando\n");
    }
    return 1;
}