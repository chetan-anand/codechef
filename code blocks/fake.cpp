#include<stdio.h>
int main()
{
    int n,i,j,first,last;
    long long int a[100001]={1,0,2,3,7};
    //scanf("%d",&n);
    n=5;
    /*for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }*/
    for(first=0;first<=n-4;++first)
    {
        for(last=first+3;last<=n-1;last++)
        {
            for(i=first+1;i<=last-2;++i)
            {
                for(j=i+1;j<=last-1;++j)
                {
                    if((a[first]^a[i]^a[j]^a[last])==0){printf("Yes");return 0;}
                }
            }
        }
    }
    printf("No");
    return 0;
}
