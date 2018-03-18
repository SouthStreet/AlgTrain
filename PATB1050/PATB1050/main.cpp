#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 10010;
int matrix[maxn][maxn], A[maxn];
bool cmp(int a, int b){
	return a > b;
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i ++){
		scanf("%d", &A[i]);
	}
	if(N == 1){
		printf("%d", A[0]);
		return 0;
	}
	sort(A, A + N, cmp);
	int m = (int )ceil(sqrt(1.0 * N));
	while (N % m != 0){
		m ++;
	}
	//n为列数 ij 为当前欲填的位置,now指向序列中当前待填的数下标
	int n = N / m, i = 1, j = 1, now = 0;
	//mn ij是数组下标 now 是现在输出的
	int U = 1, D = m, L = 1, R = n;
	while (now < N){
		while (now < N && j < R){
			matrix[i][j] = A[now++];
			j ++;
		}
		while(now < N && i < D){
			matrix[i][j] = A[now++];
			i ++;
		}
		while(now < N && j > L){
			matrix[i][j] = A[now++];
			j --;
		}
		while(now < N && i > U){
			matrix[i][j] = A[now++];
			i --;
		}
		//缩进
		U ++, D --, L ++, R --;
		i ++, j ++;
		if(now == N - 1){
			matrix[i][j] = A[now ++];
		}
	}
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			printf("%d", matrix[i][j]);
			if(j < n) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}