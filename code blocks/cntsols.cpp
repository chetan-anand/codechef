#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#define max(a,b) a>b?a:b

int dp[41];
int n,u;
using namespace std;
int ans;
int nos(int a)
{
    return u/n+(u%n>=a);
}
void process(int x,int y,int z)
{
    ans=ans+nos(x)*nos(y)*nos(z);
}

int main()
{
    int t,i,j,k,m,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&u,&d,&n,&m);
        ans=0;
        for(i=0;i<=39;i++)
        {
            for(j=0;j<=39;j++)
            {
                for(k=0;k<=39;k++)
                {
                    if((i+j+k)%n==m)
                    process(i,j,k);
                }
            }
        }
        printf("%d\n",ans);
    }

	return 0;
}

