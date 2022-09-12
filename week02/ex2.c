#include<stdio.h>
#include<string.h>
int main(){

   char str[256];
   
   //reverse string
   char rev_str[256];
   
   
   //reading input
   fgets(str, 256,stdin);
   int len = strlen(str);
   
   //index of the last character
   int last_char = 0;
   
   //looking for "." or "Enter key"
   for (int i = 0;i < len; i++){
   		if ((str[i] == '.') || (str[i] == '\n')) {
   		//we should know index of the last character before "." or enter to create reverse string 
   		last_char = i-1;
   		break;
   		}
   }
   
   //creating the reverse string
   for (int i = 0;i <= last_char;i++){
   		rev_str[i] = str[last_char - i];
   }
   //printing the reverse string
   printf("%s", rev_str);
}
