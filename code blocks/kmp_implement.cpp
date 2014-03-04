#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int pref[700000];
long long int cnt;
char p[700000];
char t[700000];
char temp[700000];
void prefix(char *p)
{
    int m=strlen(p);
    p--;
    int k=0; /// initialising total no of character matched
    pref[1]=0;
    for(int i=2;i<=m;i++)
    {
        while(k>0 && p[k+1]!=p[i])
        {
            k=pref[k];
        }
        if(p[k+1]==p[i]){k++;}
        pref[i]=k;
    }
}

void patternmatch(char *p,char *t)
{
    cnt=0;
    prefix(p);
    int m=strlen(p);
    int n=strlen(t);
    p--;
    t--;
    int q=0;
    for(int i=1;i<=n;i++)
    {
        while(q>0 && p[q+1]!=t[i])
        {
            q=pref[q];
        }
        if(p[q+1]==t[i]){q++;}
        if(q==m)
            {
                cnt++;
        //printf("The pattern is found at %d\n",i-1);q=pref[q];
        }
    }
    printf("%lld\n",cnt);

}

int main()
{
    int i,j,k,n,tc;
    scanf("%d",&tc);

    /*char *p="na";
    char *t="banananobano";*/
    while(tc--)
    {
        scanf("%d %d",&n,&k);
        t[0]='\0';
        for(i=1;i<=n;i++)
        {
            itoa(i,temp,10);
            strcat(t,temp);
            temp[0]='\0';
        }
        itoa(k,p,10);
        //puts(t);
        //puts(p);
        patternmatch(p,t);
    }


   // pref=(malloc(strlen(p)*sizeof(int)));

    //prefix(p);
    /*for(i=1;i<=strlen(p);i++)
    {
        printf("%d\n",pref[i]);
    }*/


    return 0;
}




