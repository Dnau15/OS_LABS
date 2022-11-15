#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

typedef struct Link {
    char * name;
    int inode;
} Link;

int main() {
    struct dirent *_dirent; 
    struct stat _stat;

    int count1 = 0;
    int count2 = 0;
    
    Link map[1000];
    Link newLinks[1000];

    DIR *directory = opendir("tmp");
    FILE *file = fopen("ex4.txt", "a");

    
    while ((_dirent = readdir(directory)) != NULL) {
        char * path = (char*)calloc(1000, sizeof(char));
        strcpy(path, "./tmp/");

        if (strcmp(_dirent->d_name, ".") != 0 && strcmp(_dirent->d_name, "..")) {
            strcat(path, _dirent->d_name);
            stat(path, &_stat);

            Link pair = {.inode=_stat.st_ino, .name=_dirent->d_name};
            map[count1++] = pair;

            if (_stat.st_nlink >= 2) {
                newLinks[count2++] = pair;
            }
        }
    }


    for(int i = count2 - 1; i >= 0; i--) {
        fprintf(file, "%s —– ", newLinks[i].name);
        
        for(int j = count1 - 1; j >=0; j--) {
            if (newLinks[i].inode == map[j].inode) {
                fprintf(file, "%s",map[j].name);
            }
            if (j > 1) fprintf(file, "%s", ", ");
        }
        fprintf(file, "%s", "\n");
    }

}