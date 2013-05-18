#include<stdio.h>
#include<string.h>


void index()
{
    char a[20],ch;
    int i,now,nol;
    FILE *ptr=fopen("text.txt","r");

    for(i=0;ch!=EOF;i++)
    {
        fscanf(ptr,"%s",a);

        puts(a);
        ch=fgetc(ptr);
        if(ch=='\n'){nol++;}
    }
    now=i;
}


int hashfunc(char *a,int size)
{
    int i,count=7,ascii;
    for(i=0;i<size;i++)
    {
        ascii=a[i];
        count=count*13+a[i];
    }
}

int main()
{
    index();
    return 0;
}
