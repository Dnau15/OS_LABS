#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

//function that converts the given number x from numeral system s to another system t
void convert(long long number, int source_system, int target_system);

int main(){	
   long long number;
   char input[256];
   
   //given system
   int source_system;
   //target system
   int target_system;
   
   //reading
   fgets(input, 256, stdin);
   
   //converting string to int
   sscanf(input, "%lld %d %d", &number, &source_system, &target_system);
   
   //converting the number from numberal system s to another system t
   convert(number, source_system, target_system);
}

void convert(long long number, int source_system, int target_system){
	//source number converted to string
	char str_num[256];
	
	//converting int to string
	snprintf(str_num, 256, "%lld", number);
	
	//counting length of the string number
	int str_len = strlen(str_num);
	
	//number in decimal system
	long long dec_num = 0;
	
	//current digit. We will move through the digits of our number and convert them to decimal system
	int digit = 0;
	
	//checking correctness
	if ((source_system > 10) || (source_system < 2) || (target_system > 10) || (target_system < 2)){
		printf("cannot convert!");
		return;
	}	
	
	//convert source number to decimal system
	for (int i = 0;i < str_len; i++){
		//current digit
		digit = (int) (str_num[i] - '0'); 
		dec_num += digit * pow(source_system, str_len - i - 1);
	}
	
	//convert to target system
	
	//
	int tar_digit;
	int tar_pos = 0;
	long long res = 0;
	while (dec_num != 0){
		//we should find reminder 
		tar_digit = dec_num % target_system;
		//we should divide our number by base of the new system
		dec_num = dec_num / target_system;
		//we should multiply reminder by 10 in tar_pos-th power
		res += tar_digit * pow(10, tar_pos);
		tar_pos++;
	}
	printf("%lld", res);
}
