#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int n, p, k;
vector<int> facNum, ans, temp;
int maxFacSum = -1;
int power(int x){
	int res = 1;
	for(int i = 0; i < p; i ++){
		res *= x;
	}
	return res;
}
void init(){
	int i = 0, temp = 0;
	while(temp <= n){
		facNum.push_back(temp);
		temp = power(++i);
	}	
}

void DFS(int index, int nowK, int sum, int facSum){//sum最后等于n facSum最后要最大
	if(sum == n && nowK == k){
		//搜索成功
		if(facSum > maxFacSum){
			maxFacSum = facSum;
			ans = temp;
		}
		return;
	}
	if( sum > n || nowK > k){
		//超出边界
		return;
	}
	//index选中
	if(index >= 1){
		temp.push_back(index);
		DFS(index, nowK + 1, sum + facNum[index], facSum + index);
		temp.pop_back();
		DFS(index - 1, nowK, sum, facSum);
	}
	
}

int main(){
	scanf("%d%d%d", &n, &k, &p);
	init();
	DFS(facNum.size() - 1, 0, 0, 0);
	if(maxFacSum == -1){
		printf("Impossible\n");//GG
	}
	else{
		printf("%d = %d^%d", n, ans[0], p);
		for(int i = 1; i < ans.size(); i ++){
			printf(" + %d^%d", ans[i], p);
		}
	}
	return 0;
}

