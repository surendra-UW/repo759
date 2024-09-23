#include<stdio.h>
#include <cstddef>
#include "scan.h"

void scan(const float *arr, float *output, std::size_t n){
    int size = static_cast<int>(n);
    output[0] = arr[0];
    for(int i=1;i<size;i++) {
        output[i] = arr[i] + output[i-1];
    }
}