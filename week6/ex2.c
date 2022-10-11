#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct process {
    double arrival_time;
    double burst_time;
} Process;

int cmp_by_at(const void *process_1, const void *process_2) {
    Process * processes = (Process *)process_1;
    Process * b = (Process *)process_2;

    return (processes->arrival_time - b->arrival_time);
}


typedef struct quesort {
    Process processes[500];
    int len;
} quesort;

void swap(Process *process1, Process *process2){
    Process temp_process = *process1;
    *process1 = *process2;
    *process2 = temp_process;
}

void add(quesort * processes, Process b){
    int len = processes->len;
    processes->processes[len] = b;
    processes->len++;
    len++;
    for(int it = 0; it < len; it++) {
        for (int i = 0; i + 1 < len; i++) {
            if(processes->processes[i].burst_time > processes->processes[i + 1].burst_time){
                swap(&processes->processes[i], &processes->processes[i + 1]);
            }
        }
    }
}

Process get_min(quesort *processes){
    int len = processes->len;
    Process res = processes->processes[0];
    for(int i = 1; i < len; i++){
        processes->processes[i - 1] = processes->processes[i];
    }
    processes->len--;
    return res;
}

int main() {
    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    Process processes[n];
    printf("Enter the arrival time and burst time of each process\n");
    for(int i = 0; i < n; i++){
        scanf("%lf%lf", &processes[i].arrival_time, &processes[i].burst_time);
    }
    qsort(processes, n, sizeof(Process), cmp_by_at);

    double st = 0;
    Process b[n];
    quesort q = {.len = 0};
    
    for(int i = 0, j = 0; i < n; i++){
        if (st < processes[i].arrival_time) st = processes[i].arrival_time;
        while(j < n && st >= processes[j].arrival_time){
            add(&q, processes[j]);
            j++;
        }
        Process val = get_min(&q);
        st += val.burst_time;
        processes[i] = val;
    }

    double waiting_time[n];
    double turnaround_time[n];
    double finish_time[n];

    double cur = 0;

    for(int i = 0; i < n; i++) {
        if (cur < processes[i].arrival_time) cur = processes[i].arrival_time;
        cur += processes[i].burst_time;
        finish_time[i] = cur;
        turnaround_time[i] = cur - processes[i].arrival_time;
        waiting_time[i] = cur - processes[i].arrival_time - processes[i].burst_time;
    }

    double turnaround_sum = 0;
    double waiting_sum = 0;
    double waiting_average = 0;
    double turnaround_average = 0; 
    
    for (int i = 0;i < n;i++){
        turnaround_sum += turnaround_time[i];
        waiting_sum += waiting_time[i];
    }

    waiting_average = waiting_sum / n;
    turnaround_average = turnaround_sum / n;

    for(int i = 0; i < n; i++){
        printf("Arrival Time: %lf Burst Time %lf: ", processes[i].arrival_time, processes[i].burst_time);
        printf("Finish Time %lf, Turnaround Time %lf, Waiting Time %lf\n",
         finish_time[i], turnaround_time[i], waiting_time[i]);
    }
    printf("\n");
    printf("Average Turnaround Time: %lf\n", turnaround_average);
    printf("Average Waiting Time: %lf\n", waiting_average);

    return 0;
}