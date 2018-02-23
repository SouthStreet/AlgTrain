#include <cstdio>
#include <cstring>

int main(){
	char str1[100];
	char str2[100];

	bool hashTable[128] = {false};
	scanf("%s", &str1);
	scanf("%s", &str2);

	//a 97 A 65
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len1; i ++){
		char c1, c2;
		int j;
		for( j = 0; j < len2; j ++){
			c1 = str1[i];
			c2 = str2[j];
			if(97 <= c1 && c1 <= 122){
				c1 -= 32;
			}
			if(97 <= c2 && c2 <= 122){
				c2 -= 32;
			}
			if(c1 != c2){
				continue;
			}else{
				break;
			}
		}
		if(i != len1 && j == len2){
			//str2 not found
			if(hashTable[c1] == false)//not output
			{
				hashTable[c1] = true;
				printf("%c", c1);
			}
		}

	}

	return 0;
}