#include <cstdio>
#include <iostream>

using namespace std;

#define sz 1000001
#define hi 1001

bool prime[sz];
long primeTable[78500],nPrime,sum[78500];

void sieve(){
 int i,j;

 for( i=4; i < sz ;i += 2)
  prime[i] = true;

 primeTable[nPrime++] = 2;

 for( i=3; i <= hi;i += 2){
  if(!prime[i]){
   primeTable[nPrime++] = i;
   for(j = i+i; j < sz; j += i)
    prime[j] = true;
  }
 }
 for( i= hi+2; i < sz; i += 2)
  if(!prime[i])
   primeTable[nPrime++] = i;
}

long findSum(long I,long J){
 long summ = 0;

 for(int i = I; i < J; i++){
  summ += primeTable[i];
  if(summ > sz)
   return 0;
 }
 return summ;
}


int main(){
 long i,j,k,l,tmp,max,ans;

 sieve();

 max = ans = 0;
 for(i = 0; i < nPrime; i++){
  tmp = 0;
  for(j = i; j < nPrime; j++){
   tmp += primeTable[j];
   if( tmp >= sz){
    //i = j-1;
    break;
   }

   if(!prime[tmp] && (j-i+1) > max){
    max = j-i+1;
    ans = tmp;
   }
  }
 }

 printf("%ld %ld\n",ans,max);

 return 0;
}
