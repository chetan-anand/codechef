#include<stdio.h>
#include<math.h>
int main()
{
    int t,j,flag=0;
    long long int m,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&m,&n);
        for(i=m;i<=n;++i)
        {
            if(i==2){printf("2\n");continue;}
            if(i%2==0||i==1||i==0){continue;}
            flag=0;
            for(j=2;j<=sqrt(i)+1;++j)
            {
                if(i%j==0){flag=1;break;}
            }
            if(flag==0){printf("%lld\n",i);}
        }
        printf("\n");
    }
    return 0;
}
