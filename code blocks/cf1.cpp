#include<stdio.h>
#include<algorithm>
int main()
{

    int n,m,a[200],b[200];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }

    std::sort(a,a+n);
    std::sort(b,b+m);
    //printf("%d %d %d %d\n",a[0],a[n-1],b[0],b[m-1]);
    if(2*a[0]>=b[0] || a[n-1]>=b[0])
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",a[n-1]);
    }
    return 0;
}
