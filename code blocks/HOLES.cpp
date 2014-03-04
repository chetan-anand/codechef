#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include <stdint.h>
#include <unistd.h>
#define max(a,b) a>b?a:b

using namespace std;

int main()
{
    int t,i,j,k;
    char ch[104];
    scanf("%d",&t);
    if(t>40){return 0;}
    while(t--)
    {
        scanf("%s",ch);
        int cnt=0;
        for(i=0;ch[i]!='\0';i++)
        {
            if(ch[i]=='A' || ch[i]=='D'|| ch[i]=='O'|| ch[i]=='P'|| ch[i]=='R'||ch[i]=='Q')
            {
                cnt++;
            }
            if(ch[i]=='B'){cnt+=2;}
        }
        printf("%d\n",cnt);
    }
	return 0;
}

