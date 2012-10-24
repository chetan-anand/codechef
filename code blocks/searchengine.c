#include<stdio.h>
#include<string.h>
int main()
{
    char ch[30002][31],qch[31];
    int n,q,i,j,k,c,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("a\n");
        if(i==0){getchar();}
        gets(ch[i]);
        puts(ch[i]);
        printf("b\n");
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        c=0;l=0;
        printf("a\n");
        if(i==0){getchar();}
        gets(qch);
        puts(qch);
        printf("b\n");
        for(j=0;j<n;j++)
        {
            for(k=0;;k++)
            {
                c++;
                if(qch[k]!=ch[j][k]){break;}
                if(qch[k]=='\0'||ch[j][k]=='\0'){l++;break;}
            }
            if(l!=0){break;}
        }
        printf("%d\n",c);
    }
    return 0;
}
