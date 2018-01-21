#include <cstdio>

int main(){
	const int maxn = 100010;
	int school[maxn] = {0}, T = 0;
	int i, j;
	scanf("%d", &T);
	int N = T;
	while(T --){
		scanf("%d%d", &i, &j);
		school[i] += j;
	}
	i = j = 0;
	for(int k = 1; k <= N; k++){
		if(j < school[k]){
			i = k;
			j = school[k];
		}
	}
	printf("%d %d", i, j);
	return 0;
}