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

int shell = 1;

void handler(int sig)
{
  shell = 0;
}

void freeList(List* lp)
{
    Node * node;
	Node * tmp;
	if(lp->head == NULL)
	{
		return;
	}
	node = lp->head;
    while (node != NULL)
    {
       tmp = node;
       node = node->next;
       free(tmp);
    }

}

int main(int argc, char const *argv[])
{
  signal(SIGINT, handler);
  List *lp;
	lp = (List *) malloc(sizeof(List));
	initList(lp);
  char **input;
  while (shell)
  {
    printf("> ");
    input = read_user_input();
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
        //sleep(20);
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
          int len1;
          float ignore1;  // Ref: https://stackoverflow.com/questions/45554639/is-there-a-way-to-check-if-a-string-can-be-a-float-in-c
          int ret1 = sscanf(input[1], "%f %n", &ignore1, &len1);
          int check1 = ret1==1 && !input[1][len1];
          int len2;
          float ignore2;
          int ret2 = sscanf(input[2], "%f %n", &ignore2, &len2);
          int check2 = ret2==1 && !input[2][len2];
          float NUMBER_1 = atof(input[1]);
          float NUMBER_2 = atof(input[2]);
          //float n1 = atof(input[1]);
          //char str1[BUFFER_SIZE];
          //sprintf(str1, "%f", NUMBER_1);
          //float n2 = atof(input[2]);
          //char str2[BUFFER_SIZE];
          //sprintf(str2, "%f", n2);
          //sleep(5);
          if (check1 == 1 && check2 == 1)
          {
            float result = NUMBER_1 + NUMBER_2;
            printf("LA SUMA ES: %f\n", result);
            printf("> ");
            exit(EXIT_SUCCESS);
          }
          else{
            printf("INGRESAR UN INPUT VÁLIDO\n");
          }
        }
        //else
        //{
        //  printList(lp);
        //}
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
          //sleep(5);
          int n = atoi(input[1]);   // Ref: https://www.educative.io/edpresso/how-to-convert-a-string-to-an-integer-in-c
          char str[BUFFER_SIZE];
          sprintf(str, "%d", n);
          if (strcmp(input[1], str) == 0)
          {
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
          else{
            printf("INGRESAR UN INPUT VÁLIDO\n");
          }
        }
        //else
        //{
        //  printList(lp);
        //}
      }
    }
    if (strcmp(input[0], "crlist") == 0)
    {
      //time_t time_1; // QUIZAS ELIMINAR TODO ESTO Y DEJAR SOLO EL PRINTLIST
      //pid_t pid = fork();
      //addAtTail(lp, pid, "crlist", time(&time_1));
      //if (pid == -1)
      //{
      //  printf("There's an error while calling");
      //  exit(EXIT_FAILURE);
      //}
      //if (pid == 0)
      //{
      //  printList(lp);
      //  sleep(5);
      //  printf("> ");
      //  exit(EXIT_SUCCESS);
      //}
      //else
      //{
        printList(lp);
        //printf("Main process id: %i\n", getpid());
        //printf("Back in the main process\n");
      //}
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
          input[1] = path;
          if (pid == -1)
          {
            printf("There's an error while calling");
            exit(EXIT_FAILURE);
          }
          if (pid == 0)
          {
            //sleep(7);
            execvp(path, &input[1]);  // CAMBIAR
            printf("> ");
            exit(EXIT_SUCCESS);
          }
          //else
          //{
            //printList(lp);
            //printf("Main process id: %i\n", getpid());
            //printf("Back in the main process\n");
          //}
        }
        else{
          printf("EL EJECUTABLE NO EXISTE\n");
        }
      }
    }
    if (strcmp(input[0], "crexit") == 0) 
    {
      shell = 0;
      break;
    }
    if (!shell)
    {
      break;
    }
    //printf("> ");
    //input = read_user_input();
  }
  // AGREGAR CIERRE DE PROCESOS (SIGINT) (WAIT(15)) O ELIMINACIÓN DE ELLOS (SIGKILL)
  //CTRL+C: function handler (le cambia valor a una variable--> que hace continuar (detener) el while)
  // kill despues de un time de 15s

    Node * node;
    node = lp->head;
    while(node != NULL)
    {
        //float time;
        if (node->time_e == -1){
            int status;
            if (waitpid(node->PID, &status, WNOHANG) == 0)
            {
                time_t end_t;
                time(&end_t);
                kill(node->PID, SIGINT); 
            }
        }
        //else{
        //    time = ((double)(node->time_e - node->time_s) / CLOCKS_PER_SEC);  // TIEMPO TOTAL SI TERMINÓ
        //    printf("| %d | | %f | | %s |\n",node->PID, time, node->name);
        //}
        node = node->next;
    }

    //wait(15); 

    int i = 0;
    while (i < 15)
    {
      Node * node;
      node = lp->head;
      int checker = 1;
      while(node != NULL && checker)
      {
          //float time;
          if (node->time_e == -1){
              int status;
              if (waitpid(node->PID, &status, WNOHANG) == 0)
              {
                  checker = 0;
                  break;
              }
          }
          
          node = node->next;
      }
      if (checker)
      {
        break;
      }
      i++;
      sleep(1);
    }

    node = lp->head;
    while(node != NULL)
    {
        //float time;
        if (node->time_e == -1){
            int status;
            if (waitpid(node->PID, &status, WNOHANG) == 0)
            {
                time_t end_t;
                time(&end_t);
                kill(node->PID, SIGKILL); 

            }
        }
        //else{
        //    time = ((double)(node->time_e - node->time_s) / CLOCKS_PER_SEC);  // TIEMPO TOTAL SI TERMINÓ
        //    printf("| %d | | %f | | %s |\n",node->PID, time, node->name);
        //}
        node = node->next;
    }
  printf("Saliendo del programa\n");
  freeList(lp);
  free(lp);  // agregar función que libere nodos
  free_user_input(input);
}

