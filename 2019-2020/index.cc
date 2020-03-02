#include <iostream>
#include <vector>
using namespace std;

int main() {
  
  const int min_data_size = 70
    , max_data_size = 10000;
  
  const int min_int = 100
    , max_int = 10000;
  
  vector<int> dataset;
  
  int data_size = rand() % (max_data_size - min_data_size + 1) + min_data_size;
  
  for (int i = 0; i < data_size; i++) dataset.push_back(rand() % (max_int - min_int + 1) + min_int);
  
  return 0;
}
