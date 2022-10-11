#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Process {
    double arrival_time;
    double burst_time;
    int id;
} Process;


int comparator(const void *process_1, const void *process_2) {
    Process * processes = (Process *)process_1;
    Process * b = (Process *)process_2;

    return (processes->arrival_time - b->arrival_time);
}


typedef struct Quesort {
    Process processes[1028];
    int len;

} Quesort;

void swap(Process *process1, Process *process2){
    Process temp_proc = *process1;
    *process1 = *process2;
    *process2 = temp_proc;
}

void add(Quesort * processes, Process b){
    processes->processes[processes->len] = b;
    processes->len++;
}

Process get_min(Quesort *processes){
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
    double quantum;
    printf("Enter quantum\n");
    scanf("%lf", &quantum);
    Process processes[n];
    for(int i = 0; i < n; i++){
        scanf("%lf%lf", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].id = i;
    }

    qsort(processes, n, sizeof(Process), comparator);
    double st = processes[0].arrival_time;
    Quesort queue = {.len = 0};
    int i = 0;

    double waiting_time[n];
    double turnaround_time[n];
    double finish_time[n];

    while(i < n || queue.len != 0){
        if(i < n && queue.len == 0){
            if (st < processes[i].arrival_time) st = processes[i].arrival_time;
            add(&queue, processes[i]);
            i++;
        }
        Process val = get_min(&queue);
        if (val.burst_time > quantum) st += quantum;
        else
        st += val.burst_time;
        val.burst_time -= quantum;
        while(i < n && processes[i].arrival_time <= st){
            add(&queue, processes[i]);
            i++;
        }
        if(val.burst_time > 0){
            add(&queue, val);
        }else{
            finish_time[val.id] = st;
            turnaround_time[val.id] = st - val.arrival_time;
            waiting_time[val.id] = st - val.arrival_time - processes[val.id].burst_time;
        }
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
        printf("Arrival Time: %lf Burst Time: %lf: ", processes[i].arrival_time, processes[i].burst_time);
        printf("Finish Time: %lf, Turnaround Time: %lf, Waiting Time: %lf\n",
         finish_time[i], turnaround_time[i], waiting_time[i]);
    }
    printf("\nAverage Turnaround time %lf\n", turnaround_average);
    printf("Average waiting time %lf\n", waiting_average);

    return 0;
}