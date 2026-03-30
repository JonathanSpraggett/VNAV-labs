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
  for (auto &i:vect) {
    sum += i;
  }
  // double sum2 = std::accumulate(vect.begin(), vect.end(), 0.0);
  //
  // std::cout <<  sum/vect.size()  << "  " << sum2/vect.size() <<  std::endl;
  return sum/vect.size();
  
}

double RandomVector::max(){
  double max = 0;
  for (auto &i:vect) {
    if (i > max) {
      max = i;
    }

  }

  // auto max2 = std::max_element(vect.begin(), vect.end());
  //
  // std::cout << max  << "  " << *max2 <<  std::endl;
  return max;
}

double RandomVector::min(){
  double min = 100000;
  for (auto &i:vect) {
    if (i < min) {
      min = i;
    }

  }
  //
  // auto max2 = std::min_element(vect.begin(), vect.end());
  // std::cout << min  << "  " << *max2 <<  std::endl;
  return min;
}

void RandomVector::printHistogram(int bins) {
  double min = RandomVector::min();
  double max = RandomVector::max();
  double bin_step = (max - min)/ (bins);

  std::vector<int> hist(bins, 0);
  // std::vector<std::vector<double>> hist(bins);
  std::sort(vect.begin(), vect.end());
  int counter = 0;
  for (auto &elem: vect) {
    for (int i =0; i < (bins-1); i++) {
      if (elem > (min +bin_step*i) && elem < (min +bin_step*(i+1))) {
        hist[i] += 1;
        counter += 1;
      }
    }
  }
  hist[hist.size() -1] = vect.size() - counter;

  // for (auto &i:hist) {
  //   std::cout << i << " ";
  // }
  // std::cout << std::endl;

  int max_hist = 0;
  for (auto &i:hist) {
    if (i > max_hist) {
      max_hist = i;
    }

  }



  for (int i =max_hist; i > 0; i--) {
    std::string hist_out;
    for ( auto &elem:hist) {
      if (elem == i) {
        hist_out += "*** ";
        elem -= 1;
      }
      else {
        hist_out += "    ";
      }
    }
    std::cout << hist_out << std::endl;
  }
}