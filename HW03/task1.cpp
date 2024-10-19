#include <omp.h>
#include<stdio.h>
#include<string>
#include<random>
#include<vector>
#include<chrono>
#include<algorithm>
#include<iostream>
#include "matmul.h"

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main(int argc, char *argv[]) {
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, milli> duration_sec;

    uint32_t N = stoi(argv[1]);
    int T = stoi(argv[2]);

    float *A = (float *)malloc(N*N*sizeof(float));
    float *B = (float *)malloc(N*N*sizeof(float));
    random_device rd;  // Seed generator
    mt19937 gen(rd()); 
    uniform_real_distribution<> distribution(-1.0, 1.0);

    for (unsigned int i=0;i<N*N;i++) {
        A[i] = distribution(gen);
        B[i] = distribution(gen);
    }

    //Matmul1
    float *C = new float[N*N];
    omp_set_num_threads(T);

    //Matmul2
    start = high_resolution_clock::now();
    mmul(A, B, C, N);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    cout<<C[0]<<endl;
    cout<<C[N*N-1]<<endl;
    cout << duration_sec.count() << endl;

    // fill(C, C+N*N, 0.0);

    // //Matmul3 
    // start = high_resolution_clock::now();
    // mmul2(A, B, C, N);
    // end = high_resolution_clock::now();

    // duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    // cout << duration_sec.count() << endl;
    // cout<<C[N*N-1]<<endl;

    free(A);
    free(B);

    delete[] C;
    return 0;
}