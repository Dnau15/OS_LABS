#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include <stdbool.h>

int main(){
    while (true){
        printf("> ");
        char command[256];
        fgets(command, sizeof command, stdin);
        if ((command[0]=='e') && (command[1]=='x') && (command[2]=='i') && (command[3]=='t')){
            return EXIT_SUCCESS;
        }
        pid_t id = fork();
        if (id == 0){
            system(command);
            exit(0);
        }
    }
}
