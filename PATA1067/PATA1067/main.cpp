#include<cstdio>
#include<algorithm>
const int maxn = 100010;
int pos[maxn];
using namespace std;
int main(){
	int n, num;
	scanf("%d", &n);
	int left = n - 1, ans = 0;
	for(int i = 0; i < n; i ++){
		scanf("%d", &num);
		pos[num] = i;
		if(num == i && num != 0){
			left --;
		}
	}
	int k= 1;
	while(left > 0){
		if(pos[0] == 0){
			while(k < n){
				if(pos[k] != k){
					swap(pos[0], pos[k]);
					ans ++;
					break;
				}
				k ++;
			}
		}
		while(pos[0] != 0){
			swap(pos[0], pos[pos[0]]);
			ans ++;
			left --;
		}
	}
	printf("%d", ans);
	return 0;
}