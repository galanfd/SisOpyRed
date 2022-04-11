#pragma once

typedef struct process {
    int pid;
    char* name;
    int priority;
    int state;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int startTime;
    int endTime;
    int waitingTime;
    int turnaroundTime;
    int timeTilUpgrade;
}Process;



Process* createProcess(int pid, int arrivalTime, int burstTime, char name[],
                       int priority, char state_i, int waitingTime, int timeTilUpgrade);

void updateBurstTime(Process* process, int time_used);

void freeProcess(Process* process);