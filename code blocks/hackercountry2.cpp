
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
#include <cstring>
#include <functional>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef int weight_type;
const weight_type INF = 99999999;
struct edge {
  int src, dst;
  weight_type weight;
};
struct minimum_mean_cycle {
  vector<edge> edges;
  void add_edge(int src, int dst, weight_type weight) {
    // must be directed
    edges.push_back({src, dst, weight});
  }
  int n;
  vector<vector<edge>> adj;
  void make_graph(int n_ = 0) {
    n = n_;
    for (auto e: edges)
      n = max(n, max(e.src, e.dst)+1);
    adj.resize(n);
    for (auto e: edges)
      adj[e.src].push_back(e);
  }

  double solve() {
    vector<vector<weight_type>> dist(n+1, vector<weight_type>(n, INF));
    dist[0][0] = 0;
    for (int k = 0; k < n; ++k)
      for (int u = 0; u < n; ++u)
        for (auto e: adj[u])
          dist[k+1][e.dst] = min(dist[k+1][e.dst], dist[k][e.src] + e.weight);
    weight_type num = 1;
    int den = 0;
    for (int k = 0; k < n; ++k)
      for (int u = 0; u < n; ++u)
        if (dist[k][u] < INF)
          if (num * (n-k) > (dist[n][u]-dist[k][u]) * den) {
            num = (dist[n][u] - dist[k][u]);
            den = n-k;
          }
    printf("%d/%d",num,den);
    //return 1.0*num/den;
  }
};



int main() {
  minimum_mean_cycle solver;
  int n ,x;
  cin>>n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      {
          cin>>x;
          if(x==0)
          x=2000000000;
          solver.add_edge(i, j, x);
      }
  solver.make_graph(n);
    solver.solve();
  //cout << solver.solve() << endl;
  return 0;
}
