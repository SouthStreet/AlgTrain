#include <cstdio>
#include <cstring>

const int maxn = 1010;
int dp[maxn][maxn];
char s[maxn];
int main(){
	gets(s);
	int len = strlen(s);
	int ans = 1;
	memset(dp,0, sizeof(dp));
	for(int i = 0; i < len; i ++){
	//boarder
		dp[i][i] = 1;
		if(i < len - 1){
			if(s[i] == s[i + 1]){
				dp[i][i + 1] = 1;//=1 ��ʾ�ǻ����Ӵ�
				ans = 2;
			}
		}
	}
	//״̬ת�Ʒ���
	for(int  L = 3; L <= len; L ++){
		for(int i = 0;i + L - 1 < len; i ++){//i����˵�
			int j = i + L - 1;//j�Ҷ˵�
			if(s[i] == s[j] && dp[i + 1][j - 1] == 1){
				dp[i][j] = 1;
				ans = L;//update ans ΪL
			}
		}
	}
	printf("%d", ans);

	return 0;
}