#include <iostream>
#include <vector>
#include <utility>
#include <map> 
using std::vector;
using std::pair;
int reach(vector<bool> &visited, vector<vector<int> > &adj, int x, int y) {
  // for(int i = 0; i<adj.size();i++){
  //   std::cout<<"adjacents: "<<i<<": ";
  //   for(int j = 0; j<adj[i].size();j++){
  //     std::cout<<adj[i][j]<<",";
  //   }
  //   std::cout<<std::endl;
  // }
  // std::cout<<" startend: "<<x<<" "<<y<<std::endl;
  if(x==y){
    return 1;
  }
  visited[x] = true;
  for(int i = 0; i<adj[x].size();i++){
    // std::cout<<"adjacents: "<<adj[x][i]<<"; ";
    if(visited[adj[x][i]]==false){
      int result = reach(visited,adj,adj[x][i],y);
      if(result == 1){
        return 1;
      }
    }
    // std::cout<<std::endl;
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  vector<bool> visited(n, false);
  std::cout << reach(visited,adj, x - 1, y - 1)<<std::endl;
}


// 4 4
// 1 2
// 3 2
// 4 3
// 1 4
// 1 4

// 4 2
// 1 2
// 3 2
// 1 4