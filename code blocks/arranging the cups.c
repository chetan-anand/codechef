#include<stdio.h>
#include<math.h>
int main()
{
    int t,n,j,sq;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sq=sqrt(n);
        for(j=sq;j!=0;j--)
        {
            if(n%j==0){j=(n/j)-j;break;}
        }
        printf("%d\n",j);
    }
}
