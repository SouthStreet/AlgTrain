#include <cstdio>
#include <cstring>

const int maxn = 256;
const int MAXL = 1010;

int main(){
	int ht[maxn];
	memset(ht, 0, sizeof(ht));
	char str1[MAXL], str2[MAXL];
	int miss = 0;

	gets(str1);
	gets(str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for(int i = 0; i < len1; i++){
		ht[str1[i]] ++;
	}
	for(int i = 0; i < len2; i ++){
		ht[str2[i]] --;
		if(ht[str2[i]] < 0) miss ++;
	}
	
	if(miss > 0)printf("No %d", miss);
	else printf("Yes %d", len1 - len2);
	


	return 0;
}