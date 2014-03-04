// Program to show segment tree operations like construction, query and update
#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;
long long int arr[1000110];
// A utility function to get the middle index from corner indexes.
long long int getMid(long long int s, long long int e) {  return s + (e -s)/2;  }

/*  A recursive function to get the sum of values in given range of the array.
    The following are parameters for this function.

    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
long long int getSumUtil(long long int *st, long long int ss, long long int se, long long int qs, long long int qe, long long int index)
{
    // If segment of this node is a part of given range, then return the
    // sum of the segment
    if (qs <= ss && qe >= se)
        return st[index];

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;

    // If a part of this segment overlaps with the given range
    long long int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}

/* A recursive function to update the nodes which have the given index in
   their range. The following are parameters
    st, index, ss and se are same as getSumUtil()
    i    --> index of the element to be updated. This index is in input array.
   diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(long long int *st, long long int ss, long long int se, long long int i, long long int diff, long long int index)
{
    // Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;

    // If the input index is in range of this node, then update the value
    // of the node and its children
    st[index] = st[index] + diff;
    if (se != ss)
    {
        long long int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}

// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(long long int arr[], long long int *st, long long int n, long long int i, long long int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }

    // Get the difference between new value and old value
    long long int diff = new_val - arr[i];

    // Update the value in array
    arr[i] = new_val;

    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

// Return sum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses getSumUtil()
long long int getSum(long long int *st, long long int n, long long int qs, long long int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
long long int constructSTUtil(long long int arr[], long long int ss, long long int se, long long int *st, long long int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    long long int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
long long int *constructST(long long int arr[], long long int n)
{
    // Allocate memory for segment tree
    long long int x = (long long int)(ceil(log2(n))); //Height of segment tree
    long long int max_size = 2*(long long int)pow(2, x) - 1; //Maximum size of segment tree
    long long int *st = new long long int[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);

    // Return the constructed segment tree
    return st;
}

// Driver program to test above functions
int main()
{
    long long int i,j,k,t,q,a,b,n;
    char ch;
    scanf("%lld %lld",&n,&q);
    for(i=0;i<n;i++){scanf("%lld",&arr[i]);}
    // Build segment tree from given array
    long long int *st = constructST(arr, n);

    for(i=0;i<q;i++)
    {
        //scanf("%c %d %d",&ch,&a,&b);
        cin>>ch>>a>>b;
        //printf("%c %d %d\n",ch,a,b);
        if(ch=='S')
        {
            printf("%lld\n",getSum(st,n,a,b));
            continue;
        }
        else if(ch=='G')
        {
            updateValue(arr,st,n,a,arr[a]+b);
            continue;
        }
        else if(ch=='T')
        {
            updateValue(arr,st,n,a,arr[a]-b);
            continue;
        }
    }
    return 0;
}
