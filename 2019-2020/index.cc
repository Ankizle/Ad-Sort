#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  
  const int min_data_size = 70
    , max_data_size = 10000;
  
  const int min_int = 100
    , max_int = 10000
    , max_variance = 9;
  
  vector<map<string, int> > dataset;
  
  int data_size = rand() % (max_data_size - min_data_size + 1) + min_data_size;
  
  for (int i = 0; i < data_size; i++) {
    map<string, int> curMap;
    
    int variance_lower = variance_lower = rand() % (max_variance + 1);
      , variance_upper = rand() % (max_variance + 1);
    
    curMap.insert(pair<string, int>("cost", rand() % (max_int - min_int + 1) + min_int));
    curMap.insert(pair<string, int>("max_discount_cost", variance_lower));
    curMap.insert(pair<string, int>("max_markup_cost", variance_upper));
    dataset.push_back(curMap);
  }
  
  return 0;
}
