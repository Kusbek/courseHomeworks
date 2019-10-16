#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using namespace std;
int bfs(vector<vector<int>> &adj, int s, int t, int d, queue<pair<int,int>> &queues, vector<bool> &pushed){
  if(s==t){
    return d;
  }
  d = d + 1;

  for(int i = 0; i < adj[s].size();i++){
    if(!pushed[adj[s][i]] && adj[s][i] != s){
      // cout<<s<<" pushing "<<adj[s][i]<<":"<<d<<endl;
      pushed[adj[s][i]] = true;
      queues.push(make_pair(adj[s][i],d));
    }
  }
  if(!queues.empty()){
    pair<int,int> current = queues.front();
    queues.pop();
    return bfs(adj,current.first,t,current.second,queues, pushed);
  }
  return -1;
}
int distance(vector<vector<int> > &adj, int s, int t) {
  vector<bool> pushed(adj.size(), false);
  queue<pair<int,int>> queues;
  int d = 0;
  pushed[s] = true;
  int ans = bfs(adj,s,t,d,queues, pushed);
  return ans;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t)<<endl;
}

// 4 4
// 1 2
// 4 1
// 2 3
// 3 1
// 2 4


// 5 8
// 4 1
// 4 1
// 1 1
// 3 5
// 1 4
// 5 2
// 4 2
// 4 2
// 4 3