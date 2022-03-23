#include <string.h> // strtok, strcpy, etc.
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h> 
#include "funciones.h"

void helloworld()
{
    printf("Hello World!\n");
}

void suma(int num1, int num2)
{
    printf("LA SUMA ES: %i\n", num1 + num2);
}

void primo(int n)
{
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
}