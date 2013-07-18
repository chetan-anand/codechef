#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

int shad[110][110];
int dp[110][110][2];

void shadow(int n,int,m,int** mat)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(mat[i][j]=='1')
            {
                shad[i+1][j]++;
                shad[i-1][j]++;
                shad[i][j+1]++;
                shad[i][j-1]++;
            }
        }
    }
}

int solve(int n,int m,int** mat)
{
    int i,j,k;
    dp[0][0][0]=dp[0][0][1]=shad[0][0]-
}

int main()
{
    int i,j,k,shad[110][110];
    char mat[110][110];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",mat[i]);
        }
        memset(shad,0,sizeof(shad));
        shadow(n,m,mat);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%d ",shad[i][j]);
            }
            printf("\n");
        }

    }


    retunr 0;
}
