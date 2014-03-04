#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int pref[100];
void prefixfunc(char *s)
{
    int m=strlen(s);
    s=s--;
    printf("%s\n",s+1);
    pref[1]=0;
    int k=0;
    for(int i=2;i<=m;i++)
    {
        while(k>0 && s[k+1]!=s[i])
        {
            k=pref[k];
        }
        if(s[k+1]==s[i]){k++;}
        pref[i]=k;
    }
}
int overlap[100];

/*void computeOverlap(char *pattern)
{
	overlap[0] = -1;
	for(int i=0; pattern[i]; i++)
	{
		overlap[i+1] = overlap[i] + 1;
		while(overlap[i+1] > 0 && pattern[i] != pattern[overlap[i+1]-1])
			overlap[i+1] = overlap[overlap[i+1]-1] + 1;
	}
}*/

/*bool petternmatching(char* p, char* t)
{
    n=strlen(t);m=strlen(p);
    p=p-1;t=t-1;
    int q=0;
    int *pref=prefixfunc(p);
    for(int i=1;i<=n;i++)
    {
        while(q>0 && p[q+1]!=p[i])
            q=pref[q];
        if(p[q+1]==p[i]){q++;}
        if(q==m){printf("pattern found at %d\n",i);return true;}
    }
    printf("No pattern found\n");
    retunr false;
}*/
int main()
{

    char *p="ababaca";
    printf("%s\n",p);
    //computeOverlap(p);
    prefixfunc(p);
    for(int i=1;i<=strlen(p);i++)
    {
        printf("%d\n",pref[i]);
    }
    return 0;
}
