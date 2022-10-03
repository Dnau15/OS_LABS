#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc <= 1){
        printf("Enter number of subscribers\n");
        exit(0);
    }

    int sub_count = atoi(argv[1]);

    if (sub_count > 3){
        printf("Max number of subscribers equals to 3\n");
        exit(0);
    }
    if (sub_count < 1){
        printf("Min number of subscribers equals to 1\n");
        exit(0);
    }

    char pub_cmd[256];
    char sub_cmd[256];
    mkfifo("/tmp/ex1", 0666);

    char *tab_cmd = "gnome-terminal --tab -e ";

    sprintf(pub_cmd, "%s \"./p.out %s\"", tab_cmd, argv[1]);
    sprintf(sub_cmd, "%s \"./s.out %s\"", tab_cmd, argv[1]);

    for (int i = 0;i < sub_count;i++){
        system(sub_cmd);
    }
    system(pub_cmd);
}