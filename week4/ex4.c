#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char* argv[]){
    char command[100];
    printf("Enter command\n");
    fgets(command, sizeof command, stdin);
    pid_t id = fork();
    if (id == 0){
        system(command);
        exit(0);
    }
    
   
}