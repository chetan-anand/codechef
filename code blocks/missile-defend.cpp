#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void mergesort(long long int a[],int,int);
void merge(long long int a[],int,int,int);

int main()
{
  long long int *a;
  long long int i,n,k,diff,min=1000000000000000002,j,diff1,diff2,l;

  //cout<<"enter no of elements: ";
  cin>>n>>k;

  a = new long long int[n];
  for(i = 0;i<n;i++)
		 cin>>a[i];

  mergesort(a,0,n-1);

  //for(int i = 0;i < n;i++)
     //cout<<a[i]<<endl;
  /*for(i = 0;i<(n-k+1);i++)
    {
		diff = a[i+k-1] - a[i];
		if(min > diff)
		{
			min = diff;
			diff1 = i+k-1;
			diff2 = i;
		}
    }
    diff = 0;
    j = diff1-diff2;
    if(n > 1)
    {
	 for(i = diff1; i >= diff2 ; i--)
	 {

			diff += (a[i]*j -a[i]*(diff1 - diff2 - j) );
            	        j--;
			//cout<<diff<<endl;
	 }
    }*/

  if(n!=k)
  {
     for(i = 0 ;i < n - k;i++)
     {
       diff = 0;
       l = 0;
       for(j = i;j < i + k;j++)
       {
           diff += (a[j] * l - a[j] *(k-l-1));
           if(min < diff)
               break;
           l++;
       }
       if(j == i + k && diff > 0)
           min = diff;
       //cout<<"after: "<<min<<endl;
     }
   }
   else
   {
        if(k == 1)
            min = a[0];
        else
        {
            diff = 0;
            for(i = n - 1; i >= 0; i--)
            {
                diff+=a[i]*i - a[i]*(n-i-1);
            }
            min = diff;
        }

    }
    cout<<min<<endl;
    delete[] a;
    return 0;
}

void mergesort(long long int a[],int start,int end)
{
	int mid;
	if(start<end)
	{
		mid = (start + end)/2;
		// cout<<"\nmid: "<<mid<<"\n";
		mergesort(a,start,mid);
		mergesort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}

void merge(long long int a[],int start,int mid,int end)
{
	long long int *left,*right;
	int n1,n2;
	n1 = mid - start + 1;
	n2 = end - mid;
	left = new long long int[n1 + 1];
	right = new long long int[n2 + 1];
	int i=0;
	int j=0;
	for(;i<n1;i++)
		left[i] = a[start + i];
	for(;j<n2;j++)
		right[j] = a[mid + j +1];
	left[i] = 1000000000;
	right[j] = 1000000000;
	int k=0,l=0;
	for(i = start;i<=end;i++)
	{
		if(left[k]<=right[l])
		{
			a[i] = left[k];
			k++;
		}
		else
		{
			a[i] = right[l];
			l++;
		}
	}
	delete[] left;
	delete[] right;
}
