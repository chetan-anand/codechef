#include<stdio.h>
int main()
{
    int t;
    double p,con;
    scanf("%d",&t);
    while(t--)
    {
        con=10000.0;
        scanf("%lf",&p);
        if(1.0-p>p){p=1.0-p;}
        printf("%.6lf\n",p*con*(3.0-2*p));
    }
    return 0;
}
