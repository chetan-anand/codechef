///Djisktra Algorithm --------------------------------------  O(v*logv)


#include<stdio.h>
#include<limits.h>

int main()
{
    int i,j,k,n,t,temp,min,len,cnt;
    int ch[2600];
    int x[2506],y[2506];
    int len[2506];
    int d[2600];
    /*for(i=0;i<10;i++)
    {
        printf("%d\n",d[i]);
    }*/
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x[i],&y[i],&);
            ch[i]=0;
            d[i]=INT_MAX;
        }
        scanf("%d %d",&x[0],&y[0]);
        scanf("%d %d",&x[n+1],&y[n+1]);

        d[n+1]=INT_MAX;
        ch[n+1]=0;

        /*for(i=0;i<=n+1;i++)
        {
            printf("%d %d\n",x[i],y[i]);
            //printf("%d\n",d[i]);
        }*/

        ch[0]=1;
        min=0;
        d[min]=0;
        for(j=0;min!=n+1;j++)
        {

            ///updating the vertices
            for(i=1;i<=n+1;i++)
            {
                if(ch[i]==0 && i!=min)
                {
                    len=(x[min]-x[i])*(x[min]-x[i])+(y[min]-y[i])*(y[min]-y[i]);
                    if((len+d[min])<d[i]){d[i]=d[min]+len;}
                }
            }
            //printf("%d\n",d[min]);
            temp=INT_MAX;

            ///finding the vertices with local minimum distance
            for(i=1;i<=n+1;i++)
            {
                if(ch[i]==0 && i!=min)
                {
                    if(temp>d[i]){min=i;temp=d[i];}
                }
            }
            ch[min]=1;
        }
        /*for(i=0;i<=n+1;i++)
        {
            printf("%d ",d[i]);
        }*/
        printf("%d\n",d[n+1]);
    }
    return 0;
}
