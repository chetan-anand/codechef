#include<stdio.h>
int main()
{
    long long int l,r,j,n,n1;
    int b,c,f4,f7,t,k;

    scanf("%d",&t);
    while(t--)
    {
        b=0;
        scanf("%lld %lld",&l,&r);
        for(j=r;j>=l;j--)
        {
            n=j;f4=f7=0;
                for(k=0;n!=0;k++)
                {
                    if(n%10==4){f4++;}
                    if(n%10==7){f7++;}
                    n=n/10;
                }
                if(f4==0||f7==0){continue;}
                c=f4*f7;
                if(c>b){b=c;}
                if(f4+f7==k&&(f7-f4==0||f4-f7==0)){break;}
                if(j==r){l=k;}
                if(l-k>1){break;}
        }
        printf("%d\n",b);
    }
    return 0;
}
