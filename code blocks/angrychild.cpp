#include<stdio.h>
#include<algorithm>
long long int a[100010];

using namespace std;

long long int dpartition(long long int p,long long int r)
	{
		long long int pivot,temp,i,j;
		pivot=a[r];	//choosing the last element as pivot always.
		i=p-1;
		for(j=p;j<=r;j++)
		{
			if(a[j]<=pivot)
			{
				i++;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		/*temp=a[i+1];
		a[i+1]=a[r];
		a[r]=temp;*/

		return i;
	}

	void dquicksort(long long int p,long long int r)//Deterministic quicksort without tail recusion
	{
		long long int q;
		if(p<r)
		{
			q=dpartition(p,r);
			dquicksort(p,q-1);
			dquicksort(q+1,r);
		}
	}
int main()
{

    long long int n,k,i,j,t,temp,cnt,cnt1;
    scanf("%lld",&n);
    scanf("%lld",&k);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    dquicksort(0,n-1);
    long long int minv,minv1;
    for(i=0;i<=n-1-k;i++)
    {
        if(i==0){minv=a[i+k-1]-a[i];continue;}
        if(a[i+k-1]-a[i]<minv){minv=a[i+k-1]-a[i];}
    }
    //printf("minv=%d\n",minv);
    j=0;
    for(i=0;i<=n-1-k;i++)
    {
        if(a[i+k-1]-a[i]==minv)
        {
            temp=i;
            cnt=0;cnt1=0;
            for(i=temp+1,j=1;i<=temp+k-1;i++,j++)
            {
                cnt=cnt+a[i-1];
                //printf("cnt=%lld\n",cnt);
                cnt1=cnt1+(a[i]*j-cnt);
                // printf("cnt1=%lld\n",cnt1);
            }
            if(j==0){minv1=cnt1;j=1;}
            if(cnt1<minv1){cnt1=minv1;}

        }
    }
    printf("%lld\n",minv1);

    //if(k==1){printf("%lld\n",a[temp]);return 0;}
    /*for(i=temp+1,j=1;i<=temp+k-1;i++,j++)
    {
        cnt=cnt+a[i-1];
       //printf("cnt=%lld\n",cnt);
        cnt1=cnt1+(a[i]*j-cnt);
       // printf("cnt1=%lld\n",cnt1);
    }*/



    return 0;
}
