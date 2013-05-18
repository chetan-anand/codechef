#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,j,k,pt[10004],max,maxcf,maxco;
    char ch,co[10000][14],cf[100002][14],temp[14];
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        //printf("jahbsd\n");
        scanf("%s %s",cf[i],co[i]);
        /*puts(cf[i]);
        puts(co[i]);*/
        pt[i]=0;
    }
    max=0;
    for(i=0;i<m;i++)
    {
        scanf("%s",temp);
        for(j=0;j<n;j++)
        {
            if(strcmp(temp,cf[j])==0)
            {
                pt[j]++;
                if(pt[j]>max){max=pt[j];}
            }
        }
    }
    /*for(i=0;i<n;i++)
    {
        printf("%d\n",pt[i]);
    }
    printf("%d\n",max);*/
    maxcf=0;
    maxco=0;
    for(i=0;i<n;i++)
    {
        if(pt[i]==max)
        {

        }
    }
    return 0;
}
