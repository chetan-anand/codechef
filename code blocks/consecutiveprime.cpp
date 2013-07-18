#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mil 1000008
int prm[mil];
int sum[mil];
void init()
{
    int i,j,k;
    int cnt=0;
    sum[0]=0;
    for(i=2;i<=mil/2;i++)
    {
        if(prm[i]==0){cnt++;sum[cnt]=sum[cnt-1]+i;}
        for(j=2*i;j<=mil;j+=i)
        {
            prm[j]=1;
        }
    }

}
int main()
{
    int i;
    memset (prm,0,sizeof(prm));
    init();
    for(i=1;i<=50;i++)
    {
        printf("%d\n",prm[i]);
    }
    for(i=1;i<=50;i++)
    {
        printf("%d\n",sum[i]);
    }

    return 0;
}
