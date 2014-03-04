#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,k;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        int ans=n;
        while(n>=k)
        {
            ans=ans+n/k;
            n=n/k+n%k;
        }
        printf("%d\n",ans);
    }
    return 0;
}
