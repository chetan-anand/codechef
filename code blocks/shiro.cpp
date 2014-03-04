#include<cstdio>
#include<algorithm>
using namespace std;
double ks[11010][105];
int main(){
    int t,n,i,j,sum,a[105];
    double p[105],temp,val;
    scanf("%d",&t);
    while(t--){

               //initialisation
               sum=0;
               val=0.0;
               a[0]=0;
               p[0]=0;
               for(i=0;i<10010;i++)
                                 for(j=0;j<105;j++)
                                                   ks[i][j]=0;

               //input
               scanf("%d",&n);
               for(i=1;i<=n;i++){
                               scanf("%d",&a[i]);
                               sum+=a[i];
               }
               sort(a,a+n+1);
               for(i=1;i<=n;i++){
                               scanf("%lf",&temp);
                               p[i]=temp/(double)100;
               }



               //evaluation
               for(i=0;i<=sum;i++){
                                   ks[i][0]=ks[i][1]=0;
               }
               ks[0][1]=(double)1-p[1];
               ks[a[1]][1]=p[1];
               for(j=2;j<=n;j++){
                                 for(i=0;i<=sum;i++){
                                      if(i<a[j])
                                           ks[i][j]=ks[i][j-1]*((double)1-p[j]);
                                      else{
                                                     ks[i][j]=ks[i][j-1]*((double)1-p[j]) + ks[i-a[j]][j-1]*p[j];
                                      }
                                 }

               }//i loop ends
               for(i=(sum+1)/2;i<=sum;i++)
                {
                    val=ks[i][n];

                }printf("%.6lf\n",val);
    }//while ends
    return 0;
}
