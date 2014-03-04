#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iostream>

#define max(a,b) a>b?a:b

using namespace std;


int main()
{
    int t,i,j,k;
    char fs[30],cf[300000];
    int cnt[300],nod;
    char h[300];
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        nod=0;
        cin>>fs>>cf;
        //puts(fs);
        //puts(cf);
        for(i=0;cf!='\0';i++)
        {
            cnt[cf[i]]++;
        }

        for(i=0;i<300;i++)
        {
            if(cnt[i]>0){nod++;}
        }

        for(i=0,j=nod;i<300;i++)
        {
            if(cnt[i]>0)
            {
               h[i]=fs[26-j];
               j--;
            }
        }

        for(i=0;cf[i]!='\0';i++)
        {
            printf("%c",h[cf[i]]);
        }

        printf("\n");
    }

	return 0;
}

