#include <stdio.h>
#include <string.h> // strtok, strcpy, etc.
#include <stdlib.h>
#include "../input_manager/manager.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h> 

int main(int argc, char const *argv[])
{
  printf("> ");
  char **input = read_user_input();
  printf("> The first argument you wrote was: %s\n", input[0]);
  while (strcmp(input[0], "crexit") != 0)
  {
    if (strcmp(input[0], "hello") == 0)  // AGREGAR QUE NO VENGAN MÁS ARGUMENTOS(?)
    {
      pid_t pid = fork();
      printf("Hello World!\n");
      kill(pid, SIGKILL);
    }
    if (strcmp(input[0], "sum") == 0)
    {
      pid_t pid = fork();
      int NUMBER_1 = atoi(input[1]);  // Ref: https://www.educative.io/edpresso/how-to-convert-a-string-to-an-integer-in-c
      int NUMBER_2 = atoi(input[2]);
      printf("LA SUMA ES: %i\n", NUMBER_1 + NUMBER_2);
      kill(pid, SIGKILL);
    }
    if (strcmp(input[0], "is_prime") == 0)
    {
      pid_t pid = fork();
      int n = atoi(input[1]);
      printf("soy el numero %i\n", n);  // REVISAR ERROR DE MEMORIA
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
      kill(pid, SIGKILL);
    }
    printf("> ");
    input = read_user_input();
  }
  // AGREGAR CIERRE DE PROCESOS (SIGINT) (WAIT(15)) O ELIMINACIÓN DE ELLOS (SIGKILL)
  free_user_input(input);
}
