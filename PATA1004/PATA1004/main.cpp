#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
const int maxn = 110;
vector<int> G[maxn];
int ans[maxn];
int maxh = 1;
void DFS(int index, int h){//当前的结点 当前的高度
	maxh = max(h, maxh);
	if(G[index].size() == 0){
		//empty
		ans[h]++;
		return;
	}
	for(int i = 0; i < G[index].size(); i ++){
			DFS(G[index][i], h + 1);
	}
}

int main(){
	int n, m, parent, k, child;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i ++){
		scanf("%d %d", &parent, &k);
		for(int j = 0; j < k; j ++){
			scanf("%d", &child);
			G[parent].push_back(child);//加入边
		}
	}
	DFS(1, 1);
	for(int i = 1; i <= maxh; i ++){
		printf("%d", ans[i]);
		if(i < maxh) printf(" ");
	}
	return 0;
}