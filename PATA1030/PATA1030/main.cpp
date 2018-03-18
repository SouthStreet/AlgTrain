#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXV = 510;
const int INF = 1e9;//无穷大
//n个城市，m条道路，st开始点，ed结束点
//
//
int n, m, st, ed;
int G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], c[MAXV], pre[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s){
	//init
	fill(d, d + MAXV, INF);
	fill(c, c + MAXV, INF);
	d[s] = 0;
	c[s] = 0;
	//循环n次
	for(int i = 0; i < n; i ++){
		//找最小点u
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j ++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;//找不到return
		vis[u] = true;
		//更新 搞v
		for(int v = 0; v < n; v ++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}else if(d[u] + G[u][v] == d[v]){
					if(c[u] + cost[u][v] < c[v]){
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}
void DFS(int v){
	//打印路径
	if(v == st){
		printf("%d ", v);
		return;
	}
	DFS(pre[v]);
	printf("%d ", v);
}
int main(){
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	int u, v;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	for(int i = 0; i < m; i ++){
		scanf("%d%d", &u, &v);
		scanf("%d%d", &G[u][v], &cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra(st);
	DFS(ed);
	printf("%d %d\n", d[ed], c[ed]);
	return 0;
}