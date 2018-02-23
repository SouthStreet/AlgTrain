#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
bool cmp(int a, int b){
	return a > b;
}

int main(){
	const int maxn = 10000;
	bool hashTable[maxn] = {false};
	int a[110];
	int k, n;
	scanf("%d", &k);
	for(int i = 0; i < k; i ++){
		scanf("%d", &a[i]);
		int m = a[i];//cal till m == 1
		while(m > 1){
			if(m % 2 == 1){
				//odd
				m = (m * 3 + 1) / 2;
			}else{
				m /= 2;
			}
			hashTable[m] = true; 
		}
	}
	//hash finished
	//now sort the a[]
	sort(a, a + k, cmp);
	vector<int> res;
	for(int i = 0; i < k; i ++){
		if(hashTable[a[i]] == false){
			//not covered needed to be printed
			res.push_back(a[i]);
		}
	}
	for(int i = 0; i < res.size(); i ++){
		if(i < res.size() - 1){
			printf("%d ", res[i]);
		}
		else{
			printf("%d", res[i]);
		}
	}
	
	return 0;
}