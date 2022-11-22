#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
	DIR *directory = opendir("/");
	struct dirent *_dirent;

	while ((_dirent = readdir(directory)) != NULL) {
		printf("%s\n", _dirent->d_name);
	}
    
	return 0;
}
