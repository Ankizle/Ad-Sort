#ifndef SORT_HH_
#define SORT_HH_

#include <vector>
#include <map>
#include "calculate_sum.hh"
using namespace std;

//function to sort, and return a pointer array
vector<map<string, double>> sort(vector<map<string, double>> data) {

  //if it only has 1 element just return the given vector
  if (data.size() <= 1) return data;

  //get the pivot value
  double firstval = calcSum(data[0]);

  map<string, double> firstdata = data[0];

  //remove the pivot from the data
  data.erase(data.begin());

  //create the first (less) and second (greater) partitions
  vector<map<string, double>> first, second;

  for (map<string, double> it : data) {

    //get sum
    double sum = calcSum(it);

    if (sum <= firstval) first.push_back(it);
    else second.push_back(it);

    delete &sum; //free memory address of sum
  }

  delete &data;

  vector<map<string, double>> merged = sort(first)
  , sortedSecond = sort(second);

  merged.push_back(firstdata);

  //free memory address of firstdata
  delete &firstdata;

  //merge the two vectors
  merged.insert(merged.end(), sortedSecond.begin(), sortedSecond.end());

  delete &sortedSecond;

  return merged;
}

#endif
