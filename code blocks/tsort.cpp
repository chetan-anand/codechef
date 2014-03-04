#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int a[1000004];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%d",&a[i]);}
    sort(a,a+n);
    for(i=0;i<n;i++){printf("%d\n",a[i]);}
	return 0;
}
