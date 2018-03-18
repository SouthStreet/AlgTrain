#include <cstdio>

const int maxn = 1111;
double p[maxn] = {0};

int main(){
	int k;
	scanf("%d", &k);
	int x;
	double y;
	int count = 0;
	for(int i = 0; i < k; i ++){
		scanf("%d%lf", &x, &y);
		p[x] = y;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i ++){
		scanf("%d%lf", &x, &y);
		p[x] += y;
	}
	for(int i = 0; i < maxn; i ++){
		if(p[i] != 0){
			count ++;
			}
	}
	printf("%d", count);
	for(int i = maxn - 1; i >= 0; i --){
		if(p[i] != 0) printf(" %d %.1f", i, p[i]);
	}
	
	return 0;
}