#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int file_count = 0;
struct File{
	int id;
	double size;
	struct Directory *directory;
	char name[64];
	char data[1024];
};

struct Directory{
	struct File *files[256];
	int nf;
	int nd;
	char path[2048];
	struct Directory *directories[8];
};

//overwrites the file content with the new content
void add_to_file(struct File *file, const char * content);

//appends the new content to the end of the file
void append_to_file(struct File* file, const char *str); 

//prints to stdout the path of the file
void pwd_file(struct File* file);

void add_file(struct File* file, struct Directory* dir);

char * concat_paths(char *path1, char *path2);

struct Directory * dir_constructor(char * path);

struct File * file_constructor(char * path, char * data);

void add_file_to_dir(struct File *file, struct Directory *dir);

void add_dir_to_dir(struct Directory * subdir, struct Directory * dir); 

int main(){
	struct Directory * root = dir_constructor("/");
    struct Directory * bin = dir_constructor("bin/");
    struct Directory * home = dir_constructor("home/");
    struct File * bash = file_constructor("bash", NULL);
    struct File * ex3_1c = file_constructor("ex3_1.c", "int printf(const char * format, ...);");
    struct File * ex3_2c = file_constructor("ex3_2.c", "//This is a comment in C language");
    
    add_dir_to_dir(home, root);
    add_dir_to_dir(bin, root);

    add_file_to_dir(bash, bin);
    add_file_to_dir(ex3_1c, home);
    add_file_to_dir(ex3_2c, home);

    add_to_file(bash, "Bourne  Again  Shell!!");

    append_to_file(ex3_1c, "int  main(){printf(”Hello  World!”)}");

    pwd_file(bash);
    pwd_file(ex3_1c);
    pwd_file(ex3_2c);
}

struct Directory * dir_constructor(char * path) {
    struct Directory * dir = (struct Directory *) malloc(sizeof(struct Directory));
    //struct Directory * dir = (struct Directory *) malloc(sizeof(struct Directory));
    strcpy(dir->path, path);
    dir->nf = 0;
    dir->nd = 0;
    // for (int i = 0;i < 8;i++){
    //     dir->directories[i] = (struct Directory **) calloc(1, sizeof(struct Directory));
    // }
    return dir;
}

struct File * file_constructor(char *name, char *data){
    struct File * file = (struct File *) malloc(sizeof(struct File));
    strcpy(file->name, name);
    file->id = ++file_count;
    if (data != NULL){
        strcpy(file->data, data);
        file->size = strlen(data);
    }
    return file;
}


void add_to_file(struct File *file, const char * content){
    if (strlen(content) <= 1024){
        strcpy(file->data, content);
    }
    else {
        printf("Max size of the data is 1024\n");
    }
};

void append_to_file(struct File* file, const char *str){
    if (file->size + strlen(str) >1024){
        printf("Max size of the data is 1024\n");
    }
    strcat(file->data, str);
    file->size = strlen(file->data);
}

void pwd_file(struct File* file){
    char path[2048];
    strcat(path,file->directory->path);
    strcat(path, file->name);
    printf("%s\n", path);
    strcpy(path, "\0");
}

void add_file(struct File* file, struct Directory* dir){
    file_count++;
}

void add_dir_to_dir(struct Directory * subdir, struct Directory * dir){
    if (dir->nd >= 8){
        printf("Error, directory cannot have more than 8 subdirectories!\n");
        exit(0);
    }
    if (strlen(dir->path) + strlen(subdir->path) >= 2048){
        printf("Error, directory cannot have more than 2048 characters in its name!\n");
        exit(0);
    }
    strcpy(subdir->path, concat_paths(dir->path, subdir->path));
    dir->directories[dir->nd] = subdir;
    dir->nd++;
}

char * concat_paths(char *path1, char *path2){
    char *new_path = (char *)calloc(2048, sizeof(char)) ;
    strcat(new_path, path1);
    strcat(new_path, path2);
    return new_path;
}

void add_file_to_dir(struct File *file, struct Directory *dir){
    if (dir->nf >= 256){
        printf("Max number of files is 256\n");
    }
    dir->files[dir->nf] = file;
    dir->nf++;

    file->directory = dir;
}
