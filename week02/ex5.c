#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int fst = 0;
	int snd = 1;
	int thd = 1;
	long long current = 0;
	for (int i = 3;i < n;i++){
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
	printf("%lld", current);
}
