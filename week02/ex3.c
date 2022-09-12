#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void convert(long long number, int source_system, int target_system);

int main(){
   long long number;
   char input[256];
   int source_system;
   int target_system;
   fgets(input, 256, stdin);
   sscanf(input, "%lld %d %d", &number, &source_system, &target_system);
   convert(number, source_system, target_system);
   
}

void convert(long long number, int source_system, int target_system){
	char str_num[256];
	snprintf(str_num, 256, "%lld", number);
	int str_len = strlen(str_num);
	long long dec_num = 0;
	int digit = 1;
	//checking correctness
	if ((source_system > 9) || (source_system < 2) || (target_system > 9) || (target_system < 2)){
		printf("cannot convert!");
		return;
	}	
	
	
	//convert to decimal
	for (int i = 0;i < str_len; i++){
		digit = (int) (str_num[i] - '0'); 
		dec_num += digit * pow(source_system, str_len - i - 1);
	}
	
	//convert to target system
	int tar_digit;
	int tar_pos = 0;
	long long res = 0;
	while (dec_num != 0){
		tar_digit = dec_num % target_system;
		dec_num = dec_num / target_system;
		res += tar_digit * pow(10, tar_pos);
		tar_pos++;
	}
	printf("%lld", res);
}
