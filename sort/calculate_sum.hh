#ifndef CALCULATE_SUM_HH_
#define CALCULATE_SUM_HH_

#include <map>
using namespace std;

map<string, double> biases = {
  { "dullness", -0.5 },
  { "compensation", 0.9 },
  { "length", -2.0 },
  { "popularity", 5.0 }
};

double calcSum(map<string, double> val) {

  double sum = 0;

  //get the sum of all the data points while accounting for biases
  for (pair<string, double> it : val) {

    double bias = biases[it.first];
    sum+=bias * it.second;

    delete &bias;
  }

  return sum;
}

#endif
