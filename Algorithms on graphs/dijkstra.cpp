#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;
typedef pair<int,int> pi;
typedef priority_queue<pi,vector<pi>, greater<pi>> priority_pi;
typedef pair<int, priority_pi> edges;

void pushIntoQueue(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, queue<edges> &H, vector<bool> &pushed){
  priority_pi si;
  for(int i = 0; i<adj[s].size(); i++){
      si.push(make_pair(cost[s][i],adj[s][i]));
  }
  
  H.push(make_pair(s,si));
  pushed[s] = true;
}
int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  vector<int> dist(adj.size(), 2000000000);
  vector<bool> pushed(adj.size(), false);
  dist[s] = 0;
  queue<edges> H;
  pushIntoQueue(adj,cost,s,H, pushed);
  pushed[s] = true;

  while(!H.empty()){
    edges segment  = H.front();
    H.pop();
    int start = segment.first;
    priority_pi pr_weights = segment.second;
    while (!pr_weights.empty()){
      pi weights = pr_weights.top();
      int weight = weights.first;
      int finish = weights.second;
      if(!pushed[finish]){
        pushIntoQueue(adj,cost,finish,H,pushed);
      }
      if(dist[finish]>dist[start] + weight){
        dist[finish] = dist[start] + weight;
      }
      // cout<<"start: "<<start<<" finish: "<<finish<<" weight: "<<weight<<endl;
      pr_weights.pop();
    }
  }
  // for(int i = 0; i<dist.size(); i++){
  //   cout<<dist[i]<<" ";
  // }
  // cout<<endl;
  if(dist[t]>1999999999){
    return -1;
  }else{
    return dist[t];
  }  
  
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t)<<endl;
}

// 4 6
// 1 2 1
// 4 1 2
// 2 3 2
// 1 3 5
// 3 5 1
// 3 4 2
// 1 3

// 4 4
// 1 2 1
// 4 1 2
// 2 3 2
// 1 3 5
// 1 3

// 4 6
// 1 2 1
// 4 1 2
// 2 3 2
// 1 3 5
// 3 5 1
// 3 1 0
// 1 3

// 5 9
// 1 2 4
// 1 3 2
// 2 3 2
// 3 2 1
// 2 4 2
// 3 5 4
// 5 4 1
// 2 5 3
// 3 4 4
// 1 5


// 3 3
// 1 2 7
// 1 3 5
// 2 3 2
// 3 2


// 4 4
// 1 2 1
// 4 1 2
// 2 3 2
// 1 3 5
// 2 3


// for(int i = 0; i<adj.size(); i++){
//   for(int j = 0; j <adj[i].size(); j++){
//     cout<<"start: "<<i+1<<" finish: "<<adj[i][j]+1<<" cost: "<<cost[i][j]<<endl;
//   }
// }

// 6 11  
// 1 2 3 
// 1 3 10
// 2 4 3 
// 2 5 5 
// 2 3 8 
// 3 2 2 
// 3 5 5 
// 4 3 3 
// 4 5 1 
// 4 6 2 
// 5 6 0 
// 1 6 