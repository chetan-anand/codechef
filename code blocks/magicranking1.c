/*this solution is bottom up dp version for the magic ranking
problem*/

#include<stdio.h>
int max(int a,int b)
{
    if(a>b){return a;}
    return b;
}
int main()
{
    int i,j,k,n,t;
    int s[102][102];
    int dp[102][102];
    float ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&s[i][j]);
                if(i==1 && j==1){dp[i][j]=s[i][j];}
                else if(i==1)
                {
                    dp[i][j]=dp[i][j-1]+s[i][j];continue;
                }
                else if(j==1)
                {
                    dp[i][j]=dp[i-1][j]+s[i][j];continue;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])+s[i][j];
                }
            }
        }
        if(dp[n][n]<0){printf("Bad Judges\n");}
        else
        {
            ans=(float)(dp[n][n])/(float)(2*n-3);
            printf("%.6f\n",ans);
        }
    }
    return 0;
}
