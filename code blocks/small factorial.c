#include<stdio.h>
void main()
{
    int t,n,i;
    long long int ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=1;
        for(i=n;i>=2;i--)
        {
            ans*=i;
        }
        printf("%lld\n",ans);
    }
}
