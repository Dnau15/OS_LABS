#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d", &N);
    int *ar = calloc(sizeof(int), N);
    for (int i = 0;i < N;i++){
        ar[i] = i;
    }
    for (int i = 0;i < N;i++){
        printf("%d\n", ar[i]);
    }
    free(ar);
}