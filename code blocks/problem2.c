#include<stdio.h>
int main()
{
    int t,i,j,n,b[7],l,len;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=0;n!=0;j++)
        {
            b[j]=n%10;
            n=n/10;
            printf("%d\n",b[j]);
        }
        l=j;
        printf("%d\n",l);
    if(l%2==0){len=l/2-1;}else{len=l/2;}

        for(j=0;;j++)
        {
            if(b[len+j]!=9){b[len+j]=b[len+j]+1;break;}
            else{b[len+j]=0;}
        }
        for(j=0;j<len;j++)
        {
            b[j]=b[l-j-1];
        }
        n=0;
        for(j=0;j<l;j++)
        {
            n=n*10+b[j];
            printf("%d\n",b[j]);
        }
        printf("%d\n",n);
    }
    return 0;
}
