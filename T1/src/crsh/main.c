#include <stdio.h>
#include <string.h> // strtok, strcpy, etc.
#include "../input_manager/manager.h"
#include <sys/types.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
  printf("> ");
  char **input = read_user_input();
  printf("> The first argument you wrote was: %s\n", input[0]);
  //printf("string: %s\n", input[0]);
  //printf("es 0? : %i\n", strcmp(input[0], "hello"));
  if (strcmp(input[0], "hello") == 0)  // AGREGAR QUE NO VENGAN MÁS ARGUMENTOS
  {
    pid_t pid = fork();
    printf("Hello World!\n");
    kill(pid, SIGKILL);
  }
  if (strcmp(input[0], "sum") == 0)
  {
    char c = '5';
    int x = c - '0';
    printf("numero %i\n", x);
    //int a = 0;
    //int a =  input[1] - '0';
    //int b = input[2] - "0";
    //printf("A: %i\n", a);
    //int result = (int)input[1] + (int)input[2];
    //printf("Resultado: %i\n", result);
  }
  printf("> ");
  //input = read_user_input();
  printf("string: %s\n", input[0]);
  free_user_input(input);
}
