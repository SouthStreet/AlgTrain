#include <cstdio>
#include <cmath>
//É¸·¨
const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] = {0};

void Find_Prime(int n){
	for(int i = 2; i < maxn; i ++){//i = 2 -> n
		if(p[i] == false){
			prime[num ++] = i;
		}
		for(int j = i + i; j < maxn; j += i){
			p[j] = true;
		}
		if(num > n){
			return;
		}
	}
	
}
int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	Find_Prime(n);
	int count = n - m + 1;
	for(int i = 0; i < count; i ++){
		if(i == count - 1){
			printf("%d", prime[m + i - 1]);
			break;
		}
		if((i + 1) % 10 != 0)
			printf("%d ", prime[m + i - 1]);
		else
			printf("%d\n", prime[m + i - 1]);
	}
	return 0;
}