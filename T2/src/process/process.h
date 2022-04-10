#pragma once

typedef struct process {
    int pid;
    char name[32];
    int priority;
    int state;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int startTime;
    int endTime;
    int waitingTime;
    int turnaroundTime;
}Process;



struct Process* createProcess(int pid, int arrivalTime, int burstTime, char name, int priority, char state_i);