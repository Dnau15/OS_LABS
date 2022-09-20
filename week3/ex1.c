#include <stdio.h>
#include <stdlib.h>

void foo(int *arr);
int main()
{
	const int x = 10;
	const int *q = &x;
	
	int * p = (int *) calloc (5, sizeof (const int));
	
	for (int i = 0;i < 5;i++){
		*p = x;
		printf("%p\n", p);
		p++;
	}
	
	printf("Enter your age\n");
	
	for (int i = 5;i >= 1;i--){
		scanf("%d", (p-i));
	}
	
	p = p - 5;
	foo(p);
	
	for (int i = 0;i < 5;i++){
		printf("%d\n", *(p+i));
	}
	free(p);	
}
void foo(int *arr){
	const int current_year = 2022;
	for (int i = 0;i < 5;i++){
		*arr = current_year - *arr;
		arr++;
	}
}

