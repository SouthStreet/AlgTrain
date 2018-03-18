#include <cstdio>
#include <algorithm>

const int maxn = 1010;
int P[maxn];//第i列皇后的行号
bool ht[maxn] = {false};//第x行放了没
int cnt = 0;
int n = 8;
void gP(int index){
	if(index == n + 1){
		cnt ++;
		return;
	}
	for(int x = 1; x <= n; x ++){
		//x是还没放 准备放一发
		if(ht[x] == false){
			bool flag = true;//能不能放呢
			for(int pre = 1; pre < index; pre ++){
				if(abs(index - pre) == abs(x - P[pre])){
					//index,pre都是列号 x,P[pre]都是行号
					//GG 这个x放不了了
					flag = false;
					break;
				}
			}//检查完成
			if(flag){
					P[index] = x;
					ht[x] = true;
					gP(index + 1);
					ht[x] = false;
				}
		}
	}
}
int main(){

	gP(1);
	printf("%d", cnt);
	return 0;
}
