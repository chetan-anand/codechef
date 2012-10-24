#include<stdio.h>
int main()
{
    unsigned long int n,m,r;
    int t,i,j,k,a,b;
    scanf("%d",&t);
    for(i=0;i<t;++i)
    {
        r=(2*n-1)/m;
        a=0;
        scanf("%lu %lu",&n,&m);
        for(j=1;j<=r;j++)
        {
            b=j*m+1;
            if(b%2!=0){b++;}
            if((n-b/2+1)>(b/2-1)){k=b/2-1;}else{k=n-b/2+1;}
            a=a+k;
        }
        printf("%d\n",a);
        }
    return 0;
}
