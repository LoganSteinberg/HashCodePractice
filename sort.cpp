#include <algorithm>
#include "sort.hpp"

template<typename T, typename P>
sorts<T>::sorts(const P(*compar)(const T &, const T &), T data_to_sort){
  this.internal_data_store = data_to_sort;
  this.comparator = compar;
}

template<typename T>
sorts<T>::sort(T& arr){
  std::sort(arr.begin(), arr.end(), this.comparator);
}