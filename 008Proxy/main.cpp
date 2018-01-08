#include<stdio.h>
#include<string.h>

int solve(char p[1000][16],int n,char s[5000][16],int m)
{//ÿ�ε��ã���Ŀ�괮��������Է��ʵ��Ľ�㣬�Ӹý�㿪ʼ���������
    int i,j,max;

    max = -1;
    for(i = 0;i < n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(!strcmp(p[i],s[j])) //ƥ���򷵻�0,���������ֻ��Ŀ��������г��ֶ��Ҳ����
            {
                if(j > max)
                    max = j;
                break;
            }
        }
        if(j == m)  return 0;
    }

    if(n == 1 && max != -1)  //ֻ��һ̨�����ҳ����ڴ����ʶ����У��޷���ɣ�
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
