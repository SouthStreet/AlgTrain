#include <cstdio>
#include <cstring>

const int maxn = 101;

int main(){
	int a[maxn];
	memset(a, 0, sizeof(a));

	int n, c;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		int temp;
		scanf("%d", &temp);
		a[temp] ++;
	}

	scanf("%d", &c);
	for(int i = 0; i < c; i ++){
		int temp;
		scanf("%d", &temp);
		if(i == c - 1){
			printf("%d", a[temp]);
		}
		else{
			printf("%d ", a[temp]);
		}
	}

	return 0;
}