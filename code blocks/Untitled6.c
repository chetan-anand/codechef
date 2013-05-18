#include<stdio.h>
#define max(a,b) a>b?a:b
int a[10]={1,5,8,9,10,17,17,20,24,30};
int maxrev(int n)
{
    int ans;
    if(n==0)
    {
        return 0;
    }
    else
    {
        int i;
        ans=a[n-1];
        for(i=1;i<n-2;i++)
        {
            ans=max(ans,maxrev(i)+maxrev(n-i));
        }
        return ans;
    }
}
int main()
{

    int i,j,k,ans;
    for(i=0;i<10;i++)
    {
        printf("%d\n",a[i]);
    }
    printf("%d\n",max(2,3));
    ans=maxrev(10);
    printf("%d\n",ans);
    return 0;
}
