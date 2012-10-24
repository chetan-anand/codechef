#include<stdio.h>
int main()
{
    int i,n,m,t,p,l,cnt;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        int a[101]={0};
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&p,&l);
            a[l]=a[l]+p;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&p,&l);
            a[l]=a[l]-p;
        }
        for(i=0;i<=100;i++)
        {
            if(a[i]<0){cnt=cnt-a[i];}
        }
        printf("%d\n",cnt);
    }
    return 0;
}
