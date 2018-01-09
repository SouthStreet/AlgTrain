#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

struct E
{
    char name[15];
    char code[15];
    int score;
}buf[100];
bool cmp(E a,E b){
    return a.score < b.score;
}
int main()
{
    int n = 0;
    if(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%s%s%d", buf[i].name, buf[i].code, &buf[i].score);
        }
        sort(buf, buf + n, cmp);
    }
    printf("%s %s\n", buf[n - 1].name, buf[n - 1].code);
    printf("%s %s", buf[0].name, buf[0].code);
    return 0;
}
