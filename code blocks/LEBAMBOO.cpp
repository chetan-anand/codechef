#include<stdio.h>
#include<string.h>

int main()
{
    int i,t,n,cnt,sum,sumd,sumh;
    int h[200],d[200];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);sumd=0;sumh=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
            sumh=sumh+h[i];
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&d[i]);
            sumd=sumd+d[i];
        }
        if(n==1)
        {
            if(h[0]<d[0]){printf("-1\n");}
            else{printf("%d\n",h[0]-d[0]);}
            continue;
        }
        if(n==2)
        {
            if(sumd==sumh)
            {
                if(h[0]>d[0]){printf("%d\n",h[0]-d[0]);}
                else{printf("%d\n",d[0]-h[0]);}
            }
            else
            {
                printf("-1\n");
            }
            continue;
        }
        if(n>2)
        {
            if((sumd-sumh)<0){printf("-1\n");}
            else
            {
                if((sumd-sumh)%(n-2)==0)
                {
                    sum=(sumd-sumh)/(n-2);
                    for(i=0;i<n;i++)
                    {
                        if((h[i]+sum-d[i])%2!=0){sum=-1;break;}
                        int temp=(h[i]+sum-d[i])/2;
                        if(temp<0){sum=-1;break;}
                    }
                    printf("%d\n",sum);
                }
                else{printf("-1\n");}
           }
        }

    }
    return 0;
}
