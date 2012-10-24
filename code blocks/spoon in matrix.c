#include<stdio.h>
main()
{
      int r,c,i,j,k,flag=0;
      char m[100][101];
      scanf("%d",&r);
      scanf("%d",&c);
      for(i=0;i<r;i++)
      {
                      gets(char[i]);
                      }
      if(c>=5)
      {
      for(i=0;i<r;i++)
      {
         for(j=0;j<c;j++)
         {
              if(m[i][j]=='s'&&m[i][j+1]=='p'&&m[i][j+2]=='o'&&m[i][j+3]=='o'&&m[i][j]=='n');
              {
                  flag++;
                  break;
                  }
                  }
                  }
                  }
      if(r>=5)
      {
          for(i=0;i<c;i++)
          {
                for(j=0;j<r;j++)
                {
                      if(m[j][i]=='s'&&m[j+1][i]=='p'&&m[j+2][i]=='o'&&m[j+3][i]=='o'&&m[j+4][i]=='n')
                      {
                         flag++;
                         break;
                         }
                         }
                         }
                         }
       if(flag>0)
       {
                 printf("there is indeed a spoon!");
                 }
       else
       {printf("there is indeed no spoon!");}
       getch();
       }
