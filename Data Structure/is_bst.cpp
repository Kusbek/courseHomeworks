#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  for(size_t i = 0; i<tree.size(); i++){
    if(tree[i].left != -1) { 
      if(tree[tree[i].left].key > tree[i].key){
        return false;
      }else{
        if(tree[tree[i].left].right != -1){
          if(tree[tree[tree[i].left].right].key > tree[i].key){
            return false;
          }
        }
      }
    }

    if(tree[i].right != -1) { 
      if(tree[tree[i].right].key < tree[i].key){
        return false;
      }else{
        if(tree[tree[i].right].left != -1){
          if(tree[tree[tree[i].right].left].key < tree[i].key){
            return false;
          }
        }          
      }
    }
      
  }
  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}

// 7
// 4 1 2
// 2 3 4
// 6 5 6
// 1 -1 -1
// 3 -1 -1
// 5 -1 -1
// 7 -1 -1

// 4
// 4 1 -1
// 2 2 3
// 1 -1 -1
// 5 -1 -1