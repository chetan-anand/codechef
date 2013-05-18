#include<stdio.h>
int main()
{
    long long int i,j,k,t,n,a,b,c,d,e,temp,ans;
    scanf("%lld",&t);

    while(t--)
    {
        a=1;b=2;c=5;d=12;
        scanf("%lld",&n);
        if(n==1){printf("1\n");continue;}
        if(n==2){printf("2\n");continue;}
        if(n==3){printf("5\n");continue;}
        if(n==4){printf("12\n");continue;}
        for(i=5;i<=n;i++)
        {
            ans=d+2*c+3*b+a;
            //if(ans>mod){ans=ans%mod;}
            a=b;
            b=c;
            c=d;
            d=ans;
        }
        printf("%lld\n",d);
    }
    return 0;
}
