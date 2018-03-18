#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char N1[20], N2[20], temp[20];
int radix, tag;
int Map[256];
void init(){
	for(char c = '0'; c <= '9'; c ++){
		Map[c] = c - '0'; 
	}
	for(char c = 'a'; c <= 'z'; c ++){
		Map[c] = c - 'a' + 10;
	}
}
long long convertN10(char N[], int radix){
	long long ans = 0;
	int len = strlen(N);
	for(int i = 0; i < len; i ++){
		ans = ans * radix + Map[N[i]];
		if(ans < 0) return -1;
	}
	return ans;
}
int findMaxDig(char N2[]){
	int ans = -1, len = strlen(N2);
	for(int i = 0; i < len; i ++){
		ans = max(ans, Map[N2[i]]);
	}
	return ans;
}
int cmp(char N2[], long long radix, long long t){
	int len = strlen(N2);
	long long num = convertN10(N2, radix);
	if(num < 0){
		//溢出
		return 1;//大于返回1
	}
	if(t > num) return -1;
	else if(t == num) return 0;
	else return 1;
}
long long binSearch(char N2[], long long left, long long right, long long t){
	long long mid;
	while(left <= right){
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, t);//N2按mid为radix和t比较
		if(flag == 0) return mid;
		else if(flag == -1) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
int main(){
	init();
	scanf("%s %s %d %d", &N1, &N2, &tag, &radix);
	if(tag == 2){
		//exchage N1 N2
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}
	long long t = convertN10(N1, radix);
	long long left = findMaxDig(N2) + 1;
	long long right = max(t, left) + 1;
	long long ans = binSearch(N2, left, right, t);
	if(ans == -1)printf("Impossible\n");
	else printf("%lld\n", ans);
	return 0;
}