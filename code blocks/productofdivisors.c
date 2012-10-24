#include<stdio.h>
int main()
{
    int t,i,n,ans,flag,temp;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d",&n);
        ans=1;
        for(i=2;i<=temp&&flag==1;i++)
        {
            if(n%i==0){ans=ans*i;if(flag==0){temp=n/i;temp=(temp+i)/2;flag=1;}}
        }
        if(ans>9999){ans=ans/10000;}
        printf("%d\n",ans);
    }
    return 0;
}
