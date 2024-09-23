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

int main(int argc, char * argv[]) { 
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, milli> duration_sec;

    uint32_t N = 1000;
    double *A = (double *)malloc(N*N*sizeof(double));
    double *B = (double *)malloc(N*N*sizeof(double));
    random_device rd;  // Seed generator
    mt19937 gen(rd()); 
    uniform_real_distribution<> distribution(-1.0, 1.0);

    for (unsigned int i=0;i<N*N;i++) {
        A[i] = distribution(gen);
        B[i] = distribution(gen);
    }

    //Matmul1
    double *C = new double[N*N];

    start = high_resolution_clock::now();
    mmul1(A, B, C, N);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    cout << duration_sec.count() << endl;
    cout<<C[N*N-1]<<endl;
    fill(C, C+N*N, 0.0);

    //Matmul2
    start = high_resolution_clock::now();
    mmul2(A, B, C, N);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    cout << duration_sec.count() << endl;
    cout<<C[N*N-1]<<endl;
    fill(C, C+N*N, 0.0);

    //Matmul3 
    start = high_resolution_clock::now();
    mmul3(A, B, C, N);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    cout << duration_sec.count() << endl;
    cout<<C[N*N-1]<<endl;
    fill(C, C+N*N, 0.0);

    //Matmul4 
    vector<double> vecA(A, A+N*N);
    vector<double> vecB(B, B+N*N);
    start = high_resolution_clock::now();
    mmul4(vecA, vecB, C, N);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);

    free(A);
    free(B);
    cout << duration_sec.count() << endl;
    cout<<C[N*N-1]<<endl;
    delete[] C;
    return 0;
}