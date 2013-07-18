#include<stdio.h>
#include<algorithm>
int main()
{
    int t,n,a[100000],i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        std::sort(a,a+n);
        for(i=0;i<n;i++)
        {
            printf("%d\n",a[i]);
        }
    }
    return 0;
}
