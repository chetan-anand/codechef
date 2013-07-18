#include<stdio.h>
int main()
{
    int t,i,j,k,prime[10009],cnt[10009],n;
    memset(prime,0,10009);
    memset(cnt,0,10009);
    for(i=2;i<10009;i++)
    {
        if(prime[i]==1){continue;}
        for(j=i+i;j<10009;j=j+i)
        {
            prime[j]=1;
            //printf("kjasdn\n");
        }
    }
    /*for(i=0;i<100;i++)
    {
        printf("%d ",prime[i]);
    }*/
    for(i=2;i<10009;i++)
    {
        if(prime[i]==1){continue;}
        for(j=2;(i+2*j)<=10009;j++)
        {
            if(prime[j]==1){continue;}
            cnt[i+2*j]++;
        }
    }
    cnt[1]=cnt[3]=cnt[5]=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",cnt[n]);
    }
    /*for(i=0;i<t;i++)
    {
        printf("%d\n",cnt[2*i+1]);
    }*/
    return 0;
}
