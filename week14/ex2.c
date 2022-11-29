#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

int main(){
    int input = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    while(true) {
        struct input_event input_event;
        if (read(input, (void*) &input_event, sizeof(struct input_event)) < 
            sizeof(struct input_event)) continue;
        if (input_event.type == 1) printf("PRESSED %x (%d)\n", input_event.code,
             input_event.code);
        else if (input_event.type == 0) printf("RELEASED %x (%d)\n",
             input_event.code, input_event.code);
    }
    return 0;
}