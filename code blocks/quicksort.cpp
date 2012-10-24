#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int a[1000000];

class quick
{
    public:
    void quicksort(int *a,int left,int right)
    {
        int pivot,j,temp,i;

        if(left<right){
            pivot=left;
            i=left;
            j=right;

            while(i<j){
                while(a[i]<=a[pivot]&&i<right)
                    i++;
                while(a[j]>a[pivot])
                    j--;
                if(i<j){
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }

            temp=a[pivot];
            a[pivot]=a[j];
            a[j]=temp;
            quicksort(a,left,j-1);
            quicksort(a,j+1,right);
        }
    }
};


int main()
{
  int n,i;
  printf("Enter the no of random integer to be sort=");
  scanf("%d",&n);
  //printf("--------the random no are----------\n");
  clock_t start,end;
  start=clock();
  for(i=0;i<n;i++)
  {
      a[i]=rand();
   //   printf("%d\n",a[i]);
  }
  quick object;
  object.quicksort(a,0,n-1);
  printf("----------The soreted random no are:--------------\n");
  for(i=0;i<n;i++)
   {
       printf("%d\n",a[i]);
   }
   end=clock();
    cout<<double(end-start)/(double)CLOCKS_PER_SEC<<"sec is the running time of programme"<<endl;
  return 0;
}

