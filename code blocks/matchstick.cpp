#include <stdio.h>
#include <math.h>
#include <limits.h>
// A utility function to get minimum of two numbers
int minVal(int x, int y) { return (x < y)? x: y; }
int maxVal(int x, int y) { return (x > y)? x: y; }
// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }

/*  A recursive function to get the minimum value in a given range of array
    indexes. The following are parameters for this function.

    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */


int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return the
    // min of the segment
    if (qs <= ss && qe >= se)
        return st[index];

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return INT_MAX;

    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

int RMQUtilx(int *stx, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return the
    // min of the segment
    if (qs <= ss && qe >= se)
        return stx[index];

    // If segment of this node is outside the given range
    /*if (se < qs || ss > qe)
        return INT_MAX;*/

    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return maxVal(RMQUtil(stx, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(stx, mid+1, se, qs, qe, 2*index+2));
}


// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQ(int *st, int n, int qs, int qe)
{
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

int RMQx(int *stx, int n, int qs, int qe)
{
    return RMQUtilx(stx, 0, n-1, qs, qe, 0);
}
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

int constructSTUtilx(int arr[], int ss, int se, int *stx, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        stx[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = getMid(ss, se);
    stx[si] =  maxVal(constructSTUtilx(arr, ss, mid, stx, si*2+1),
                     constructSTUtilx(arr, mid+1, se, stx, si*2+2));
    return stx[si];
}

/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);

    // Return the constructed segment tree
    return st;
}

int *constructSTx(int arr[], int n)
{
    // Allocate memory for segment tree
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *stx = new int[max_size];

    // Fill the allocated memory st
    constructSTUtilx(arr, 0, n-1, stx, 0);

    // Return the constructed segment tree
    return stx;
}

// Driver program to test above functions
int main()
{
    int arr[] = {1, 3, 2, 7, 9, 11, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("n=%d\n",n);
    //Build segment tree from given array
    int *st = constructST(arr, n);
    int *stx= constructSTx(arr, n);
    int qs = 0;  // Starting index of query range
    int qe = 6;
    while (1)
    {
        scanf("%d %d",&qs,&qe);
        printf("Minimum of values in range [%d, %d] is = %d\n",qs, qe, RMQ(st, n, qs, qe));
        printf("Maximum of values in range [%d, %d] is = %d\n",qs, qe, RMQx(stx, n, qs, qe));
    }
     // Ending index of query range

    // Print minimum value in arr[qs..qe]


    return 0;
}

