#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct E
{
    int score;
    int num;
}buf[100];
bool cmp(E a,E b){
    if(a.score!= b.score) return a.score < b.score;
    else{
        return a.num < b.num;
    }
}
int main()
{
    int n = 0;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d%d", &buf[i].num, &buf[i].score);
        }
        sort(buf, buf + n, cmp);
        for(int i = 0; i < n; i ++){
            printf("%d %d\n", buf[i].num, buf[i].score);
        }
    }
    return 0;
}
