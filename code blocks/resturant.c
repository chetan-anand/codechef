#include<stdio.h>
#define min(a,b) a<b?a:b
int main()
{
    int t,i,j,k,minv,l,b,area;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&l,&b);
        area=l*b;
        minv=min(l,b);
        for(i=minv;i>=1;--i)
        {
            if(l%i==0 && b%i==0 )
            {
                if(area%(i*i)==0)
                {
                    printf("%d\n",area/(i*i));
                    break;
                }

            }

        }
    }
    return 0;
}
