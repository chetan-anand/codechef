#include<stdio.h>
#include<string.h>
int stringExist( char *string, char *sub )
{
  int count = 0;

  while( *string )
  {
    char *a = string, *b = sub;
    while( *a && *a == *b ) {a++;b++;}
    count += !*b;
    ++string;
  }

  return count;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s1
        scanf(:)
    }
    return 0;
}
