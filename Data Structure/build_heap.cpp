#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector<int> data1;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n = 11;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; i++)
      cin >> data_[i];
  }

  int parent(int i){
    return (i-1)/2;
  }

  int leftChild(int i){
    return 2*i+1;
  }
  int rightChild(int i){
    return 2*i+2;
  }  
  // void siftUp(int i){
  //   swaps_.clear();
  //   int it = i;
  //   while (it > 0 && data1[parent(it)]>data1[it]){
  //     // cout<<it<<" ";
  //     swap(data1[it], data1[parent(it)]);
  //     swaps_.push_back(make_pair(it, parent(it)));
  //     it = parent(it);
  //   }
  // }

  void siftDown(int i){
    int maxIndex = i;
    int r = rightChild(i);
    int l = leftChild(i);
    if (l<data_.size() && data_[l]<data_[maxIndex]){
      maxIndex = l;
    }      
    if (r<data_.size() && data_[r]<data_[maxIndex]){
      maxIndex = r;
    }

    if (maxIndex!=i){
      swap(data_[i], data_[maxIndex]);
      swaps_.push_back(make_pair(i, maxIndex)); 
      siftDown(maxIndex);     
    }
    
  }

  void GenerateSwaps() {
    swaps_.clear();
    // for (int i = 0; i < data_.size(); ++i)
    //   for (int j = i + 1; j < data_.size(); ++j) {
    //     if (data_[i] > data_[j]) {
    //       swap(data_[i], data_[j]);
    //       swaps_.push_back(make_pair(i, j));
    //     }
    //   }
    for (size_t i = (data_.size() - 1)/2; i < data_.size(); --i){
        siftDown(i);
    }   
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
