#include<stdio.h>
#include<stdlib.h>
void insertion(int *a,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        for(j=i;;j--)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
            else{break;}
        }
    }
}
int main()
{
    clock_t start, end;
    int i,n,a[100001];
    //scanf("%d",&n);
    n=100000;
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    insertion(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
