#ifndef NDARRAY
#define NDARRAY

#include <iostream>
#include <array>
#include <tuple>
#include <vector>

template<typename T>
class ndarray {

public:
    using shape_t = std::vector<size_t>;
    const int size;
    const shape_t shape;


private:

   std::array<T, shape[0]> 

};


#endif