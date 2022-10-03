#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char *buf_path = "/tmp/ex1";

    int buf;
    buf = open(buf_path, O_RDWR | O_NONBLOCK);
    
    int subs_count = atoi(argv[1]);

    

    if (buf<0){
        printf("Error subscriber!\n");
        exit(0);
    }

    while (1){
        char *message = (char*)calloc(1024, sizeof(char));
        read(buf, message, 1024);

        if (strlen(message)!=0) {
            printf("Message:%s\n", message);
            sleep(subs_count);
        }
        if (strcmp("exit\n", message) == 0)
            break;

        free(message);
    }
    close(buf);
}