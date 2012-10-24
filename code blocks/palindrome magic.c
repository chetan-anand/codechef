#include<stdio.h>
int main()
{
    int i,k,n,t,ans,n1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        ans=1;
        if(n%2==0){n1=n/2;}
        else{n1=(n/2)+1;}
        for(i=1;i<n1;i++)
        {
            ans=ans*10;
        }
        ans=ans+k-1;
        printf("%d",ans);
        if(n%2!=0){ans=ans/10;}
        for(i=1;ans!=0;i++)
        {
            printf("%d",ans%10);
            ans=ans/10;
        }
        printf("\n");
    }
    return 0;
}
