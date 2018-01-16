#include <stdio.h>

int main(){
	int n = 20;
	int a[51];
	a[1] = a[2] = 1;
	for(int i = 3; i <= n; i ++){
		a[i] = a[i-1] + a[i-2];
	}
	for(int i = 1; i < n; i ++){
		printf("%d\n", a[i]);
	}
	printf("%d", a[n]);
	return 0;
}
