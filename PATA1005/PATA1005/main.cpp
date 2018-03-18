#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int maxn = 110;
int main(){
	char Num[10][10] = {"zero", "one", "two", "three", "four", "five"
						,"six", "seven", "eight", "nine"};
	char str[maxn];
	stack<int> si;
	gets(str);
	int len = strlen(str);
	int sum = 0;
	for(int i = 0; i < len; i ++){
		sum += (str[i] - '0');
	}
	if(sum == 0){
		si.push(0);
	}
	//covert sum into char
	while(sum > 0){
		si.push(sum % 10);
		sum /= 10;
	}
	while(!si.empty()){
		printf("%s",Num[si.top()]);
		si.pop();
		if(!si.empty()) printf(" ");
	}

	return 0;
}