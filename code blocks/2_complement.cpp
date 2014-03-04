#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int solve(long long int a)
{
 if(a == 0) return 0 ;
 if(a % 2 == 0) return solve(a - 1) + __builtin_popcount(a) ;
 return (a + 1) / 2 + 2 * solve(a / 2) ;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long int t,a,b,i,j,k,temp;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        //printf("%d\n",solve(a));
        if(a>b){temp=a;a=b;b=temp;}
        if(a>0)
        {
            printf("%lld\n",solve(b)-solve(a-1));
        }
        else if(b<0)
        {
            a=-1*a;b=-1*b;
            temp=(a*32)-solve(a-1);
            temp=temp+solve(b-2)-((b-1)*32);
            printf("%lld\n",temp);
        }
        else
        {
            a=-1*a;
            temp=(a*32)-solve(a-1);
            temp=temp+solve(b);
            printf("%lld\n",temp);
        }
    }
    return 0;
}
