#include<stdio.h>
#include<string.h>

int dp[2000][2000];
int main()
{
    int t,n,s[50],sum,nom,tog,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            sum=sum+s[i];
        }

        memset(dp,-1,sizeof(dp));
        nom=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==-1){nom++;}
        }
        tog=(n*(n-1))/2;

        if(sum<tog)
        {

        }

    }
    return 0;
}
