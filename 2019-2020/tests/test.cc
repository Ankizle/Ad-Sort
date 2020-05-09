//index file to test data is sorted

#include <vector>
#include <map>
#include <thread>
#include <iostream>
#include "../index.hh"
#include "../sort/calculate_sum.hh"
using namespace std;

//amount of tests
const unsigned long test_amt = 10000;

void test(int cur) {
  vector<map<string, double>> sorted = generate_and_sort();

  for (int i = 0; i < sorted.size(); ++i) {

    if (i == 0) continue;

    if (calcSum(sorted[i]) < calcSum(sorted[i - 1])) {

      //goto next test
      goto failure;
    }
  }

  delete &sorted;

  cout << ("(+) Passed Test #" + to_string(cur) + "\n");
  return;

  failure:;
  cout << ("(-) Failed Test #" + to_string(cur) + "\n");
}

int main() {

  unsigned long
    passed = 0,
    failed = 0;

  for (unsigned long i = 0; i < test_amt;) {
    thread t(test, ++i);

    t.detach();
  }
}
