#include<stdio.h>
int main()
{
    int a[8]={10,9,8,7,6,5,4,3};
    int i,j,k,b,c,temp1,temp2;
    for(i=0;i<8;i+=2)
    {
        if(a[i+1]<a[i]){b=a[i];a[i]=a[i+1];a[i+1]=b;}
    }
    for(i=0;i<8;i++)
    {
        printf("%d ",a[i]);
    }
    //now merging process starts
    for(i=0;i<8;i)

    return 0;
}
