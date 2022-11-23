#include <dirent.h>
#include <stdio.h>

int main() {
	DIR *directory = opendir("/");

	struct dirent *dirent;

	while ((dirent = readdir(directory)) != NULL) 
	{
		printf("%s\n", dirent->d_name);
	}
	return 0;
}
