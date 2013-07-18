#include<stdio.h>
int main()
{
    int t,i,j,k,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&k);
        if(n==1 && m==1){printf("0\n");continue;}
        else if(n==2 && m==1){printf("0\n");continue;}
        else if(m==2 && n==1){printf("0\n");continue;}
        else if(n==1||m==1)
        {
            printf("%d\n",k);
            continue;
        }
        else
        {
            if(k%2==0){printf("%d\n",k/2);}
            else{printf("%d\n",k/2+1);}
        }
    }
    return 0;
}
