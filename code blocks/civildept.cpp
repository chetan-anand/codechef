#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{

    int t,i,j,k;
    double x,y,c,d;
    scanf("%d",&t);
    while(t--)
    {
        d=0.0;
        scanf("%lf %lf %lf",&x,&y,&c);
        //printf("%lf %lf %lf\n",x,y,c);
        while(1)
        {
            double k1,k2,k3;
            k1=sqrt(x*x-d*d);
            k2=sqrt(y*y-d*d);
            k1=(1.0)/k1;
            k2=(1.0)/k2;
            k3=(1.0)/c;
            if(k1+k2>=k3){break;}
            d=d+1.0;

        }
        printf("%d\n",(int)d);
    }
    return 0;

}
