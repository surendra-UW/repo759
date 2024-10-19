#include<iostream>
#include<cstdlib>
#include <omp.h>
#include "matmul.h"


void mmul(const float* A, const float* B, float* C, const std::size_t n){ 
    unsigned int i,j,k;
    #pragma omp parallel for private (i,j,k) shared(A,B,C)
    for(i=0;i<n;i++) {
        // #pragma omp parallel for 
        for (k=0;k<n;k++){
            for(j=0;j<n;j++) {
                // #pragma omp atomic
                C[i*n+j] += A[i*n+k]*B[k*n+j]; 
            }
        }
    }
}

void mmul2(const float* A, const float* B, float* C, const std::size_t n) {
    #pragma omp parallel for collapse(2)
    for(unsigned int i = 0; i < n; i++) {
        for(unsigned int j = 0; j < n; j++) {
            float sum = 0.0;
            for(unsigned int k = 0; k < n; k++) {
                sum += A[i*n + k] * B[k*n + j];
            }
            C[i*n + j] = sum;
        }
    }
}