#ifndef GENERATE_HH_
#define GENERATE_HH_

#include <vector>
#include <map>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;

//refrence vars:
//---------------------
const int
  min_data_size = 10,
  max_data_size = 100;

const int dullness[2] = {0, 100};
const int compensation[2] = {1, 999};
const int length[2] = {5, 60};
const int popularity[2] = {-1000, 1000};
//---------------------

vector<map<string, double>> generate() {

  //init a dataset
  vector<map<string, double> > dataset;

  //calculate a data size
  int data_size = rand() % (max_data_size - min_data_size + 1) + min_data_size;

  //generate the seed

  //get current time
  struct timeval tp;

  gettimeofday(&tp, NULL);
  long int time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
  //////////////////

  srand(time);
  ///////////////////

  delete &time;
  delete &tp;

  for (int i = 0; i < data_size; i++) {

    //init a map
    map<string, double> curMap;

    int
      dullness_value = rand() % (dullness[1] - dullness[0] + 1) + dullness[0],
      compensation_value = rand() % (compensation[1] - compensation[0] + 1) + compensation[0],
      length_value = rand() % (length[1] - length[0] + 1) + length[0],
      popularity_value = rand() % (popularity[1] - popularity[0] + 1) + popularity[0];

    //insert the values into the map
    curMap.insert(pair<string, double>("dullness", dullness_value));
    curMap.insert(pair<string, double>("compensation", compensation_value));
    curMap.insert(pair<string, double>("length", length_value));
    curMap.insert(pair<string, double>("popularity", popularity_value));

    //push into the data set
    dataset.push_back(curMap);

    delete &curMap;

    delete &dullness_value;
    delete &compensation_value;
    delete &length_value;
    delete &popularity_value;
  }

  delete &data_size;

  return dataset;
}

#endif
