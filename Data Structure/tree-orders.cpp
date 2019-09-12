#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  // vector <int> tio(int i){
  //   if(i==-1){
  //     return {};
  //   }
  //   vector<int> result;
  //   vector<int> rights;

  //   result = tio(left[i]);
  //   rights = tio(right[i]);
    
  //   result.push_back(key[i]);
  //   result.insert(result.end(),rights.begin(),rights.end());

  //   return result;
  // }
  void tio(int i){
    if(i!=-1){
      
      tio(left[i]);
      cout<<key[i]<<' ';
      tio(right[i]);
    }
  }  
  // vector <int> tpreo(int i){
  //   if(i==-1){
  //     return {};
  //   }
  //   vector <int> result;
  //   vector<int> lefts;
  //   vector<int> rights;
  //   result.push_back(key[i]);

  //   lefts = tpreo(left[i]);
  //   rights = tpreo(right[i]);

  //   result.insert(result.end(),lefts.begin(),lefts.end());
    
  //   result.insert(result.end(),rights.begin(),rights.end());

  //   return result;
  // }
  void tpreo(int i){
    if(i!=-1){
      cout<<key[i]<<' ';
      tpreo(left[i]);
      tpreo(right[i]);
    }
  }
  // vector <int> tposto(int i){
  //   if(i==-1){
  //     return {};
  //   }
  //   vector<int> result;
  //   vector<int> rights;
    

  //   result = tposto(left[i]);
  //   rights = tposto(right[i]);
    
  //   result.insert(result.end(),rights.begin(),rights.end());
  //   result.push_back(key[i]);

  //   return result;
  // } 
  void tposto(int i){
    if(i!=-1){
      tposto(left[i]);
      tposto(right[i]);
      cout<<key[i]<<' ';
    }
  }       
  void in_order() {
    // vector<int> result;
    tio(0);
    cout<<"\n";
    // result = tio(0);
    // return result;
  }

  void pre_order() {
    // vector<int> result;    
    // result = tpreo(0);
    // return result;
    tpreo(0);
    cout<<"\n";
  }

  void post_order() {
    // vector<int> result;
    // result = tposto(0);
    // return result;
    tposto(0);
    cout<<"\n";
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  t.in_order();
  t.pre_order();
  t.post_order();
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

