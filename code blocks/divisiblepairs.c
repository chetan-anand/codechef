#include<stdio.h>
int main()
{
    unsigned long int n,m;
    //int a[3]={2,4,1},b[3]={3,3,6};
    int t=3,i,j,k,c;
    scanf("%d",&t);
    for(i=0;i<t;++i)
    {
        scanf("%lu %lu",&n,&m);
        //n=a[i];m=b[i];
        c=0;
        if((2*n-1)<m){printf("0\n");}
        else
        {
        for(j=2;j<=n;++j)
        {
            for(k=1;k<j;++k)
            {
                if((j+k)<m){break;}
                if(m%(j+k)==0)
                {
                    c++;
                }
            }
        }
        printf("%d\n",c);
        }
    }
    return 0;
}
