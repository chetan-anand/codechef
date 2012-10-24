#include<stdio.h>
int main()
{
    int r,c,g[200][200],i,j,k,b,s,a[100],flag;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    /*for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }*/
    for(i=0;i<r;i++)
    {
        s=g[i][0];
        for(j=1;j<c;j++)
        {
            if(s>=g[i][j]){s=g[i][j];}
        }
        for(j=0,k=0;j<c;j++)
        {
            if(s==g[i][j]){a[k]=j;k++;}
        }
        for(j=0;j<k;j++)
        {
            flag=0;
            for(b=0;b<r;b++)
            {
                if(s<g[b][a[j]]){flag=1;break;}
            }
            if(flag==0){break;}
        }
        if(flag==0){printf("%d\n",s);break;}
    }
    if(flag==1){printf("GUESS\n");}
    return 0;
}
