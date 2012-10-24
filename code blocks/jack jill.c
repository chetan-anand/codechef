#include<stdio.h>
void quicksort(int x[],int first,int last);
int main()
{
    int n,k,i,cnt,temp,a[100002],temp1,temp2;
    scanf("%d",&n);
    scanf("%d",&k);
    cnt=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);

        if(temp==-1)
        {
            if(temp2==1){printf("%d\n",temp1);continue;}
            temp2=1;

            if(temp>=temp1){printf("%d\n",temp1);continue;}
            quicksort(a,0,cnt-1);
            temp1=a[k-1];
            printf("%d\n",a[k-1]);
        }
        else
        {
            temp2=0;
            a[cnt]=temp;
            cnt++;
        }
    }
    return 0;
}
void quicksort(int x[100002],int first,int last)
{
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}
