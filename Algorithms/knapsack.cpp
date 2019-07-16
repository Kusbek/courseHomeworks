#include <iostream>
#include <vector>

using std::vector;

// int optimal_weight(int W, const vector<int> &w) {
//   int value[W+1];
//   for(size_t current_W = 0; current_W <=W; current_W++){
//     value[current_W] = 0;
//     int val = 0;
//     for(size_t j = 0; j <w.size(); j++){
//       if (w[j]<=current_W){
//         val = value[current_W - w[j]] + w[j];
//         if (val>value[current_W]){
//           value[current_W] = val;
//         }
//       }
//     }
//     std::cout<<current_W<<", "<<value[current_W]<<std::endl;
//   }

//   return value[W];
// }

int optimal_weight(int W, const vector<int> &w) {
  int no_of_cols = W+1;
  int no_of_rows = w.size()+1;
  std::vector<std::vector<int>> value;
  value.resize(no_of_rows, std::vector<int>(no_of_cols, 0));

  for (size_t i = 0; i<=w.size(); i++){
    for (size_t curr_w = 0; curr_w<=W; curr_w++){
      if(curr_w == 0 || i == 0){
        value[i][curr_w] = 0;
      } else{
        value[i][curr_w] = value[i-1][curr_w];
        if(w[i-1]<=curr_w){
          int val = value[i-1][curr_w - w[i-1]] + w[i-1];
          if(value[i][curr_w]<val){
            value[i][curr_w] = val;
          }
        } 
      }
    }
  }
  return value[w.size()][W];;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
