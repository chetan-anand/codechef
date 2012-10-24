#include<stdio.h>
int main()
{
    int t,n,min,a,i,cnt;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d",&n);if(n==1){scanf("%d",&a);printf("1\n");continue;}
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(i==0){cnt++;min=a;continue;}
            if(a<=min){cnt++;min=a;}
        }
        printf("%d\n",cnt);
    }
    return 0;
}
