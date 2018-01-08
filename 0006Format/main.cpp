#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a, b, c;
    a = n / 100;
    b = (n % 100) / 10;
    c = n % 10;
    while(a --){
        cout << 'B';
    }
    while(b --){
        cout << 'S';
    }
    for(int i = 1; i <= c; i++){
        cout << i;
    }
    return 0;
}
