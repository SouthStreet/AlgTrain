#include <cstdio>
#include <algorithm>

const int maxn = 10010;
const int maxv = 110;
using namespace std;

int dp[maxv] = {0};
int w[maxn];
bool choice[maxn][maxv], flag[maxn];

bool cmp(int a, int b){
	return a > b;
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++){
		scanf("%d", &w[i]);
	}//w[i]��1��n
	sort(w + 1, w + n + 1, cmp);
	for(int i = 1; i <= n; i ++){
		for(int v = m; v >= w[i]; v --){
			if(dp[v] <= dp[v - w[i]] + w[i])//choose
			{
				dp[v] = dp[v - w[i]] + w[i];
				choice[i][v] = true;
			}else{
				choice[i][v] = false;//������
			}
		}
	}
	//dp finished
	//get flag
	if(dp[m] != m) printf("No Solution");
	else{
		//��¼����·��
		int num = 0, v = m;
		for(int k = n; k >= 0; k --){
			if(choice[k][v] == true){
				flag[k] = true;
				v-= w[k];
				num ++;
			}else{
				flag[k] = false;
			}
		}
		//�������
		for(int i = n; i >= 1; i --){
			//��С�������
			if(flag[i] == true){
				printf("%d", w[i]);
				num --;
				if(num > 0) printf(" ");
			}
		}
	}
	return 0;
}