#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
	double I, res = 0.0;

	scanf("%lf", &I);
	if(I <= 100000){
		res = I * 0.1;
	}
	else if(I <= 200000){
		res = 10000.0 + (I - 100000) * 0.075;
	}
	else if(I <= 400000){
		res = 17500.0 + (I - 200000) * 0.05;
	}
	else if(I <= 600000){
		res = 27500.0 + (I - 400000) * 0.015;
	}
	else{
		res = 36500.0 + (I - 1000000) * 0.01;
	}
	printf("%.2f", res);
	return 0;
}