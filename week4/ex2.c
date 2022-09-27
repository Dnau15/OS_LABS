#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
#include <sys/wait.h>

int main(){
    int u[120];
    int v[120];
    int dot_product = 0;

    for (int i = 0;i < 120; i++){
        u[i] = random() % 100;
        //u[i] = 3;
    }

    for (int i = 0;i < 120;i++){
        v[i] = random() % 100;
        //v[i] = 3;
    }

    FILE *temp_file;
    temp_file = fopen("temp.txt", "wr+");

    int n;
    printf("Enter number of processes\n");
    scanf("%d", &n);
    
    for (int i = 0;i < n;i++){
        pid_t current_id = fork();
        if (current_id == 0){
            int current_index = ceil(120/n);
            int sum = 0;
            for (int j = i * current_index;j < current_index * (i+1);j++){
                sum += v[j]*u[j];
            }
            fprintf(temp_file, "%d ", sum);
            exit(0);
        }
    }
    
    while(wait(NULL) > 0);

    rewind(temp_file);
    
    for (int i = 0;i < n;i++){
        int input;
        fscanf(temp_file, "%d", &input);
        dot_product += input;
    }
    fclose(temp_file);
    
    printf("dot product = %d", dot_product);
}