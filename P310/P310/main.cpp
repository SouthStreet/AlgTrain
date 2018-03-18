//PAT A1103
#include<stdio.h>
#include<vector>
using namespace std;

vector<int> square,ans,temp;
int n,k,p,max_sum=-1;

int column(int x)
{
	int ppp = p;
    int result=1;
    while(ppp)
    {
        result=result*x;
        ppp--;
    }
    return result;
}

void init()
{//平方初始化
    int temp=0,i=0;
    while(temp<=n)
    {
        square.push_back(temp);
        temp=column(++i);
    }
}

void dfs(int index,int numk,int sum_sq,int sum_di)
{
    if(numk==k && sum_sq==n)
    {
        if(sum_di>max_sum)
        {
            ans=temp;
            max_sum=sum_di;
        }
        return;
    }
    if(numk>k || sum_sq>n)
        return;
    if(index-1>=0)
    {
//        选这个数,可以重复选择该数
        temp.push_back(index);
        dfs(index,numk+1,sum_sq+square[index],sum_di+index);
//        不选这个数
        temp.pop_back();
        dfs(index-1,numk,sum_sq,sum_di);
    }
}

int main()
{
    scanf("%d%d%d",&n,&k,&p);//
    init();
    dfs(square.size()-1,0,0,0);
    if(max_sum==-1)
        printf("Impossible\n");
    else
    {
        printf("%d= %d^%d",n,ans[0],p);
        for(int i=1;i<ans.size();i++)
            printf(" + %d^%d",ans[i],p);
    }
    return 0;
}