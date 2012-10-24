#include<stdio.h>
int main()
{
    int t;
    unsigned long long n,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&n);
        ans=(n-1)*(n-2)/2;
        printf("%llu\n",ans);
    }
    return 0;
}
