#include<stdio.h>
#include<unistd.h>
#include<time.h>

int main(){
    clock_t main_start = clock();
    clock_t process1_start;
    clock_t process2_start;

    clock_t process1_end;
    clock_t process2_end;

    pid_t main_id = getpid();
    pid_t main_parent_id = getppid();
    pid_t process1_id;
    pid_t process2_id;


    double exec_time, exec_time1, exec_time2;

    if (getpid() == main_id) {
        fork();
        process1_start = clock();
        process1_id = getpid();
    }

    if (getpid() == main_id) {
        fork();
        process2_start = clock();
        process2_id = getpid();
    }

    if (getpid() == process1_id) {
        process1_end = clock();
        exec_time = (double)(process1_end - process1_start) / CLOCKS_PER_SEC * 1000;
    }
    
    if (getpid() == process2_id) {
        process2_end = clock();
        exec_time = (double)(process2_end - process2_start)/ CLOCKS_PER_SEC * 1000;
    }
    
    if (getpid() == main_id) {
        clock_t main_end = clock();
        exec_time = (double)(main_end - main_start) / CLOCKS_PER_SEC * 1000; 
    }

    printf("ID of the process %d Parent ID %d Execution time in milliseconds of the process %f\n",
    getpid(), getppid(), exec_time);
}