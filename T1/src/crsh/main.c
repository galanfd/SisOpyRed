#include <stdio.h>
#include <string.h> // strtok, strcpy, etc.
#include <stdlib.h>
#include "../input_manager/manager.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h> 
#include "data.h"
#include "funciones.h"

int main(int argc, char const *argv[])
{
  List *lp;  // #1  // SEGUIR MAÑANA
	lp = (List *) malloc(sizeof(List));  // #1

	initList(lp);  // #1

	addAtTail(lp, 10, "sum", 50);
  printList(lp);
	addAtTail(lp,20, "is_prime", 10);
  printList(lp);
	addAtTail(lp,30, "hello", 20);
  printList(lp);
	addAtTail(lp,40, "crexec", 30);		
	printList(lp);
  printf("> ");
  char **input = read_user_input();
  printf("> The first argument you wrote was: %s\n", input[0]);
  while (strcmp(input[0], "crexit") != 0)
  {
    if (strcmp(input[0], "hello") == 0)  // AGREGAR QUE NO VENGAN MÁS ARGUMENTOS(?)
    {
      pid_t pid = fork();
      helloworld();
      //printf("Hello World!\n");
      kill(pid, SIGKILL);
    }

    if (strcmp(input[0], "sum") == 0)
    {
      pid_t pid = fork();
      int NUMBER_1 = atoi(input[1]);  // Ref: https://www.educative.io/edpresso/how-to-convert-a-string-to-an-integer-in-c
      int NUMBER_2 = atoi(input[2]);
      suma(NUMBER_1, NUMBER_2);
      //printf("LA SUMA ES: %i\n", NUMBER_1 + NUMBER_2);
      kill(pid, SIGKILL);
    }

    if (strcmp(input[0], "is_prime") == 0)
    {
      pid_t pid = fork();
      int n = atoi(input[1]);
      primo(n);
      kill(pid, SIGKILL);
    }




    if (strcmp(input[0], "crexec") == 0)
    {
      if (strcmp(input[1], "hello") == 0)
      {
        pid_t pid = fork();
        helloworld();
        kill(pid, SIGKILL);
      }
      if (strcmp(input[1], "sum") == 0)
      {
        pid_t pid = fork();
        int NUMBER_1 = atoi(input[2]);  // Ref: https://www.educative.io/edpresso/how-to-convert-a-string-to-an-integer-in-c
        int NUMBER_2 = atoi(input[3]);
        suma(NUMBER_1, NUMBER_2);
        kill(pid, SIGKILL);
      }
      if (strcmp(input[1], "is_prime") == 0)
      {
        pid_t pid = fork();
        int n = atoi(input[2]);
        primo(n);
        kill(pid, SIGKILL);
      }
    }





    printf("> ");
    input = read_user_input();
  }
  // AGREGAR CIERRE DE PROCESOS (SIGINT) (WAIT(15)) O ELIMINACIÓN DE ELLOS (SIGKILL)
  free_user_input(input);
}
