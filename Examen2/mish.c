#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
 
#define MAX_LINE 80
#define MAX_NUM_ARGS 10
 
size_t string_parser(char *input, char *word_array[]) {
    size_t n = 0;
    while (*input) {
        while (isspace((unsigned char)*input))
        ++input;
        if (*input) {
            word_array[n++] = (char *)input;
            while (*input && !isspace((unsigned char)*input))
                ++input;
                *(input) = '\0';
                ++input;
        }
    }
    word_array[n] = NULL;
    return n;
}
 
int main(void) {
  char *args[MAX_NUM_ARGS + 1]; /* command line (of 80) has max of 5 arguments */
  char line[MAX_LINE + 1];
  int should_run = 1;
 
  int i;
 
  while (should_run) {
    printf("mish> ");
    fgets(line,MAX_LINE,stdin);
    line[strcspn(line, "\n")] = '\0';
    // Separamos la línea en palabras separadas por espacio
    // y las guardamos en args
    i = string_parser(line,args); // i contiene el número de argumentos
    printf("%d, %s %s\n", i, args[1],line); // Es solo para pruebas borrar cuando esté listo
    
    /**
    (1) Crear un proceso hijo
    (2) El hijo debe ejecutar execvp para ejecutar al comando tecleado
    (3) Si el programa no existe debe imprimir programa no encontrado
    (4) El proceso padre debe esperar a que el hijo termine, checar funcion wait
    (5) Debe ejecutar comandos como ls -l /etc o ps -fea
    (6) Cuando se teclee exit deberá terminar
    **/


    //Punto 6) Se manda la señal para que al teclear "exit" se termine
     if((strcmp(args[0], "exit"))==0){
        should_run=0;
        break;
    }
    //Punto 1) Crea al proceso hijo
    int pid=fork();
    if(pid==0){
        //Punto 2) Si es proceso hijo el pid=0. Entonces se ejecuta el comando tecleado
            execvp(args[0],args);
    }
    else if(pid<0){
        //Punto 3) Si el proceso no existe entonces se regresa un valor de -1, por lo que se avisa que el programa no existe. 
        printf("Programa no encontrado");
    }else{
        //Cuando entra el proceso padre se ejecuta el wait. Punto 4)
        wait(NULL);
    }

    //Se probaron los comandos ls -l /etc y ps -fea. Punto 5)
   
    
    fflush(stdout);
    fflush(stdin);
    line[0] = '\0';
  }
 
  return 0;
}