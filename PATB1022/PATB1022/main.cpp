#include <cstdio>

int main(){
	int A, B, D;
	scanf("%d %d %d", &A, &B, &D);
	int sum = A + B;
	int  ans[31] = {0}, num = 0;
	while(sum != 0){
		ans[num] = sum % D;
		sum = sum / D;
		num ++;
	}
	if(num == 0){
		printf("0");
	}
	else{
		for(int i = num - 1; i >= 0; i --){
			printf("%d", ans[i]);
		}
	}
	return 0;
}