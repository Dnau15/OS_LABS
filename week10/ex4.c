#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

const int n = 10000000;

int main(){
    struct rusage usage;
    int ar_size = (int) n / 4;
    int *ar;
    for (int i = 0;i < 10;i++){
        ar = calloc(ar_size, sizeof(int));
        memset(ar, 0, n);
        sleep(1);
        getrusage(RUSAGE_SELF, &usage);
        printf("ru_maxrss %ld\n", usage.ru_maxrss);
    }
    
    /**
     * 
    */
    free(ar);
}