#include<stdio.h>
int main()
{
    long long int a[500],cnt;
    int flag,i,j,k,it,s1,s2,n,t,l;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        flag=0;
        scanf("%d %d %d %d %d",&it,&s1,&s2,&k,&n);

        a[1]=it;
        for(j=2;j<=s1+1;j++)
        {
            a[j]=a[j-1]+1;

            if(j==n){printf("%lld\n",a[n]%100000007);flag=1;break;}
        }
        if(flag==1){continue;}
        for(j=s1+2;j<=s1+1+s2;j++)
        {
            a[j]=2*a[j-1];

            if(j==n){printf("%lld\n",a[n]%100000007);flag=1;break;}
        }
        if(flag==1){continue;}
        for(j=s1+s2+2;;j++)
        {
            cnt=1;
            if(j==s1+s2+2)
            {
                for(l=0;l<k;l++)
                {cnt=cnt*a[j-1-l];}
               a[j]=cnt;
            }
           else
            {
               a[j]=(a[j-1]/a[j-1-k])*a[j-1];

            }
            if(j==n){printf("%lld\n",a[n]%100000007);flag=1;break;}
        }
    }
    return 0;
}
