#include <cstdio>
#include <cstring>

int main(){
	int T;
	scanf("%d", &T);
	while(T --){
		char str[100];
		scanf("%s", str);//cin str
		int len = strlen(str);
		int num_p = 0, num_t = 0, other = 0;
		int loc_p = 0, loc_t = 0;
		for(int i = 0; i < len; i++){//condition 1
			if(str[i] == 'P'){
				num_p ++;
				loc_p = i;
			}else if(str[i] == 'T'){
				num_t ++;
				loc_t = i;
			}else if(str[i] != 'A'){
				other ++;
			}
		}
		if((num_p != 1)||(num_t != 1)||(other != 0)||((loc_t - loc_p) <= 1)){
			//gg
			printf("NO\n");
			continue;//only break this loop
		}
		//start condition 2
		int x = loc_p, y = loc_t - loc_p - 1, z = len - loc_t - 1;
		if((z - (y - 1) * x) == x){
		//correct
			printf("YES\n");
		}else{
			printf("NO\n");
		}

	}
	return 0;
}