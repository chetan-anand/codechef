#include<stdio.h>
#define max(a,b) a>b?a:b
int cutrod(int *a,int n)
{
    int i,ans;
    if(n==0)
    {
        return 0;
    }
    ans=0;
    for(i=1;i<=n;i++)
    {
        ans=max(ans,a[i-1]+cutrod(a,n-i));
    }
    printf("%d\n",ans);
    return ans;
}
int main()
{
    int a[11]={1,5,8,9,10,17,17,20,24,30};
    int ans=cutrod(a,15);
    printf("the maximum revenue is %d\n",ans);
    return 0;
}
