#include<stdio.h>
#include<string.h>
#include<algorithm>
int main()
{
    int i,j,k,t,n,m,temp,c,cnt;
    int p[120],v[120];
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        memset(p,0,sizeof(p));
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&temp);
            p[temp]++;
        }


        for(j=0;j<n;j++)
        {
            scanf("%d",&c);
            for(i=0;i<c;i++)
            {
                scanf("%d",&v[i]);
            }
            if(p[j]==0){continue;}
            std::sort(v,v+c);
            /*for(i=0;i<c;i++)
            {
                printf("%d ",v[i]);
                printf("\n");
            }*/
            if(p[j]>c)
            {
                //printf("f\n");
                for(i=0;i<c;i++)
                {
                    cnt=cnt+v[c-1-i];
                }
            }
            else
            {
                //printf("s\n");
                for(i=0;i<p[j];i++)
                {
                    //printf("%d\n",v[c-1-i]);
                    cnt=cnt+v[c-1-i];
                }
            }
            //printf("%d\n",cnt);
            //printf("%d\n",p[j]);
        }
        printf("%d\n",cnt);
    }
}
