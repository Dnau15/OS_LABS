#include<stdio.h>

void tribonacci(int n);

int main(){
	int n;
	scanf("%d", &n);
	printf("Tribonacci(4) = ");
	tribonacci(4);
	printf("Tribonacci(36) = ");
	tribonacci(36);
	tribonacci(n);
}

void tribonacci(int n){
	int fst = 0;
	int snd = 1;
	int thd = 1;
	long long current = 0;
	for (int i = 3;i <= n;i++){
		current = fst + snd + thd;
		fst = snd;
		snd = thd;
		thd = current;
	}
	if (n == 0) current = 0;
	else
	if (n == 1) current = 1;
	else 
	if (n == 2) current = 1;
	printf("%lld\n", current);
}
