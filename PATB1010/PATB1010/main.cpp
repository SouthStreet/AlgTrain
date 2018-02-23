#include <cstdio>

int main(){
	int const maxn = 1010;
	int a[maxn] = {0};
	int k, e, count = 0;
	while(scanf("%d%d", &k, &e) != EOF){
		a[e] = k;
	}
	a[0] = 0;
	for( int i = 1; i < maxn; i ++){
		a[i - 1] = a[i] * i;
	}
	for(int i = maxn - 1; i >= 0; i --){
		if(a[i] != 0) count ++;
	}
	if(count == 0){
		printf("0 0");
	}
	for(int i = maxn - 1; i >= 0; i --){
		if(a[i] != 0){
			if(count > 1){
				printf("%d %d ", a[i], i);
				count --;
			}else{
				printf("%d %d", a[i], i);
			}
		}
	}
		
	return 0;
}