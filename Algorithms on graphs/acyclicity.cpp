#include <iostream>
#include <vector>

using namespace std;
int dfs (vector<vector<int>>&adj, int x, vector<bool> &visited, vector<bool> &still_in_recursion){
  visited[x] = true;
  still_in_recursion[x] = true;

  for(int i=0; i<adj[x].size();i++){
    if(!visited[adj[x][i]] && dfs(adj,adj[x][i],visited,still_in_recursion)){
      return 1;
    }else if (still_in_recursion[adj[x][i]]){
      return 1;
    }
  }
  still_in_recursion[x] = false;
  return 0;
}



int acyclic(vector<vector<int> > &adj) {
  // for(size_t i = 0; i<adj.size(); i++){
  //   cout<<i<<": ";
  //   for(size_t j = 0; j<adj[i].size();j++){
  //     cout<<adj[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }  
  //write your code here
  vector<bool> still_in_recursion(adj.size());
  vector<bool> visited(adj.size());
  for(int i = 0; i<adj.size(); i++){
      if(!visited[i]){
        if(dfs(adj,i,visited,still_in_recursion)){
          return 1;
        }
      }
    } 
  cout<<endl;
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
  }
  std::cout << acyclic(adj)<<endl;;
}


// 5 7
// 1 2
// 2 3
// 1 3
// 3 4
// 1 4
// 2 5
// 3 5


// 4 4
// 1 2
// 4 1
// 2 3
// 3 1

// 4 3
// 1 2
// 3 2
// 4 3

// 4 4
// 1 2
// 3 2
// 4 3
// 2 4


// 200 100
// 94 123
// 121 81
// 131 11
// 198 173
// 135 60
// 10 118
// 34 8
// 59 178
// 32 142
// 135 24
// 95 197
// 34 74
// 98 86
// 28 97
// 49 28
// 8 38
// 119 198
// 75 171
// 120 198
// 163 19
// 183 59
// 188 121
// 71 41
// 72 2
// 182 78
// 165 155
// 129 103
// 64 195
// 5 164
// 156 23
// 49 181
// 132 85
// 66 120
// 76 151
// 176 22
// 82 67
// 178 196
// 90 8
// 184 24
// 199 63
// 25 9
// 102 176
// 44 161
// 195 192
// 187 135
// 136 40
// 118 87
// 74 10
// 191 108
// 91 100
// 57 1
// 39 130
// 112 133
// 34 168
// 53 164
// 182 7
// 108 48
// 50 20
// 12 174
// 117 28
// 99 33
// 153 172
// 17 21
// 154 5
// 27 136
// 124 109
// 110 40
// 112 166
// 137 84
// 158 84
// 80 99
// 160 103
// 105 42
// 194 76
// 107 44
// 107 115
// 117 147
// 33 88
// 84 130
// 178 198
// 63 195
// 37 136
// 109 129
// 1 85
// 141 152
// 199 12
// 13 189
// 121 97
// 60 64
// 29 77
// 193 157
// 80 43
// 68 9
// 155 78
// 142 190
// 40 182
// 69 146
// 142 173
// 56 183
// 63 138