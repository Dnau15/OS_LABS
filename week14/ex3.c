#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdbool.h>
#include <linux/input.h>
#include <unistd.h>

int main() {
    printf("Shortcuts:\nP+E--> I passed the Exam!\nC+A+P--> Get some cappuccino!\nA+B--> A grade\n");
    int numbers[1000];
    char *path = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int input_file = open(path, O_RDONLY);
    if (input_file < 0) {
        return 0;
    } else {
        while (true) {
            struct input_event input_event;
            read(input_file, &input_event, sizeof(input_event));
            if (input_event.type == EV_KEY) {
                numbers[input_event.code] = input_event.value;

                if ((numbers[25] == 2 && numbers[18] == 2) ||
                 (numbers[25] == 1 && numbers[18] == 1)) {
                    printf("I passed the Exam!\n");
                }
                if ((numbers[46] == 2 && numbers[30] == 2 && numbers[25] == 2) ||
                    (numbers[46] == 1 && numbers[30] == 1 && numbers[25] == 1)) {
                    printf("“Get some cappuccino!\n");
                }
            }
            if ((numbers[30] == 2 && numbers[48] == 2) || 
            (numbers[30] == 1 && numbers[48] == 1)) {
                printf("A grade\n");
            }
        }
    }
    return 0;
}