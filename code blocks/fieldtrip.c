#include<stdio.h>
#define s(t) scanf("%d",&t)
#define fill(a, val) memset(a, val, sizeof(a))
#define maxs 1001
#define min(b,c) b<c?b:c
#define max(b,c) b>c?b:c

double com[maxs+2][maxs+2];
void preprocess()
{
    int i,j;
    fill(com,0);
    for(i=0;i<=maxs;i++)
    {
        com[i][0]=com[i][i]=1.0;
        for(j=1;j<i;j++)
        {
            com[i][j]=com[i-1][j]+com[i-1][j-1];
        }
    }
}

/*void solve(int s,int n,int m,int k)
{
    double den=com[s-1][n-1];
    double num=0.0;
    int i;
    for(i=k;i<m-1;i++)
    {
        num=num+com[m-1][i]*com[s-m][n-i-1];
    }
    printf("%.6lf\n", num/den);
}*/
int main()
{
    int t,s,n,m,k;
    preprocess();
    scanf("%d",&t);
    while(t--)
    {
        /*scanf("%d %d %d %d",&s,&n,&m,&k);
        solve(s,n,m,k);*/

    }
    return 0;
}
