/* here we are finding gcd of two natural number
 by euclidean algorithm which is fastest way to
 find gcd between two natural numbers
*/
#include<stdio.h>
int gcd(int a,int b)
{
    int temp,m;
    if(b>a){temp=a;a=b;b=temp;}
    while(b!=0)
    {
        m=a%b;
        a=b;
        b=m;
    }
    return a;
}
int main()
{
    printf("%d",gcd(13,12));
    return 0;
}
