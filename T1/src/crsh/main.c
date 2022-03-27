#include <stdio.h>
#include <string.h> // strtok, strcpy, etc.
#include <stdlib.h>
#include "../input_manager/manager.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h> 
#include "data.h"
#include <time.h>

int main(int argc, char const *argv[])
{
  List *lp;
	lp = (List *) malloc(sizeof(List));
	initList(lp);
  printf("> ");
  char **input = read_user_input();
  printf("> The first argument you wrote was: %s\n", input[0]);
  while (strcmp(input[0], "crexit") != 0)
  {
    if (strcmp(input[0], "hello") == 0)  // AGREGAR QUE NO VENGAN MÁS ARGUMENTOS
    {
      time_t time_1, time_2;
      //int diff_t;
      time(&time_1);
      //sleep(5);
      //time(&time_2);
      //printf("segundos: %.2f\n", difftime(time_2, time_1));
      clock_t start = clock();  // cambiar a segundos
      pid_t pid = fork();
      addAtTail(lp, pid, "hello", time_1);
      if (pid == -1)
      {
        printf("There's an error while calling");
        exit(EXIT_FAILURE);
      }
      if (pid == 0)
      {
        //clock_t t = clock();  PREGUNTAR
        sleep(10);
        printf("Hello World!\n");
        printf("child id: %i\n", getpid());
        //double tf = ((double)(clock() - t) / CLOCKS_PER_SEC);
        //printf("??? %f", tf);
        printf("> ");
        exit(EXIT_SUCCESS);
        //kill(pid, SIGKILL);
      }
      else
      {
        //double time_child_process = ((double)(clock() - start) / CLOCKS_PER_SEC);
        //fixtime(lp, pid);
        printf("Last process id: %i\n", pid);
        //printf("Time of last process: %f", time_child_process);
        //addAtTail(lp, pid, "hello", time_child_process);
        printList(lp);
        printf("Main process id: %i\n", getpid());
        printf("Back in the main process\n");
      }
    }
    if (strcmp(input[0], "sum") == 0)  // if str(atoi) == input, continue
    {
      clock_t start = clock();
      pid_t pid = fork();
      addAtTail(lp, pid, "sum", start);
      if (pid == -1)
      {
        printf("There's an error while calling");
        exit(EXIT_FAILURE);
      }
      if (pid == 0)
      {
        int NUMBER_1 = atoi(input[1]);  // Ref: https://www.educative.io/edpresso/how-to-convert-a-string-to-an-integer-in-c
        int NUMBER_2 = atoi(input[2]);
        int result = NUMBER_1 + NUMBER_2;
        printf("LA SUMA ES: %i\n", result);
        printf("> ");
        //kill(pid, SIGKILL); dsdsa
        exit(EXIT_SUCCESS);
      }
      else
      {
        //double time_child_process = ((double)(clock() - start) / CLOCKS_PER_SEC);
        printf("Last process id: %i\n", pid);
        //printf("Time of last process: %f", time_child_process);
        printList(lp);
        printf("Main process id: %i\n", getpid());
        printf("Back in the main process\n");
      }
    }
    if (strcmp(input[0], "is_prime") == 0)
    {
      clock_t start = clock();
      pid_t pid = fork();
      addAtTail(lp, pid, "is_prime", start);
      if (pid == -1)
      {
        printf("There's an error while calling");
        exit(EXIT_FAILURE);
      }
      if (pid == 0)
      {
        int n = atoi(input[1]);
        printf("soy el numero %i\n", n);
        int i, flag = 0;  // Ref: https://www.programiz.com/c-programming/examples/prime-number
        if (n == 0 || n == 1){
          flag = 1;
        }
        for (i = 2; i <= n / 2; ++i) {
          if (n % i == 0) {
            flag = 1;
            break;
          }
        }
        if (flag == 0){
          printf("%d es un número primo.\n", n);
        }
        else{
          printf("%d NO es un número primo.\n", n);
        }
        printf("> ");
        exit(EXIT_SUCCESS);
      }
      else
      {
        //double time_child_process = ((double)(clock() - start) / CLOCKS_PER_SEC);
        printf("Last process id: %i\n", pid);
        //printf("Time of last process: %f", time_child_process);
        printList(lp);
        printf("Main process id: %i\n", getpid());
        printf("Back in the main process\n");
      }
    }
    if (strcmp(input[0], "crlist") == 0)  // AGREGAR QUE NO VENGAN MÁS ARGUMENTOS(?)
    {
      clock_t start = clock();
      pid_t pid = fork();
      addAtTail(lp, pid, "crlist", start);
      printf("this pid %i\n", pid);  // QUIZÁS AGREGAR A LP ANTES Y LUEGO INVOCAR FUNCIÓN QUE ARREGLE EL TIEMPO 
      if (pid == -1)
      {
        printf("There's an error while calling");
        exit(EXIT_FAILURE);
      }
      if (pid == 0)
      {
        //clock_t t = clock();  PREGUNTAR
        printList(lp);
        printf("child id: %i\n", getpid());
        //double tf = ((double)(clock() - t) / CLOCKS_PER_SEC);
        //printf("??? %f", tf);
        printf("> ");
        exit(EXIT_SUCCESS);
        //kill(pid, SIGKILL);
      }
      else
      {
        //double time_child_process = ((double)(clock() - start) / CLOCKS_PER_SEC);
        printf("Last process id: %i\n", pid);
        //printf("Time of last process: %f", time_child_process);
        //printList(lp);
        printf("Main process id: %i\n", getpid());
        printf("Back in the main process\n");
      }
      // execvp(exe)  1)revisar si el archivo existe (access(nombre_archivo)) 2)despues poner execvp()
    }
    printf("> ");
    input = read_user_input();
  }
  // AGREGAR CIERRE DE PROCESOS (SIGINT) (WAIT(15)) O ELIMINACIÓN DE ELLOS (SIGKILL)
  //CTRL+C: function handler (le cambia valor a una variable--> que hace continuar (detener) el while)
  // kill despues de un time de 15s
  free(lp);  // agregar función que libere nodos
  free_user_input(input);
}
