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
}
int main()
{

}
