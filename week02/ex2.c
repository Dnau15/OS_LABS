#include<stdio.h>
#include<string.h>
int main(){
   char str[256];
   char rev_str[256];
   fgets(str, 256,stdin);
   int len = strlen(str);
   int last_char = 0;
   for (int i = 0;i < len; i++){
   	if ((str[i] == '.') || (str[i] == '\n')) {
   	last_char = i-1;
   	break;
   	}
   }
   
   for (int i = 0;i <= last_char;i++){
   	rev_str[i] = str[last_char - i];
   }
   printf("%s", rev_str);
}
