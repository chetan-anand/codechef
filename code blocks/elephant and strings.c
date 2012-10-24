#include<stdio.h>
#include<string.h>
int main()
{
    int k,n,i,j,l,m,p,q;
    char ss[51][51],s[51];
    scanf("%d %d",&k,&n);
    for(i=0;i<k;i++)
    {
        if(i==0){getchar();}
        gets(ss[i]);
    }
    for(i=0;i<n;i++)
    {
        p=0;
        gets(s);
        l=strlen(s);
        if(l>=47){printf("Good\n");}
        else{
            for(j=0;j<l;j++)
            {
                for(m=0;m<k;m++)
                {
                    q=strlen(ss[m]);
                    if(strncmp(ss[m],s+j,q)==0){p++;break;}
                }
                if(p!=0){break;}
            }

        if(p!=0){printf("Good\n");}
        else{printf("Bad\n");}
        }
    }
    return 0;
}
