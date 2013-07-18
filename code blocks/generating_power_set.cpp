///Advanced Bits Operation

/// Here we are generating power sets of a set.

#include<stdio.h>
int main()
{
    int a[]={1,2,3,4,5};  ///given set
    int n=5,i,j;              /// no of element in set
    int total=1<<n;

    for(i=0;i<total;i++)
    {
        for(j=0;j<n;j++)
        {
            if((i>>j)&1){printf("%d ",a[j]);}
        }
        printf("\n");
    }
    return 0;
}
