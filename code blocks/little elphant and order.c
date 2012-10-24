#include<stdio.h>
#include<string.h>
int main()
{
    char a[20002],ch,b[20002],c7,c4,c74,n4,n7;
    int t,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        c7=c4=c74=n4=n7=0;
        printf("a\n");
        scanf("%s",a);
        printf("b\n");
        scanf("%s",b);
        printf("c\n");
        //puts(a);
        //puts(b);
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='4'){n4++;}
            if(a[i]=='7'){n7++;}
        }

        printf("n4=%d  n7=%d ",n4,n7);

        for(i=0;a[i]!='\0';i++)
        {
            if(b[i]<'4'){c4++;}
            if(b[i]<'7'){c7++;}
            if(b[i]=='4'){c74++;}
        }

        printf("c4=%d  c7=%d  c74=%d ",c4,c7,c74);

        c4=c7=c74=n4=n7=0;

        for(i=0;b[i]!='\0';i++)
        {
            if(b[i]=='4'){n4++;}
            if(b[i]=='7'){n7++;}
        }

        printf("n4=%d  n7=%d ",n4,n7);

        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]<'4'){c4++;}
            if(a[i]<'7'){c7++;}
            if(a[i]=='4'){c74++;}
        }
        printf("c4=%d  c7=%d  c74=%d ",c4,c7,c74);


    }
    return 0;
}
