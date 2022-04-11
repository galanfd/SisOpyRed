#include "process.h"
#include <stdlib.h> // malloc, calloc, free, etc

// Asistido por Copilot
Process* createProcess(int pid, int arrivalTime, int burstTime, char name[],
                       int priority, char state_i, int waitingTime, int timeTilUpgrade) {
    enum State {READY, RUNNING, WAITING, FINISHED};
    enum State state = state_i;
    Process* process = (Process*) malloc(sizeof(Process));
    process->pid = pid;
    process->name = name;
    process->priority = priority;
    process->state = state; // estado
    process->arrivalTime = arrivalTime;
    process->burstTime = burstTime;  // tiempo total de ejecución
    process->remainingTime = burstTime; // tiempo restante
    process->startTime = -1;
    process->endTime = -1;
    process->waitingTime = waitingTime;  // waiting_delay
    process->turnaroundTime = -1;
    process->timeTilUpgrade = waitingTime; // tiempor para subir de prioridad
    return process;
}

void updateState(Process* process, char state_i) {
    enum State {READY, RUNNING, WAITING, FINISHED};
    enum State state = state_i;
    process->state = state;
}
void updateBurstTime(Process* process, int time_used) {
    process->remainingTime = process->remainingTime - time_used;  // actualizamos el tiempo restante del proceso
}

void freeProcess(Process* process) {
    free(process);
}

