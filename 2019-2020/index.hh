//Science Research 2019-20 Ankit Karnam

#include <vector>
#include <map>

#include "generate.hh"
#include "sort/sort.hh"
using namespace std;

vector<map<string, double>> generate_and_sort() {

  vector<map<string, double>> generated = generate();
  vector<map<string, double>> sorted = sort(generated);

  delete &generated;

  return sorted;
}
