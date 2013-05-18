/*top down version of dynamic programming for pizza delivery
author:-Chetan Anand*/

#include<stdio.h>
#define min(a,b) a<b?a:b
int h[505];
int k[505];
int ans=h[0];
int minfill(int n)
{
    int i,ans;
    if(n==0){return 0;}
    for(i=0;i<n;i++)
    {
        ans=min(ans,minfill(n));
    }
    return ans;
}
int main()
{
    int t,n;int h[102],k[102][102];
    int i,j,l,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&k[i]);
        }
        ans=minfill(n);
        printf("%d\n",ans);
    }
}
