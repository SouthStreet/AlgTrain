#include <cstdio>
#include <algorithm>
int const maxn = 11;
int count = 0,
	n = 8,
	P[maxn];
bool hashTable[maxn] = {false};

void generateP(int index){
	if(index == n + 1)//recurse boarder
	{
		bool flag = true;
		for(int i = 1; i <= n; i ++){
			for(int j = i + 1; j <= n; j ++){
				if(abs(i - j) == abs(P[i] - P[j])){
					flag = false;
				}
			}
		}
		

	}
}

int main(){

	return 0;
}