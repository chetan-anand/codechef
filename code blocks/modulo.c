#include<stdio.h>
int main()
{
    int a[10],c,flag,counter,i,j,k;
    for(j=0;j<10;j++)
    {
        counter=1;
       for(i=0;i<10;i++)
        {
            scanf("%d",&a[i]);
            a[i]=a[i]%42;
        }
        for(i=1;i<10;i++)
        {
            flag=0;
            c=a[i];
            for(k=i-1;k>=0;k--)
            {
                if(c==a[k]){flag=1;break;}
            }
            if(flag==0){counter++;}
        }
        printf("%d\n",counter);
    }
    return 0;
}
