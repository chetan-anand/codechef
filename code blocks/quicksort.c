#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quicksort(int *a,int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
int partition (int *a,int p,int r)
{
    int x,i,j,temp;
    x=a[r];
    i=p-1;
    for(j=p;j<=r;j++)
    {
        if(a[j]<=x)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    //printf("%d\n",i);
    /*temp=a[i];
    a[i]=a[r];
    a[r]=temp;*/
    return i;
}


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

void tquick(int *a,int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(a,p,r);
        quicksort(a,p,q-1);
        p=q+1;
    }
}
int main()
{
    //int a[8]={8,7,6,5,4,3,2,1},i;
    int i,n,a[100001];clock_t start, end;
    printf("enter tho no of integers=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }

    start = clock();
    quicksort(a,0,n-1);             //quick sort
    insertion(a,n);                 //insertion sort
   tquick(a,0,n-1);              //tail recursion quick sort
    double runTime;
    end = clock();

  runTime = ((end - start) / (double) CLOCKS_PER_SEC );
  printf ("Run time is %g seconds\n", runTime);
  /*for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }*/
  return 0;
}
