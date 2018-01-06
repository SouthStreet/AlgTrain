#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool first_con(string str);
bool second_con(string str);
int main()
{
    int n;
    string str;
    if(scanf("%d", &n) != EOF){
        for(int i = 0; i< n; i++ ){
            cin >> str;
            if(first_con(str) == true && second_con(str) == true){
                printf("Yes");
            }
            else{
                printf("NO");
                }
        }
    }
    return 0;
}

bool first_con(string str){

    int length = str.length();
    for(int i = 0; i < length; i++){
        if(str[i] != 'P' && str[i] != 'A' || str[i] != 'T'){
           return false;
        }
    }
    return true;
}

bool second_con(string str){
    int length = str.length();
    return true;

}
