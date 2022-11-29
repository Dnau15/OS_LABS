#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdbool.h>
#include <linux/input.h>
#include <unistd.h>

int main() {
    printf("Shortcuts:\nP+E--> I passed the Exam!\nC+A+P--> Get some cappuccino!\nA+B--> A grade\n");
    int array[1000];
    char *path = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int f = open(path, O_RDONLY);
    if (f < 0) {
        return 0;
    } else {
        while (1) {
            struct input_event inputEvent;
            read(f, &inputEvent, sizeof(inputEvent));
            if (inputEvent.type == EV_KEY) {
                array[inputEvent.code] = inputEvent.value;

                if (array[25] == 2 && array[18] == 2 || array[25] == 1 && array[18] == 1) {
                    printf("I passed the Exam!\n");
                }
                if (array[46] == 2 && array[30] == 2 && array[25] == 2 ||
                    array[46] == 1 && array[30] == 1 && array[25] == 1) {
                    printf("“Get some cappuccino!\n");
                }
            }
            if (array[30] == 2 && array[48] == 2 || array[30] == 1 && array[48] == 1) {
                printf("A grade\n");
            }
        }
    }
    return 0;
}