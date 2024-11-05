#include <iostream>
#include <stdio.h>
#define ARRAY_SIZE 5
/**
 * Write a program (c++ or java) that computes turnaround time and average wait time 
 * for the processes listed in Q2 for FCFS and SJF scheduling.
 */
//define struct 
typedef struct  {
    int processId;
    int bTime;
    int wTime;
    int turnaroundTime;
} Process;

/**
 * This function calculates waiting and turnaround times for FCFS
 */
void getFCFS(Process p[]) {
    p[0].wTime = 0;
    p[0].turnaroundTime = p[0].bTime;

    for (int i = 1; i < ARRAY_SIZE; ++i) {
        p[i].wTime = p[i - 1].wTime + p[i - 1].bTime;
        p[i].turnaroundTime = p[i].wTime + p[i].bTime;
    }
}

/**
 * This Function calculates waiting and turnaround times for SJF
 */
void getSJF(Process p[]) {

    for (int i = 0; i < ARRAY_SIZE-1; ++i)
    {
        for (int j = i+1; j < ARRAY_SIZE; ++j)
        {
            if (p[i].bTime > p[j].bTime)
            {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
            
        }
        
    }
    
    p[0].wTime = 0;
    p[0].turnaroundTime = p[0].bTime;
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        p[i].wTime = p[i - 1].wTime + p[i - 1].bTime;
        p[i].turnaroundTime = p[i].wTime + p[i].bTime;
    }
}

/**
 * display as the example output
 */
void display(Process p[],const char* processName) {
    std::cout << "----------------- " << processName << " -----------------\n";
    std::cout << "Process ID       |      Waiting Time      | Turnaround Time\n";

    int totalWaitingTime = 0;

    for (int i = 0 ;i<ARRAY_SIZE ;++i) {
        std::cout << "     " << p[i].processId << "           |      " << p[i].wTime 
                  << "                 |        " << p[i].turnaroundTime << "\n";
        totalWaitingTime += p[i].wTime;
    }

    std::cout << "Average Waiting Time: " << (float)(totalWaitingTime) / ARRAY_SIZE << "\n";
}

/**
 * main
 */
int main() {
    // Define processes
    Process p[] = {
        {1, 2, 0, 0}, {2, 1, 0, 0}, {3, 8, 0, 0}, {4, 4, 0, 0},{5,5,0,0}
    };

    // FCFS 
    Process fcfsProcesses[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        fcfsProcesses[i] =p[i];
    }
    
    getFCFS(fcfsProcesses);
    display(fcfsProcesses, "FCFS");

    // SJF
    Process sjfProcesses[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sjfProcesses[i] =p[i];
    }
    getSJF(sjfProcesses);
    display(sjfProcesses, "SJF");

    return 0;
}
