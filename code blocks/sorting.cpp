#include<stdio.h>
#include<stdlib.h>
int a[1000],cnt;

class Sorting
{
	public:
	int i,j,k;
	int heap_size;
		int t,n;

	void input()
	{
		int n=0;cnt=0;
		FILE *ptr=fopen("input.txt","r");
		while(fscanf(ptr,"%d",&n)!=EOF)
		{
			a[cnt]=n;
			cnt++;
		}
		fclose(ptr);
	}

	void output()
	{
		FILE *ptr=fopen("output.txt","w");
		fprintf(ptr,"Sorted array is:\n");
		for(i=0;i<cnt;i++)
		{
			fprintf(ptr,"%d\n",a[i]);
		}
		fclose(ptr);
	}

	void display()
	{
		for(i=0;i<cnt;i++)
		{
			printf("%d\n",a[i]);
		}
	}

	/*int digit()  finding the no of digits of maximum number in input
	{
		int max=a[0],temp=1;
		for(i=1;i<cnt;i++)
		{
			if(a[i]>max){max=a[i];}
		}
		for(i=0;;i++)
		{
			temp=temp*10;
			if((max/temp)==0){return i+1;}
		}
	}*/
///////////////////////////////////////////////////////////////////
///////////////     Radix Sort    /////////////////////////////////
	void radixsort(int n)
	{
 	 	int i, b[10], max=a[0],temp=1;
 	 	for (i = 0; i < n; i++)
 		{
   			if (a[i] > max)
    	 	max= a[i];
  		}

 		while (max/temp>0)		//  sort part of radix sort
 		{
   	 		int bucket[10] ={0};
  	 		for (i = 0; i < n; i++)
     		 	bucket[a[i] / temp % 10]++;
 	   		for (i = 1; i < 10; i++)
   	   			bucket[i] += bucket[i - 1];
   	 		for (i = n - 1; i >= 0; i--)
     		 	b[--bucket[a[i]/temp % 10]] = a[i];
   			for (i = 0; i < n; i++)
    			a[i]=b[i];
    		temp=temp*10;
  		}
	}
//////////////////////////////////////////////////////////////////////////////////
////////////////////mergesort//////////////////////////////////////














///////////////////////////////////////////////////////////////////////////////////
/////////////////////////counting sort/////////////////////////////////////
/*void countingsort()
{
    int c[1000]={0};
    int b
    /*for i=0 to i=k
    c[i]=0;
    for j=1 to A.length
    c[A[j]]=C[A[j]]+1;

    NOW c[i] contains the no of elements =i

    for i=1 to k
    c[i]=c[i]+c[i-1];

    c[i] now contains the number of elements less than or equal to i
    for j= a.length downto 1
    b[c[a[j]]]=a[j]
    c[a[j]]=c[a[j]]-1*/

}



//////////////////////////////////////////////////////////////////
////////////////////////  Insertion Sort /////////////////////////
	/*void insertsort()
	{
		int temp;
		for(i=1;i<cnt;i++)
		{
			for(j=i;j>=0;j--)
			{
				if(a[j]<a[j-1])
				{
					temp=a[j];
					a[j]=a[j-1];
					a[j-1]=temp;
				}
				else{break;}
			}
		}
	}*/

/////////////////////////////////////////////////////////////////////
////////        Different Partition functions         ///////////////
	int dpartition(int p,int r)
	{
		int pivot,temp;
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

	int rpartition(int p,int r)
	{
		int pivot,temp;
		temp=(rand())%cnt;
		pivot=a[temp];	//choosing the last element as pivot always.
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

		return i;
	}
///////////////////////////////////////////////////////////////////
//////////////  Different Quicsort Functions  /////////////////////

	void dquicksort(int p,int r)//Deterministic quicksort without tail recusion
	{
		int q;
		if(p<r)
		{
			q=dpartition(p,r);
			dquicksort(p,q-1);
			dquicksort(q+1,r);
		}
	}
////////////////////////////////////////////////////////////////////
	void rquicksort(int p,int r)//Randomized quicksort without tail recusion
	{
		int q;
		if(p<r)
		{
			q=rpartition(p,r);
			rquicksort(p,q-1);
			rquicksort(q+1,r);
		}
	}
//////////////////////////////////////////////////////////////////
	void tailquicksort(int p,int r) //deterministic quicksort with tail recursion
	{
		int q;
		while(p<r)
		{
			q=dpartition(p,r);
			if((q-p)<(r-q))
			{
				tailquicksort(p,q-1);
				p=q+1;
			}
			if((q-p)>(r-q))
			{
				tailquicksort(q+1,r);
				r=q-1;
			}
		}
	}
//////////////////////////////////////////////////////////////////
	void rtquicksort(int p,int r) //randomized quicksort with tail recursion
	{
		int q;
		while(p<r)
		{
			q=rpartition(p,r);
			if((q-p)<(r-q))
			{
				rtquicksort(p,q-1);
				p=q+1;
			}
			if((q-p)>(r-q))
			{
				rtquicksort(q+1,r);
				r=q-1;
			}
		}
	}

//////////////////////////////////////////////////////////////////////
//////////////////////// heap sort ///////////////////////////////////


void build_heap(int* a)
{
        int i;
//        printf("in build_heap\n");
        for(i=heap_size/2;i>0;i--)
                max_heapify(a,i);
}

void max_heapify(int* a,int i)
{
        int l,r,t,large;
//        printf("in max_heapify\n");
        l=left(a,i);
        if(l==0)
                return;
        r=right(a,i);
        if((l<=heap_size)&&(a[i]<a[l]))
                large=l;
        else
                large=i;
        if(r!=0)
        {
                if((r<=heap_size)&&(a[large]<a[r]))
                        large=r;
        }
        if(large!=i)
        {
                t=a[large];
                a[large]=a[i];
                a[i]=t;
                max_heapify(a,large);
        }
}

	int left(int* a,int i)
	{
//        printf("in left\n");
        if(2*i<=heap_size)
                return (2*i);
        else
                return (0);
	}

	int right(int* a,int i)
	{
	//        printf("in right\n");
        if((2*i)+1<=heap_size)
                return (2*i+1);
        else
                return (0);
	}


	void HeapSort()
	{
		int t;
		build_heap(a);
		while (heap_size >= 2)
		{
          	      t=a[1];
          	      a[1]=a[heap_size];
          	     a[heap_size]=t;
				heap_size =heap_size-1;
     	          max_heapify(a,1);
		}
	}
//////////////////////////////////////////////////////////////////////
///////////////////////// Bubble sort ////////////////////////////////
	void bubblesort()
	{
		int temp;
		for(i=0;i<=cnt/2;i++)
		{
			for(j=0;j<cnt-1;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}

////////////////////////////////////////////////////////////////////////////


};


int main()
{
	int d;

	Sorting o1;   //making object

	o1.input();	  //reading from the input text file

	printf("the unsorted array obtained from file is\n");

	o1.display();	//displaying to the terminal

	//here we put different sorintg algorithms
	//////////////////////////////////////////////
	//o1.radixsort(cnt);
	//o1.insertsort();
	o1.dquicksort(0,cnt-1);
	//o1.bubblesort();
	//o1.rquicksort(0,cnt-1);
	//o1.HeapSort();
	//o1.tailquicksort(0,cnt-1);
	//o1.rtquicksort(0,cnt-1);


	//////////////////////////////////////////////
	printf("\nthe sorted array is\n");
	o1.display();   //displaying the sorted aay to the terminal

	o1.output();	//wrinting the sorted aay to the ouput textfile



	return 0;
}

