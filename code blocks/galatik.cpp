#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define min(a,b) a<b?a:b
using namespace std;
vector<int> adjacency[100000];
bool visited[100000];
int v[100000],minv[100000],totalComponents;
/// @param Standard algorithm DFS
void dfs(int u){
    visited[ u ] = true;
    if(v[u]>=0)
    {
        if(minv[totalComponents]<0){minv[totalComponents]=v[u];}
        else{minv[totalComponents]=min(minv[totalComponents],v[u]);}
    }
    for( int v = 0 ; v < adjacency[u].size(); ++v ){
        if( !visited[ adjacency[u][v] ] ){
            dfs( adjacency[u][v] );
        }
    }
}

    int main(){
        int vertex, edges , originNode ,destinationNode, i, j,cont =1,total,midx;
        memset( visited , 0 , sizeof( visited ) );
        scanf("%d %d" , &vertex , &edges );

        for (j=0; j<edges; j++){
            scanf("%d %d" , &originNode ,&destinationNode );
            originNode--;destinationNode--;
            adjacency[ originNode ].push_back( destinationNode );
            adjacency[ destinationNode ].push_back( originNode );
        }
        for(j=0;j<vertex;j++)
        {
            scanf("%d",&v[j]);
        }
        if(vertex==1)
        {
            if(v[0]<0){printf("-1");return 0;}
            else{printf("0");return 0;}
        }

            totalComponents =0;
            for( int i = 0 ; i < vertex ; ++i ){    // Loop through all possible vertex
                if( !visited[ i ] ){
                    minv[totalComponents]=v[i];
                    dfs( i );                  //we travel from node i the entire graph is formed
                    totalComponents++;                   //increased amount of components
                }
            }
            //printf("Case %d: %d component (s) connected (s)\n" ,cont++, totalComponents);
        if(totalComponents==1){printf("0");return 0;}
            for(j=0;j<totalComponents;j++)
            {
                if(minv[j]<0){printf("-1");return 0;}
                if(j==0){midx=0;continue;}
                if(minv[j]<minv[midx]){midx=j;}
            }
            int ans=0;
            for(j=0;j<totalComponents;j++)
            {
                if(j==midx){continue;}
                ans=ans+minv[midx]+minv[j];
            }
            printf("%d",ans);

    return 0;
    }
