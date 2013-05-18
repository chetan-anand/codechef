#include<stdio.h>
#include<string.h>
#define MAXN 100000
#define MAXIND 300000

 void buildmin(int node, int b, int e, int M[MAXIND], int A[MAXN], int N)
  {
      if (b == e)
          M[node] = b;
      else
       {
  //compute the values in the left and right subtrees
          buildmin(2 * node, b, (b + e) / 2, M, A, N);
          buildmin(2 * node + 1, (b + e) / 2 + 1, e, M, A, N);
  //search for the minimum value in the first and
  //second half of the interval
          if (A[M[2 * node]] <= A[M[2 * node + 1]])
              M[node] = M[2 * node];
          else
              M[node] = M[2 * node + 1];
      }
  }

  void buildmax(int node, int b, int e, int Mx[MAXIND], int A[MAXN], int N)
  {
      if (b == e)
          Mx[node] = b;
      else
       {
  //compute the values in the left and right subtrees
          buildmax(2 * node, b, (b + e) / 2, Mx, A, N);
          buildmax(2 * node + 1, (b + e) / 2 + 1, e, Mx, A, N);
  //search for the minimum value in the first and
  //second half of the interval
          if (A[Mx[2 * node]] >= A[Mx[2 * node + 1]])
              Mx[node] = Mx[2 * node];
          else
              Mx[node] = Mx[2 * node + 1];
      }
  }


  int querymin(int node, int b, int e, int M[MAXIND], int A[MAXN], int i, int j)
  {
      int p1, p2;


  //if the current interval doesn't intersect
  //the query interval return -1
      if (i > e || j < b)
          return -1;

  //if the current interval is included in
  //the query interval return M[node]
      if (b >= i && e <= j)
          return M[node];

  //compute the minimum position in the
  //left and right part of the interval
      p1 = querymin(2 * node, b, (b + e) / 2, M, A, i, j);
      p2 = querymin(2 * node + 1, (b + e) / 2 + 1, e, M, A, i, j);

  //return the position where the overall
  //minimum is
      if (p1 == -1)
          return M[node] = p2;
      if (p2 == -1)
          return M[node] = p1;
      if (A[p1] <= A[p2])
          return M[node] = p1;
      return M[node] = p2;

  }

  int querymax(int node, int b, int e, int Mx[MAXIND], int A[MAXN], int i, int j)
  {
      int p1, p2;


  //if the current interval doesn't intersect
  //the query interval return -1
      if (i > e || j < b)
          return -1;

  //if the current interval is included in
  //the query interval return M[node]
      if (b >= i && e <= j)
          return Mx[node];

  //compute the minimum position in the
  //left and right part of the interval
      p1 = querymax(2 * node, b, (b + e) / 2, Mx, A, i, j);
      p2 = querymax(2 * node + 1, (b + e) / 2 + 1, e, Mx, A, i, j);

  //return the position where the overall
  //minimum is
      if (p1 == -1)
          return Mx[node] = p2;
      if (p2 == -1)
          return Mx[node] = p1;
      if (A[p1] <= A[p2])
          return Mx[node] = p1;
      return Mx[node] = p2;

  }

int main()
{
    int arr[MAXN]={3, 4, 2, 1, 5, 7, 9, 7, 10, 5, 12, 3, 1, 1, 2, 1, 3, 2};
    int st[MAXIND];
    int stx[MAXIND];
    buildmin(1,0,17,st,arr,18);
    //fflush(stdout);
    printf("min=%d\n",querymin(1,0,17,st,arr,0,17));
    buildmax(1,0,17,stx,arr,18);
    printf("max=%d\n",querymax(1,0,17,stx,arr,0,17));
    return 0;
}
