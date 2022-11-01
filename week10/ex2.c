#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

const int n = 10000000;

int main(){
    int ar_size = (int) n / 4;
    int *ar = calloc(ar_size, sizeof(int));
    memset(ar, 0, n);
    sleep(1);
    for (int i = 0;i < 9;i++){
        ar = calloc(ar_size, sizeof(int));
        memset(ar, 0, n);
        sleep(1);
    }
    /**
     * In my report si and so equals to 0 because my laptop has enough memory and should 
     * not swap memory. 
     * si: Amount of memory swapped in from disk (/s).
       so: Amount of memory swapped to disk (/s).
     * I noticed that my free memory had been decreased every second for 10 seconds. It shows 
     * that my program works correct.
     * 
     * When I ran my program I saw new PID, also CPU usage, shared memory, total virtual
     * memory, CPU time, RAM usage and memory usage were changed. 
    */
    free(ar);
}