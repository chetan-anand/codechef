#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
int dp[200][200],t[200],p[200];
//dp[i][j]=maximum points get with i elements and j time
int maxv,temp,n;
int solve(int i,int j)
{
    printf("called\n");

    if(dp[i][j]!=0){return dp[i][j];}
    int k;
    dp[i][j]=max(solve(i-1,j),solve(i-1,j-t[i-1])+p[i-1]);
    return dp[i][j];
}



int main()
{
    int i,j,k,c[200],tc,w;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&w);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&c[i],&p[i],&t[i]);
            p[i]=p[i]*c[i];
        }

        printf("%d\n",solve(n,w));
    }
    return 0;
}
