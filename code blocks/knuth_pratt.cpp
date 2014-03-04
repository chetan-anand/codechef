#include<stdio.h>
#include<string.h>
int f[1000];
void preprocess(char* pattern) // building the initial automaton
{
    int i,j,k;
    int m=strlen(pattern); //length of pattern
    f[0]=f[1]=0; // always true
    for(i=2;i<=m;i++)
    {
        // j is the index of the largest next partial match
        // (the largest suffix/prefix) of the string under index i-1
        j=f[i-1];
        for(;;)
        {
            //check to see if the last character of string i-pattern[i-1] "expands" the current candidate
            // best partial match - the prefix under index j
            if(pattern[j]==pattern[i-1])
            {
                f[i]=j+1;
                break;
            }
            //if we cannot "expand" even the empty string
            if(j==0){f[i]=0;break;}
            //else go to the next base "candidate" partial match
            j=f[j];
        }
    }
}

void Knuth_Morris_Pratt(char* text,char *pattern)
{
  // let n be the size of the text, m the
  // size of the pattern, and F[] - the
  // "failure function"
    int n,m,i,j,k;
    n=strlen(text);
    m=strlen(pattern);
  preprocess(char *pattern);

  i = 0; // the initial state of the automaton is
         // the empty string

  j = 0; // the first character of the text

  for( ; ; ) {
    if(j == n) break; // we reached the end of the text

    // if the current character of the text "expands" the
    // current match
    if(text[j] == pattern[i]) {
      i++; // change the state of the automaton
      j++; // get the next character from the text
      if(i == m) // match found
    }

    // if the current state is not zero (we have not
    // reached the empty string yet) we try to
    // "expand" the next best (largest) match
    else if(i > 0) i = F[i];

    // if we reached the empty string and failed to
    // "expand" even it; we go to the next
    // character from the text, the state of the
    // automaton remains zero
    else j++;
  }
}

