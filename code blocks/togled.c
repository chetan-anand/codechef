#include<stdio.h>
int main()
{
    int n,k,i,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)
        {
            if(k%2==0){break;}
            k=k/2;
        }
        if(i==n+1){printf("%d ON\n",i);}
        else{printf("%d OFF\n",i);}
    }

    return 0;
}
