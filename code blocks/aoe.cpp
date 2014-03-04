#include<iostream>
using namespace std;
int main(){
    int T, N, Q, i,j,k;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d %d",&N, &Q);
       int affiliation[N];
       for(int l = 0; l<N; l++){
            affiliation[l]=0;
       }
       int nextAff = 1;
       for(j = 0;j<Q;j++) {
            int queryType ,src, dest;
            scanf("%d %d %d", &queryType, &src, &dest);
           if(queryType == 0){
               if(affiliation[src] != 0 && affiliation[dest]==0){
                    affiliation[dest] = affiliation[src];
                    printf("OK\n");
               }
               else if(affiliation[dest] != 0 && affiliation[src]==0){
                    affiliation[src] = affiliation[dest];
                    printf("OK\n");
               }
                else if(affiliation[src] == 0 && affiliation[dest] == 0){
                    affiliation[dest] = nextAff;
                    affiliation[src] = nextAff;
                    nextAff++;
                    printf("OK\n");
                }
                else{

                    if(affiliation[src] == affiliation[dest])
                        printf("OK\n");
                    else if(affiliation[src] == -affiliation[dest])
                        printf("CONFLICT\n");
                    else{
                        //need to merge
                        printf("OK\n");
                        int temp = affiliation[src];
                        for(k=0;k<N;k++){
                            if(affiliation[k] == temp)
                                affiliation[k]=affiliation[dest];
                            if(affiliation[k] == -temp)
                                affiliation[k]= -affiliation[dest];
                        }
                    }
               }
           }
           if(queryType == 1){
               if(affiliation[src] != 0 && affiliation[dest]==0){
                    affiliation[dest] = -affiliation[src];
                    printf("OK\n");
               }
               else if(affiliation[dest] != 0 && affiliation[src]==0){
                    affiliation[src] = -affiliation[dest];
                    printf("OK\n");
               }
                else if(affiliation[src] == 0 && affiliation[dest] == 0){
                    affiliation[dest] = nextAff;
                    affiliation[src] = -nextAff;
                    nextAff++;
                    printf("OK\n");
                }
                else{

                    if(affiliation[src] == -affiliation[dest])
                        printf("OK\n");
                    else if(affiliation[src] == affiliation[dest])
                        printf("CONFLICT\n");
                    else{
                        printf("OK\n");
                        //need to merge
                        int temp = -affiliation[src];
                        for(k=0;k<N;k++){
                            if(affiliation[k] == temp)
                                affiliation[k]=affiliation[dest];
                            if(affiliation[k] == -temp)
                                affiliation[k]= -affiliation[dest];
                        }
                    }
               }
           }
           if(queryType == 2){
                if(affiliation[src]==affiliation[dest])
                    printf("FRIENDS\n");
                else if(affiliation[src]== -affiliation[dest])
                     printf("ENEMIES\n");
                else
                    printf("NEUTRAL\n");
           }



       }
    }
}
