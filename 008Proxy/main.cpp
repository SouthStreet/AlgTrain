#include<stdio.h>
#include<string.h>

int solve(char p[1000][16],int n,char s[5000][16],int m)
{//每次调用，在目标串中找最长可以访问到的结点，从该结点开始再往后找最长
    int i,j,max;

    max = -1;
    for(i = 0;i < n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(!strcmp(p[i],s[j])) //匹配则返回0,代理服务器只在目标服务器中出现多次也可以
            {
                if(j > max)
                    max = j;
                break;
            }
        }
        if(j == m)  return 0;
    }

    if(n == 1 && max != -1)  //只有一台代理且出现在待访问队列中，无法完成！
        return -1;
    return 1+solve(p,n,s+max,m-max);
}

int main()
{
    int m,n,i;

    while(scanf("%d",&n) != EOF)
    {
        char p[n][16];
        for(i = 0;i <n ;i++)
            scanf("%s",p[i]);

        scanf("%d",&m);
        char s[m][16];
        for(i =0;i < m;i++)
            scanf("%s",s[i]);

        printf("%d\n",solve(p,n,s,m));
    }

    return 0;
}
