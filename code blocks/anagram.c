#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,k,d,e,flag,flag1,len1,len2;
    char a[30],b[30];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        d=e=flag1=0;
        scanf("%s %s",a,b);
        for(j=0;a[j]!='\0';j++)
        {
            d=d+a[j];
        }
        for(j=0;b[j]!='\0';j++)
        {
            e=e+b[j];
        }
        for(j=0;b[j]!='\0';j++)
        {
            flag=0;
            for(k=0;a[k]!='\0';k++)
            {
                if(b[j]==a[k]){a[k]='-';flag=1;break;}
            }
            if(flag==0){flag1=1;break;}
        }
        len1=strlen(a);len2=strlen(b);
        if(d==e && flag1==0 && len1==len2){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}
