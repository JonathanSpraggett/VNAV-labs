#include "random_vector.h"
// TODO: add any include you might require
#include <random>

RandomVector::RandomVector(int size, double max_val) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dis(0.0, max_val);

  // TODO: Write your code here
  for (int i =0; i< size ;i++) {
    vect.push_back(dis(gen));
  }

  vect.reserve(size);
  max_value = max_val;

}

void RandomVector::print(){
  for (auto &i:vect) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

double RandomVector::mean(){
  double sum = 0;
  
}

double RandomVector::max(){
  // TODO: Write your code here
}

double RandomVector::min(){
  //TODO:  Write your code here
}

void RandomVector::printHistogram(int bins){
  // TODO: Write your code here
}
