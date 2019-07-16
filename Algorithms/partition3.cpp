#include <iostream>
#include <vector>
#include <numeric>  
using std::vector;

int partition3(vector<int> &A) {
  int sumA = std::accumulate(A.begin(),A.end(),0);
  if (A.size()< 3 || sumA%3!=0){
    return 0;
  }

  int x = sumA/3+1;
  int y = sumA/3+1;
  int z = A.size()+1;
 
  std::vector<std::vector<std::vector<int>>> value;
  value.resize(z, std::vector<std::vector<int>>(x, std::vector<int>(y,0)));
  // std::cout<<value.size()<<", "<<value[0].size()<<", "<<value[0][0].size()<<std::endl;
  for(int zi = 0; zi<z;zi++){
    int curr_value = A[zi-1];
    value[zi][0][0] = 1; 
    for(int xi = 0; xi<x;xi++){
      for(int yi = 0; yi<y;yi++){
        if (zi==0 && (xi!=0 && yi!=0)){
          value[zi][xi][yi] = 0; 
        } else if (zi>0 && (xi>0 || yi>0)) {
          value[zi][xi][yi] = value[zi-1][xi][yi];
          if (xi>=curr_value && value[zi-1][xi-curr_value][yi] == 1){
            value[zi][xi][yi] = value[zi-1][xi-curr_value][yi];
          }
          if (yi>=curr_value && value[zi-1][xi][yi-curr_value] == 1){
            value[zi][xi][yi] = value[zi-1][xi][yi-curr_value];
          }            
        }
        // std::cout<<value[zi][xi][yi]<<" ";
      }
      // std::cout<<std::endl; 
    }
    // std::cout<<std::endl;
    // std::cout<<std::endl;  
  }
  // std::cout<<value[z-1][x-1][y-1]<<std::endl;
  return value[z-1][x-1][y-1];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}

// int main() {
//   int n = 13;
//   vector<int> A(n);
//   A = {1,2,3,4,5,5,7,7,8,10,12,19,25};
//   // partition3(A);
//   std::cout<<partition3(A)<<std::endl;
// }
