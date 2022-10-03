#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int buffer;
    char * buf_path = "/tmp/ex1";
    int subs_count = atoi(argv[1]);

    buffer = open(buf_path, O_RDWR | O_NONBLOCK);
    
    if (buffer < 0) {
        printf("Error publisher!\n");
        exit(0);
    }

    while (1) {
        char* message = (char*)calloc(1024, sizeof(char));
        printf("> ");
        fgets(message, 1024, stdin);
        
        for(int i = 0; i < subs_count; i++) {
            if (strlen(message) > 1024) {
                printf("Max message len %d", 1024);
                exit(0);
            }

            write(buffer, message, strlen(message));
            sleep(1);
        }

        if (strcmp("exit\n", message) == 0)
            break;

        free(message);
    }

    close(buffer);
}