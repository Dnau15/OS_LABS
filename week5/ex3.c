#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<pthread.h>
#include<math.h>

void* primes_count(void *range){
    int from = ((int*)range)[0];
    int to = ((int*)range)[1];
    int *count = malloc(sizeof(int));
    for (int j = from;j < to;j++){
    	
        if (j <= 1) continue;
        if (j <= 3){
            *count += 1;
            continue;
        }

        int flag = 1;
        for (int i = 2;i * i <= j;i++){
           if (j % i == 0) {
            flag = 0;
            break;
           }
        }
        
        if (flag == 1) {
            *count += 1; 
        }
    }
    return (void*)count;
}


int main(int argc, char* argv[]){
    if (argc < 2){
        printf("Pass n and m\n");
        exit(0);
    }
    int n, m;
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    int count = 0;
    pthread_t thr_id[m];
    
    int part = ceil(n/m);
    for (int i = 0;i < m;i++){
        int from = i * part;
        int to = (part * (i+1)) % n;
        if (to == 0) to = n;

        int *interval = (int*)calloc(2, sizeof(int));
        interval[0] = from;
        interval[1] = to;
        pthread_create(&(thr_id[i]), NULL, primes_count, interval);

        // void * loc_amount = NULL;
        // pthread_join(thr_id[i], &loc_amount);
        // count += *(int*)loc_amount;
        
    }
    
    for (int i = 0;i < m;i++){
    	void * loc_amount = NULL;
        pthread_join(thr_id[i], &loc_amount);
        count += *(int*)loc_amount;
    }
    
    printf("%d\n", count);
}
