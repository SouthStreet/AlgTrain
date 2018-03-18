#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxc = 210;
const int maxn = 100010;
int A[maxn], dp[maxn];
int ht[maxc];
using namespace std;
int main(){
	int n, m, x;
	scanf("%d%d", &n, &m);
	memset(ht, -1, sizeof(ht));
	for(int i = 0; i < m; i ++){
		scanf("%d", &x);
		ht[x] = i;
	}
	int L, num = 0;
	scanf("%d", &L);
	for(int i = 0; i < L; i++){
		scanf("%d", &x);
		if(ht[x] >= 0){
			A[num ++] = ht[x];
		}
	}

	//LIS模板
	int ans = -1;
	for(int i = 0; i < num; i ++){
		//一次算出一个dp[i]
		dp[i] = 1;//boarder
		for(int j = 0; j < i;j++){
			if(A[j] <= A[i] && (dp[j] + 1 > dp[i])){
				//update dp[i]
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}