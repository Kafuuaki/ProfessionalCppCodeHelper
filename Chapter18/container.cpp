// This chapter includes container classes

// type of containers
// Sequential containers, Associative containers, Unordered containers,
// Container adaptorss

// Allocator is used to allocate and deallocate memory for containers

// map class template
// template <class Key, class T, class Compare = std::less<Key>,
// class Allocator = std::allocator<std::pair<const Key, T>>> class map;

// the content will be covered in this chapter:

// type allocator
// sqeuential containers

// comparing vector

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main() {
  vector<double> doubleVector(10); // Create a vector of 10 doubles. //
                                   // Initialize max to smallest number
  double max{-numeric_limits<double>::infinity()};
  // for (size_t i { 0 }; i < doubleVector.size(); i++) { cout << format("Enter
  // score {}: ", i + 1); cin >> doubleVector[i]; if (doubleVector[i] > max) {
  // max = doubleVector[i]; }
  // }
  max /= 100.0;
  for (auto &element : doubleVector) {
    element /= max;
    cout << element << " ";
  }

  // vector<double> doubleVector; // Create a vector with zero elements. //
  // Initialize max to smallest number double max {
  // -numeric_limits<double>::infinity() }; for (size_t i { 1 }; true; i++) {
  // double temp; cout << format("Enter score {} (-1 to stop): ", i); cin >>
  // temp; if (temp == -1) { break; } doubleVector.push_back(temp); if (temp >
  // max) { max = temp; }
  // }
  // max /= 100.0;
  // for (auto& element : doubleVector) {
  // element /= max;
  // cout << element << " "; }

  // allocate vector on free store
  // std::unique_ptr<vector<int>>
  // vec_free_store(std::make_unique<vector<int>>(vector<int>(10)));

  // std::unique_ptr<vector<int>>
  // vec_free_store(std::make_unique(vector<int>(10)));

  // this (10) call the constructor of vector<int>
  auto elementVector{make_unique<vector<int>>(10)};

  vector<int> intVector(10);

  intVector.assign(5, 100);

  vector<int> vectorOne(10);
  vector<int> vectorTwo(5, 100);
  vectorOne.swap(vectorTwo);

  return 0;
}
