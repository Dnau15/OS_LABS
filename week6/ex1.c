#include<stdio.h>
#include<stdlib.h>

void swap(double *arrival_time1, double *arrival_time2,
double *burst_time1, double *burst_time2);

void bubble_sort(double arrival_time[], double burst_time[], int ar_size);

void print_ar(double ar[], int n);

int main(){
    int n;
    scanf("%d", &n);
    double arrival_time[n];
    double burst_time[n];
    printf("Enter the arrival time of each process");
    for (int i = 0;i < n;i++){
        scanf("%lf", &arrival_time[i]);
    }
    printf("Enter the burst time of each process");
    for (int i = 0;i < n;i++){
        scanf("%lf", &burst_time[i]);
    }
    

    double exit_time[n];
    double responce_time[n];
    double waiting_time[n];
    double turnaround_time[n];
    //fcfs
    bubble_sort(arrival_time, burst_time, n);
    double delay = 0;
    
    exit_time[0] = burst_time[0] + arrival_time[0];
    for (int i = 1;i < n;i++){
        if (exit_time[i-1] > arrival_time[i]){
            exit_time[i] = exit_time[i-1] + burst_time[i];
        }
        else
        exit_time[i] = arrival_time[i] + burst_time[i];
    }

    for (int i = 0;i < n;i++){
        turnaround_time[i] = exit_time[i] - arrival_time[i];
    }

    for (int i = 0;i < n;i++){
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }

    double average_turnaround = 0;

    double sum = 0;
    for (int i = 0;i < n;i++){
        sum += turnaround_time[i];
    }
    average_turnaround = sum / n;

    sum = 0;

    double average_waiting = 0;
    for (int i = 0;i < n;i++){
        sum += waiting_time[i];
    }
    average_waiting = sum / n;

    printf("Completion time: ");
    print_ar(exit_time, n);
    printf("Turn around time: ");
    print_ar(turnaround_time, n);
    printf("Waiting time: ");
    print_ar(waiting_time, n);
    printf("Average Turnaround time: %f\n", average_turnaround);
    printf("Average waiting time: %f\n", average_waiting);
}

void swap(double *arrival_time1, double *arrival_time2,
double *burst_time1, double *burst_time2){
    double arrival_temp = *arrival_time1;
    *arrival_time1 = *arrival_time2;
    *arrival_time2 = arrival_temp;
    
    double burst_temp = *burst_time1;
    *burst_time1 = *burst_time2;
    *burst_time2 = burst_temp; 
}

void bubble_sort(double ar1[], double ar2[], int ar_size){
    for (int i = 0;i < ar_size - 1; i++){
        for (int j = 0;j < ar_size - i - 1;j++){
            if (ar1[j] > ar1[j+1]){
                swap(&ar1[j], &ar1[j+1], &ar2[j], &ar2[j+1]);
            }
        }
    }
}

void print_ar(double ar[], int n){
    for (int i = 0;i < n;i++){
        printf("%f ", ar[i]);
    }
    printf("\n");
}