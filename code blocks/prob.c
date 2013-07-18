#include<stdio.h>
int main()
{
    int t1,t2,t3,t4;
    int t;
    double ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&t1,&t2,&t3,&t4);
        ans=(double)t1/(double)(t2+t1);
        printf("%.6lf\n",ans);
    }
    return 0;
}
