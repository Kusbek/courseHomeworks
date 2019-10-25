#include <iostream>
#include <vector>

using std::vector;
using namespace std;
int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  vector<int> dist(adj.size(), INT16_MAX);
  dist[0] = 0;

  for(int i = 0; i<adj.size()-1; i++){
    for(int j = 0; j < adj.size(); j++){
      for(int k = 0; k < adj[j].size(); k++){
        int w = dist[j] + cost[j][k];

        if(dist[adj[j][k]]>w){
          dist[adj[j][k]] = w;
        }
      }
    }
    // for(int j = 0; j<dist.size();j++){
    //   cout<<dist[j]<<" ";
    // }
    // cout<<endl;
  }
  for(int j = 0; j < adj.size(); j++){
    for(int k = 0; k < adj[j].size(); k++){
      int w = dist[j] + cost[j][k];
      if(dist[adj[j][k]]>w){
        return 1;
      }
    }
  }  
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}


// 4 4
// 1 2 -5
// 4 1 2
// 2 3 2
// 3 1 1

// 4 4
// 1 2 1
// 4 1 2
// 2 3 2
// 3 1 -5