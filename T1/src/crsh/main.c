#include <stdio.h>
#include <string.h> // strtok, strcpy, etc.
#include <stdlib.h>
#include "../input_manager/manager.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h> 
#include "data.h"
#include <time.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
  List *lp;
	lp = (List *) malloc(sizeof(List));
	initList(lp);
  printf("> ");
  char **input = read_user_input();
  while (strcmp(input[0], "crexit") != 0)
  {
    if (strcmp(input[0], "hello") == 0)
    {
      time_t time_1;
      pid_t pid = fork();
      addAtTail(lp, pid, "hello", time(&time_1));
      if (pid == -1)
      {
        printf("There's an error while calling");
        exit(EXIT_FAILURE);
      }
      if (pid == 0)
      {
        sleep(5);
        printf("Hello World!\n");
        printf("> ");
        exit(EXIT_SUCCESS);
      }
      
    }
    if (strcmp(input[0], "sum") == 0)
    {
      if (input[1] != NULL && input[2] != NULL )
      {
        time_t time_1;
        pid_t pid = fork();
        addAtTail(lp, pid, "sum", time(&time_1));
        if (pid == -1)
        {
          printf("There's an error while calling");
          exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
          int NUMBER_1 = atoi(input[1]);  // Ref: https://www.educative.io/edpresso/how-to-convert-a-string-to-an-integer-in-c
          int NUMBER_2 = atoi(input[2]);
          sleep(5);
          int result = NUMBER_1 + NUMBER_2;
          printf("LA SUMA ES: %i\n", result);
          printf("> ");
          exit(EXIT_SUCCESS);
        }
        else
        {
          printList(lp);
        }
      }
    }
    if (strcmp(input[0], "is_prime") == 0)
    {
      if (input[1] != NULL)
      {
        time_t time_1;
        pid_t pid = fork();
        addAtTail(lp, pid, "is_prime", time(&time_1));
        if (pid == -1)
        {
          printf("There's an error while calling");
          exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
          sleep(5);
          int n = atoi(input[1]);
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
          printList(lp);
        }
      }
    }
    if (strcmp(input[0], "crlist") == 0)
    {
      time_t time_1; // QUIZAS ELIMINAR TODO ESTO Y DEJAR SOLO EL PRINTLIST
      pid_t pid = fork();
      addAtTail(lp, pid, "crlist", time(&time_1));
      if (pid == -1)
      {
        printf("There's an error while calling");
        exit(EXIT_FAILURE);
      }
      if (pid == 0)
      {
        printList(lp);
        sleep(5);
        printf("> ");
        exit(EXIT_SUCCESS);
      }
      else
      {
        printList(lp);
        printf("Main process id: %i\n", getpid());
        printf("Back in the main process\n");
      }
      // execvp(exe)  1)revisar si el archivo existe (access(nombre_archivo)) 2)despues poner execvp()
    }
    if (strcmp(input[0], "crexec") == 0) // ref: https://pubs.opengroup.org/onlinepubs/009695299/functions/access.html
    {
      if (input[1] != NULL)
      {
        char path[256] = "./";
        char aux[256];
        strcpy(aux, input[1]);
        strcat(path, aux);
        int result = access(input[1],  F_OK);
        if (result == 0)  // ref: https://pubs.opengroup.org/onlinepubs/009695299/functions/access.html
        {
          time_t time_1;
          pid_t pid = fork();
          addAtTail(lp, pid, input[1], time(&time_1));
          if (pid == -1)
          {
            printf("There's an error while calling");
            exit(EXIT_FAILURE);
          }
          if (pid == 0)
          {
            sleep(5);
            execvp(path, NULL);  // CAMBIAR
            printf("> ");
            exit(EXIT_SUCCESS);
          }
          else
          {
            printList(lp);
            printf("Main process id: %i\n", getpid());
            printf("Back in the main process\n");
          }
        }
      }
      else{
        printf("EL EJECUTABLE NO EXISTE\n");
      }
    }
    printf("> ");
    input = read_user_input();
  }
  // AGREGAR CIERRE DE PROCESOS (SIGINT) (WAIT(15)) O ELIMINACIÓN DE ELLOS (SIGKILL)
  //CTRL+C: function handler (le cambia valor a una variable--> que hace continuar (detener) el while)
  // kill despues de un time de 15s
  freeList(lp);
  free(lp);  // agregar función que libere nodos
  free_user_input(input);
}
