#include <cstdio>

int main(){
	char isbn[14];
	int sum = 0, check;
	int k = 1;
	for(int i = 1; i <= 12; i ++){
		scanf("%c", &isbn[i]);
		if(isbn[i] == '-'){;}//nothin to do
		else{
			sum += k * (isbn[i] - '0');
			k ++;
		}
	}
	scanf("%c", &isbn[13]);
	if(isbn[13] == 'X') check = 10;
	else check = isbn[13] - '0';
	if(sum % 11 == check) printf("Right");
	else {
		if(sum % 11 == 10) isbn[13] = 'X';
		else isbn[13] = '0' + sum % 11;
		for(int i = 1; i <= 13; i ++){
			printf("%c", isbn[i]);
		}
	}
	return 0;
}