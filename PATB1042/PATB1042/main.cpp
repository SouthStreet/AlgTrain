#include <cstdio>
#include <cstring>
const int maxn = 1010;

char str[maxn];
int ht[30] = {0};
int main(){
	gets(str);
	int len = strlen(str);
	for(int i = 0; i < len; i ++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			ht[str[i] - 'a']++;
		}else if(str[i] >= 'A' && str[i] <= 'Z'){
			ht[str[i] - 'A'] ++;
		}
	}
	int k = 0;
	for(int i = 0; i < 26; i ++){
		if(ht[i] > ht[k]){
			k = i;
		}
	}
	printf("%c %d\n", 'a' + k, ht[k]);

	return 0;
}