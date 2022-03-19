#include <stdio.h>
#include <string.h> // strtok, strcpy, etc.
#include "../input_manager/manager.h"

int main(int argc, char const *argv[])
{
  printf("> ");
  char **input = read_user_input();
  printf("> The first argument you wrote was: %s\n", input[0]);
  //printf("string: %s\n", input[0]);
  //printf("es 0? : %i\n", strcmp(input[0], "hello"));
  if (strcmp(input[0], "hello") == 0)
  {
    printf("Hello World!\n");
  }
  printf("> ");
  input = read_user_input();
  printf("string: %s\n", input[0]);
  free_user_input(input);
}
