/*
USER: chetan anand
ALGO: range minimum query
*/

#include <cstdio>
using namespace std;

struct Tree { int maxv, sum, lval, rval; };
const int MAX = 1 << 16;
int a[MAX];
Tree T[MAX << 1];

inline int max2(int a, int b) {
	return ((a > b)? a : b);
}

inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}

void init(int Node, int i, int j) {
	if(i==j) {
		T[Node].maxv = T[Node].sum = T[Node].rval = T[Node].lval = a[i];
		return;
	}
	int m = (i+j)/2;
	init(2*Node, i, m);
	init(2*Node+1, m+1, j);
	T[Node].sum = T[Node*2].sum + T[Node*2+1].sum;
	T[Node].maxv = max3(T[2*Node].maxv, T[2*Node].rval + T[2*Node+1].lval, T[2*Node+1].maxv);
	T[Node].lval = max2(T[2*Node].lval, T[2*Node].sum + T[2*Node+1].lval);
	T[Node].rval = max2(T[2*Node].rval + T[2*Node+1].sum, T[2*Node+1].rval);
}

void find(Tree &res, int Node, int L, int R, int i, int j) {
	if(L==i && R==j) {
		res = T[Node];
		return;
	}
	int m = (L + R)/2;
	if(j<=m) find(res, 2*Node, L, m, i, j);
	else if(i>m) find(res, 2*Node+1, m+1, R, i, j);
	else {
		Tree Left, Right;
		find(Left, 2*Node, L, m, i, m);
		find(Right, 2*Node+1, m+1, R, m+1, j);
		res.maxv = max3(Left.maxv, Right.maxv, Left.rval + Right.lval);
		res.sum = Left.sum + Right.sum;
		res.lval = max2(Left.lval, Left.sum + Right.lval);
		res.rval = max2(Left.rval + Right.sum, Right.rval);
	}
}

int main() {
	int n, i, j, m;
	Tree res;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	init(1, 0, n-1);
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d", &i, &j);
		find(res, 1, 0, n-1, --i, --j);
		printf("%d\n", res.maxv);
	}
	return 0;
}




////////////////////////////////////////////////////////////


// Program for range minimum query using segment tree
#include <stdio.h>
#include <math.h>
#include <limits.h>

// A utility function to get minimum of two numbers
int minVal(int x, int y) { return (x < y)? x: y; }

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

// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQ(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0);
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

// Driver program to test above functions
int main()
{
    int arr[70];
    //int arr[] = {1, 3, 2, 7, 9, 11};
    //int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    //int *st = constructST(arr, n);

    //int qs = 1;  // Starting index of query range
    //int qe = 5;  // Ending index of query range

    // Print minimum value in arr[qs..qe]
    /*printf("Minimum of values in range [%d, %d] is = %d\n",
                           qs, qe, RMQ(st, n, qs, qe));*/

    int n,i,j,k,t;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int *st = constructST(arr, n);
    /*int q;
    cin>>q;
    while(q--)
    {
        int in;
        cin>>in;

    }*/



    return 0;
}
