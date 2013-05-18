#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,k,p[5001],n,temp,cnt,r[5002],flag;
    char c1[5001][52],c2[5002][52],ch;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%s %s %d%c",c1[i],c2[i],&p[i],&ch);
            cnt=cnt+p[i];
        }
        /*for(i=0;i<n;i++)
        {
            printf("%s %s\n",c1[i],c2[i]);
        }*/
        //printf("the total is %d\n",cnt);
        k=1;
        while(flag!=1)
        {
            flag=0;
            for(i=0;i<n-1;i++)
            {
                if(strcmp(c1[i],c2[temp])==0){temp=i;r[k]=i;k++;break;}
            }
            if(i=n-2){flag=1;}
        }

       /* while(flag!=1)
        {
            flag=0;
            for(i=0;i<n-1;i++)
            {
                if(strcmp(c1[temp],c2[i])==0){temp=i;r[k]=i;k++;break;}
            }
            if(i=n-2){flag=1;}
        }*/

        for(i=0;i<n-1;i++)
        {
            printf("%d\n",r[i]);
        }
        /*for(i=0;i<n;)
        {
            puts(a)
        }*/
    }
    return 0;
}
