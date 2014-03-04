#include<stdio.h>
int FindMaxSum(int arr[], int n)
{
  int incl = arr[0];
  int excl = 0;
  int excl_new;
  int i;

  for (i = 1; i < n; i++)
  {
     /* current max excluding i */
     excl_new = (incl > excl)? incl: excl;

     /* current max including i */
     incl = excl + arr[i];
     excl = excl_new;
  }

   /* return max of incl and excl */
   return ((incl > excl)? incl : excl);
}

/* Driver program to test above function */
int main()
{
  int arr[] = {1, - 1, 3, 8 ,4 } ;
  printf("%d \n", FindMaxSum(arr, 5));
  getchar();
  return 0;
}
