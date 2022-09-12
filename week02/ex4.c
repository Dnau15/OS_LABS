#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

//returns the number of occurrences of an input character in a string
void count(char *str, char ch);

//prints the number of occurrences of each character in the input string
void countAll(char *str);

int main(){
	
	//input string
	char input[256];
	fgets(input, 256, stdin);
	
	//we should understand which function should we use
	//we find ",". If we find "," then we will use count else we will use countAll
	_Bool is_single_count = false;
	
	char str[256];
	
	//symbol that we should find
	char symbol = 'A';
	
	for (int i = 0;i < strlen(input)-1;i++){
		//looking for ","
		if (input[i] == ',') {
			is_single_count = true;
			symbol = input[i+2];
			break;
		}
		str[i] = input[i];
	}
	//length of the string
	int str_len = strlen(str);
	
	//this part decides which function should we use
	if (is_single_count) {
		count(str, symbol);
	}
	else 
			countAll(str);
}
void count(char *str, char ch){
	//number of character occurrences
	int amount = 0;
	for (int i = 0;i < strlen(str);i++){
	//we should compare lowercase characters
		if (tolower(str[i]) == tolower(ch)) amount++;
	}
	printf("%c:%d", tolower(ch), amount);
}

void countAll(char *str){
	//number of character occurences
	int amount = 0;
	for (int i = 0;i < strlen(str);i++){
		count(str, str[i]);
		if (i < strlen(str)-1) printf(", ");
	}	
}
