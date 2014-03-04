#include<bits/stdc++.h>
using namespace std;
vector<int> adjacency[10000];
bool visited[10000];

void dfs(int u)
{
    visited[ u ] = true;
    for( int v = 0 ; v < adjacency[u].size(); ++v ){
        if( !visited[ adjacency[u][v] ] ){
            dfs( adjacency[u][v] );
        }
    }
}

    int main(int argc, char *argv []){

        std::pair<int,int> x;
         ///enumerate vertices from 1 to vertex
        int vertex, edges , originNode ,destinationNode, i, j,cont =1,total;
        ///number of test cases
        int testCases;
        int totalComponents;
        scanf ("%d", &testCases);

        for (i=0; i<testCases; i++){

        memset( visited , 0 , sizeof( visited ) );
        scanf("%d %d" , &vertex , &edges );
        for (j=0; j<edges; j++){
            scanf("%d %d" ,&originNode ,&destinationNode );

            adjacency[ originNode ].push_back( destinationNode);
            adjacency[ destinationNode ].push_back( originNode );
        }
            totalComponents =0;
            for( int i = 0 ; i < vertex ; ++i ){    // Loop through all possible vertex
                if( !visited[ i ] ){          //if we have not visited any one component from that node
                    dfs( i );                  //we travel from node i the entire graph is formed
                    totalComponents++;                   //increased amount of components
                }
            }
            printf("Case %d: %d component (s) connected (s)\n" ,cont++, totalComponents);

            for (j=0;j<total;j++){
        /*here should indicate the vertices of each connected component*/
    }
        memset( adjacency , 0 , sizeof( adjacency ) );
        }
    return 0;
    }
