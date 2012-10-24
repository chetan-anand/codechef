#include<stdio.h>
int t[250][250];
int main()
{
    int i,j,k,n,m,s,g,d;
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            scanf("%d",&t[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if((t[j][i]+t[i][k])<t[j][k])
                {
                    t[j][k]=t[j][i]+t[i][k];
                }
            }
        }
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&s,&g,&d);
        printf("%d %d\n",t[s][g]+t[g][d],t[s][g]+t[g][d]-t[s][d]);
    }
    return 0;
}
