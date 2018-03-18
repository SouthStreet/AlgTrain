// PATB1051.cpp : 定义控制台应用程序的入口点。
//
#include <cstdio>
#include <cmath>
const int epsilon = 0.01;
int main()
{
	double r1, r2, p1, p2;
	double a, b;
	scanf("%lf %lf %lf %lf", &r1, &r2, &p1, &p2);
	a = r1 * r2 * cos(p1 + p2);
	b = r1 * r2 * sin(p1 + p2);
	if(fabs(a) < epsilon){
		a = 0.0;
	}
	if(fabs(b) < epsilon){
		b = 0.0;
	}
	if(b < 0){
		printf("%.2lf-%.2lfi", a, b);
	}
	else{
		printf("%.2lf+%.2lfi", a, b);
	}
	return 0;
}

