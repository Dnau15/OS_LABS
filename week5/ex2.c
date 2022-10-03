#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

struct Thread{
    pthread_t id;
    int i;
    char message[256];
};

void *say_hello(void * thread){
    struct Thread* thr = (struct Thread*)thread;
    sprintf(thr->message, "Hello from thread %d", thr->i);
    printf("%s\n",thr->message);
    printf("%ld\n",thr->id);
    return NULL;
}

int main(){
    int thread_count;
    printf("Enter threads count:\n");
    scanf("%d", &thread_count);

    struct Thread threads[thread_count];

    for (int i = 0; i < thread_count; i++){
        threads[i].i = i;
        pthread_create(&threads[i].id, NULL, say_hello, &threads[i]);
        printf("Thread %d is created\n", threads[i].i);
        pthread_join(threads[i].id, NULL);
    }
}