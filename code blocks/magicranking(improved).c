/*this solution is topbottom version of magic ranking
problem*/

#include<stdio.h>
#define max(a,b) a>b?a:b
int s[102][102];
int dp[102][102];
int maxsum(int i,int j)
{
    if(dp[i][j]>=0){return dp[i][j];}
    if(i==0&&j==0){return s[i][j];}
    if(i==0)
    {
        dp[i][j]=maxsum(i,j-1)+s[i][j];
        return dp[i][j];
    }
    if(j==0)
    {
        dp[i][j]=maxsum(i-1,j)+s[i][j];
        return dp[i][j];
    }
    dp[i][j]=max(maxsum(i-1,j),maxsum(i,j-1))+s[i][j];
    return dp[i][j];
}

int main()
{
    int i,j,t,n;
    float ans;

    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<102;i++)
        {
            for(j=0;j<102;j++)
            {
                dp[i][j]=-1;
            }
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&s[i][j]);
            }
        }

        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d ",s[i][j]);
            }
            printf("\n");
        }*/
        if(maxsum(n-1,n-1)<0){printf("Bad Judges\n");}
        else
        {
            ans=(float)maxsum(n-1,n-1)/(float)(2*n-3);
            printf("%0.6f\n",ans);
        }

    }
    return 0;
}
