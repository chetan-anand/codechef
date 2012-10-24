#include<stdio.h>
int main()
{
    int n,k,i,j,x[1002],temp,s,p,ptemp;
    scanf("%d",&n);
    scanf("%d",&k);
    s=-1;ptemp=1;
    for(i=0;i<k;i++)
    {
        scanf("%d",&x[i]);
    }

    for(i=0;i<k;i++)
    {
        if(s<x[i]){s=x[i];p=i;}
    }
    printf("s=%d\n",s);
    printf("p=%d\n",p);

    for(i=k;i<n;i++)
    {
        scanf("%d",&temp);
        if(temp==-1)
        {
            printf("ptemp=%d\n",ptemp);
            if(ptemp==0)
            {
                for(j=0;j<k;j++)
                {
                    if(s<x[j]){s=x[j];p=j;}
                }
                printf("j=%d\n",j);
                printf("%d\n",s);
            }
            else{printf("%d\n",s);}
            ptemp=1;
        }
        else
        {
            printf("ptemp=%d\n",ptemp);
            ptemp=0;
            if(temp<s)
            {
                printf("p=%d\n",p);
                x[p]=temp;
                printf("x[p]=%d\n",x[p]);
                s=temp;
                for(j=0;j<k;j++)
                {
                    if(s<x[j]){s=x[j];p=j;}
                }
            }

        }
    }
    return 0;
}

