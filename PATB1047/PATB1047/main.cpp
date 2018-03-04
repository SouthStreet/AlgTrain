#include <cstdio>
#include <map>
const int maxn = 1010;
int ht[maxn] = { 0 };


int main(){
	int n ;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int team, member, score;
		scanf("%d-%d %d", &team, &member, &score);
		ht[team] += score;
	}
	int k, MAX = -1;
	for(int i = 0; i < maxn; i ++){
		if(ht[i] > MAX){
			k = i;
			MAX = ht[i];
		}
	}
	printf("%d %d\n", k, MAX);//Êä³ö½á¹û

	return 0;
}