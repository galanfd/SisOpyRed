#include "process.h"
#include <stdlib.h> // malloc, calloc, free, etc

Process* createProcess(int pid, int arrivalTime, int burstTime, char name, int priority, char state_i) {
    enum State {READY, RUNNING, WAITING, FINISHED};
    enum State state = state_i;
    Process* process = (Process*) malloc(sizeof(Process));
    process->pid = pid;
    process->name = &name;
    process->priority = priority;
    process->state = state;
    process->arrivalTime = arrivalTime;
    process->burstTime = burstTime;
    process->remainingTime = burstTime;
    process->startTime = -1;
    process->endTime = -1;
    process->waitingTime = -1;
    process->turnaroundTime = -1;
    return process;
}

void updateState(Process* process, char state_i) {
    enum State {READY, RUNNING, WAITING, FINISHED};
    enum State state = state_i;
    process->state = state;
}
void updateBurstTime(Process* process) {

}

