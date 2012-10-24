#include<stdio.h>
int i,j,k,n,m,a[100][100]
int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            chess(i,j);
        }
    }
    return 0;
}
