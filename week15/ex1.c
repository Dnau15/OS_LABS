#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
	char *input_file_name = "input_dl.txt";
	char *output_file_name = "output.txt";


	FILE *input_file = fopen(input_file_name, "r");
	char buffer[256];

	int Process[500];
    int e_matrix[500];
    int a_matrix[500];
	int c_matrix[500][500];
    int r_matrix[500][500];

	fgets(buffer, 256, input_file);
	char *p = buffer;
	int e_count = 0;

	while(*p != '\n')
	{
		int temp = strtol(p, &p, 10);
		e_matrix[e_count++] = temp;
	}
	
    fgets(buffer, 256, input_file);
	fgets(buffer, 256, input_file);
    printf("DATA %s", buffer);
	p = buffer;

	int a_count = 0;

    int temp = 0;

	while(*p != '\n')
	{
		temp = strtol(p, &p, 10);
		a_matrix[a_count++] = temp;
	}
	
	

	int c_count = 0;
    fgets(buffer, 256, input_file);

	while(strcmp(fgets(buffer, 256, input_file), "\n") != 0)
	{
		p = buffer;
		for(int i=0; i < e_count; i++)
		{
			temp = strtol(p, &p, 10);
			c_matrix[c_count][i] = temp;
		}
		c_count++;
	}

	for(int i=0; i<c_count; i++)
	{
		fgets(buffer, 256, input_file);
		p=buffer;
		for(int j=0; j<e_count; j++)
		{
			temp = strtol(p, &p, 10);
			r_matrix[i][j] = temp;
		}
	}

	int checking_array[500];
	for (int i = 0;i < e_count;i++){
		checking_array[i] = 0;
	}

	for (int i = 0;i < c_count;i++){
		for (int j = 0;j < e_count;j++){
			checking_array[j] += c_matrix[i][j];
		}
	}

	bool invalid_input = false;
	for (int i = 0;i < e_count;i++){
		if (e_matrix[i] < a_matrix[i] + checking_array[i]){
			invalid_input = true;
		}
	}

	bool no_dedlock = true;
	int count = 0;

	bool deadlocked_processes[500];
	for (int i = 0;i < 500;i++){
		deadlocked_processes[i] = false;
	}

	bool checking;

	while (true){
		no_dedlock = true;
		
		for (int i = 0;i < c_count;i++){
			checking = true;
			if (r_matrix[i][0] !=-1 ){
				for (int j = 0;j < e_count;j++){
				if (r_matrix[i][j] > a_matrix[j]){
					checking = false;
					no_dedlock = false;
				}
			}
			if (checking){
				for (int j = 0;j < e_count;j++){
					a_matrix[j] += c_matrix[i][j];
					r_matrix[i][0] = -1;
				}
			}
			else {
				no_dedlock = false;
			}
			}
			
		}
		for (int i = 0;i < c_count;i++){
			if (r_matrix[i][0] != -1) no_dedlock = false;
		}
		if (no_dedlock) break;
		count++;
		if (count >= 100000) {
			for (int k = 0;k < c_count;k++){
				if (r_matrix[k][0] != -1) deadlocked_processes[k] = true; 
			}
			printf("e2dadwa");
			break;
		}
	}
	
	FILE *output = fopen(output_file_name, "w");

	if (invalid_input){
		fprintf(output, "%s", "invalid input");
	}
	if (no_dedlock){
		fprintf(output, "%s", "no deadlock is detected");
	}
	else {
		for (int i = 0;i < c_count;i++){
			if (deadlocked_processes[i]) fprintf(output, "deadlock process %d\n", i);
		}

	}

	

	

	// for (int i = 0;i < 10;i++){
	// 	for (int j = 0;j < 10;j++){
	// 		printf("%d ", r_matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }


	return 0;
} 
	
	