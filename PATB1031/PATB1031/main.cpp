#include <cstdio>
#include <cstring>

int main(){
	int w[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	int n,
		sum = 0,
		Z;
	char id[20];
	bool allpass = true;
	scanf("%d", &n);
	for(int k = 0; k < n; k ++){//n¸öcase
		sum = 0;
		//cin all id
		scanf("%s", &id);
		int i;
		for(i = 0; i < 17; i ++){//cal
			if(id[i] > '9' || id[i] < '0'){
				break;//exception
			}else{
				sum += w[i] * (id[i] - '0');
			}
		}
		bool flag = true;
		if(i < 17){
			flag = false;//print id
		}
		else{
			Z = sum % 11;
			if(id[17] != M[Z]){
				flag = false;
			}
		}
		if(flag == false){
			allpass = false;
			for(int j = 0; j < 18; j ++){
				printf("%c", id[j]);
			}
			printf("\n");
		}
	}
	if(allpass){
		printf("All passed");
	}
	return 0;
}