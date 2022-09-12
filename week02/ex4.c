#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
void count(char *str, char ch);

void countAll(char *str);

int main(){
	char input[256];
	fgets(input, 256, stdin);
	
	_Bool is_single_count = false;
	char str[256];
	char symbol = 'A';
	for (int i = 0;i < strlen(input)-1;i++){
		if (input[i] == ',') {
			is_single_count = true;
			symbol = input[i+2];
			break;
		}
		str[i] = input[i];
	}
	int str_len = strlen(str);
	if (is_single_count) {
		count(str, symbol);
	}
	else 
		countAll(str);
}
void count(char *str, char ch){
	int amount = 0;
	for (int i = 0;i < strlen(str);i++){
		if (tolower(str[i]) == tolower(ch)) amount++;
	}
	printf("%c:%d", tolower(ch), amount);
}

void countAll(char *str){
	int amount = 0;
	for (int i = 0;i < strlen(str);i++){
		count(str, str[i]);
		if (i < strlen(str)-1) printf(", ");
	}	
}
