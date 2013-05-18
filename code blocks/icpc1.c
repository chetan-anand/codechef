#include<stdio.h>
int main()
{
    int t,i,x[2504],y[2504],ox,oy,fx,fy,temp1,n,flag;
    int cnt,d1,temp,min,d2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }
        scanf("%d %d",&ox,&oy);
        scanf("%d %d",&fx,&fy);
        flag=0;
        temp1=2507;
        cnt=0;
        while(flag!=1)
        {
            for(i=0;i<n;i++)
            {
                if(i==temp1){continue;}
                d1=(ox-x[i])*(ox-x[i])+(oy-y[i])*(oy-y[i]);
                d2=(fx-x[i])*(fx-x[i])+(fy-y[i])*(fy-y[i]);
                if(i==0){min=d1+d2;temp1=0;}
                if(min<d1){min=d1+d2;temp1=i;}
            }
            temp=(ox-fx)*(ox-fx)+(oy-fy)*(oy-fy);
            if(min>temp){min=temp;cnt=cnt+min;}
            else{flag=1;cnt=cnt+min;}
            ox=x[temp1];oy=y[temp1];
        }
        printf("%d\n",cnt);
    }
    return 0;
}
