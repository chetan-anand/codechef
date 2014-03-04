#include<stdio.h>
#include<string.h>
#include<math.h>
bool overlucky(int x)
{
    while(x!=0)
    {
        if((x%10)==4 || (x%10)==7){return true;}
        x=x/10;
    }
    return false;
}
int main()
{
    int t,i,j,k,n,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cnt=0;
        for(i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                if(overlucky(i)){cnt++;}
                if(overlucky(n/i)){cnt++;}
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
