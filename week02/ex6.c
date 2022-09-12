#include<stdio.h>
void fst_pattern(int len);
void snd_pattern(int len);
void thd_pattern(int len);
void mult_print(int len);
int main(){
	int n;
	int len;
	printf("Choose pattern 1-3");
	scanf("%d", &n);
	printf("Choose length");
	scanf("%d", &len);
	if (n == 1) fst_pattern(len);
	else 
	if (n == 2) snd_pattern(len);
	else
	if (n == 3) thd_pattern(len);  
}

void fst_pattern(int len){
	for (int i = 1;i <= len;i++){
		mult_print(i);
	}
}
void snd_pattern(int len){
	if (len % 2 != 0) {
		for (int i = 1;i <= len/2;i++){
			mult_print(i);
		}	
		for (int i = len/2 + 1;i >= 1;i--){
			mult_print(i);
		}	
	}
	else {
		for (int i = 1;i <= len/2;i++){
			mult_print(i);
		}	
		for (int i = len/2;i >= 1;i--){
			mult_print(i);
		}	
	}
}
void thd_pattern(int len){
	for (int i = 1;i <= len;i++){
		mult_print(len);
	}
}
void mult_print(int len){
	for (int i = 0;i < len;i++){
		printf("*");
	}
	printf("\n");
}
