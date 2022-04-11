#include <stdio.h>	// FILE, fopen, fclose, etc.
#include <stdlib.h> // malloc, calloc, free, etc
#include "../process/process.h"
#include "../queue/queue.h"
#include "../file_manager/manager.h"

// RUN ./mlfq "procesos.txt"

int main(int argc, char const *argv[])
{
	/*Lectura del input*/
	char *file_name = (char *)argv[1];
	InputFile *input_file = read_file(file_name);

	/*Mostramos el archivo de input en consola*/
	printf("Nombre archivo: %s\n", file_name);
	printf("Cantidad de procesos: %d\n", input_file->len);
	printf("Procesos:\n");
	for (int i = 0; i < input_file->len; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			printf("%s ", input_file->lines[i][j]); // 0 = name, 1 = pid, 2 = arrival_time, 3 = burst_time, 4 = wait, 5 = waitingtime, 6 = timeTilUpgrade
		}
		//Process* process = createProcess(atoi(input_file->lines[i][1]), atoi(input_file->lines[i][2]), atoi(input_file->lines[i][3]), &input_file->lines[i][0],
		//			  0, "READY", atoi(input_file->lines[i][5]), atoi(input_file->lines[i][6]));
		printf("\n");
	}

	input_file_destroy(input_file);
}