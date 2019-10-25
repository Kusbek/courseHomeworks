#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
using std::vector;
using namespace std;



struct Node{
  int x;
  int y;
  Node *parent;
  int rank;
  Node(int x, int y, Node* parent = NULL, int rank = 0):
    x (x),
    y (y),
    parent (parent),
    rank (rank)
  {}
};
typedef pair<double, pair<Node*,Node*>> pi;
typedef priority_queue<pi,vector<pi>, greater<pi>> prq;

Node* find(Node* node){
  while(node->parent!=NULL){
    node = node->parent;
  }
  return node;
}
void unite(Node* node1, Node* node2){
  node2->parent = node1;
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  prq dists;
  vector<Node*> nodes(x.size());

  for (int i = 0; i<x.size(); i++){
    nodes[i] = new Node(x[i],y[i],NULL,0);
  }
  for (int i = 0; i<x.size(); i++){
    for(int j = i+1; j<x.size();j++){
      double dist = sqrt(pow(x[j]-x[i],2) + pow(y[j]-y[i],2));
      dists.push(make_pair(dist,make_pair(nodes[i],nodes[j])));
    }
  }
  while(!dists.empty()){
    pi edge = dists.top();
    dists.pop();
    double w = edge.first;
    Node * node_start = edge.second.first;
    Node * node_finish = edge.second.second;
    // cout<<"node_start:"<<node_start->x<<" "<<node_start->y<<"; node_finish: "<<node_finish->x<<" "<<node_finish->y<<"; weight: "<<w<<endl;
    Node * root_start = find(node_start);
    Node * root_finish = find(node_finish);
    // cout<<"root_start:"<<root_start->x<<" "<<root_start->y<<"; root_finish: "<<root_finish->x<<" "<<root_finish->y<<"; weight: "<<w<<endl;
    if(root_start!=root_finish){
      result+=w;
      unite(root_start,root_finish);
    }
    // cout<<"root of "<<node_finish->x<<" "<<node_finish->y<<" with weight "<<w<<" is "<<find(node_finish)->x<<" "<<find(node_finish)->y<<endl;
    // cout<<endl ;
  }
  //write your code here
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}


// 5
// 0 0
// 0 2
// 1 1
// 3 0
// 3 2