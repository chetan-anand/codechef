#include<stdio.h>
#include<math.h>
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        i=sqrt(n);
        printf("%d\n",i);
    }
    return 0;
}
