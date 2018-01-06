
#include <iostream>
#include <stdio.h>

using namespace std;
unsigned long long fact(int n){
    unsigned long long res = 1;
    for(int i = 1; i <= n; i ++){
        res = res * i;
    }
    return res;
}
int  main(){
    int n, flag;
    flag = scanf("%d", &n);
    while (flag!= EOF ){
        cout << fact(n) << endl;
        flag = scanf("%d", &n);
    }
    return 0;
}
