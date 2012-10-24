#include<stdio.h>
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        m=1;
        while(m<n)
        {
            m=m*2;
        }
        m=m/2;
        m=n-m;
        m=2*m+1;
        printf("%d\n",m);
    }
    return 0;
}
