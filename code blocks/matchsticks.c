#include<stdio.h>
int b[100000009];
int main()
{
    int i,j,k,l,n,q,r,min,max;
    float temp;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&l,&r);
        min=b[l];max=b[l];
        for(i=l+1;i<=r;i++)
        {
            if(b[i]<min){min=b[i];}
            if(b[i]>max){max=b[i];}
        }
        temp=(float)((max-min)/2)+ (float)(min);
        max=0;
        for(i=0;i<=l-1;i++)
        {
            if(b[i]>max){max=b[i];}
        }
        for(i=r+1;i<n;i++)
        {
            if(b[i]>max){max=b[i];}
        }
        if ((float)(max+min)>temp){printf("%.1f\n",(float)(max+min));}
        else{printf("%.1f\n",temp);}
    }
    getchar();
    return 0;
}
