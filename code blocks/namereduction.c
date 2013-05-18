#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,t,n,flag[150];
    char a[200000],b[200000],temp[200000],ch,c[200000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",a,b);
        scanf("%d",&n);
        j=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",temp);
            if(i==0){strcpy(c,temp);}
            else{strcat(c,temp);}
        }
        //puts(c);
        strcat(a,b);
        //puts(a);
        for(i=95;i<129;i++){flag[i]=0;}
        for(i=0;a[i]!='\0';i++)
        {
            flag[a[i]]++;
        }
        for(i=0;c[i]!='\0';i++)
        {
            flag[c[i]]--;
            if(flag[c[i]]<0){printf("NO\n");j=1;break;}
        }
        if(j==0){printf("YES\n");}
    }
    return 0;
}
