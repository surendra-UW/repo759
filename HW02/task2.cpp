#include<stdio.h>
#include<string>
#include<random>
#include<chrono>
#include<iostream>
#include"convolution.h"

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main(int argc, char * argv[]) { 
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, milli> duration_sec;

    int n = stoi(argv[1]);
    int m = stoi(argv[2]);
    float *image = (float *)malloc(n*n*sizeof(float));
    float *output = new float[n*n];
    float *mask = (float *)malloc(m*m*sizeof(float));
    random_device rd;  // Seed generator
    mt19937 gen(rd()); 
    uniform_real_distribution<> distribution(-1.0, 1.0);

    for (int i =0;i<n*n;i++) {
        image[i] = 10.0f*distribution(gen);
    }

    for (int i =0;i<m*m;i++) {
        mask[i] = distribution(gen);
    }

    start = high_resolution_clock::now();
    convolve(image, output, n, mask, m);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);

    cout << duration_sec.count() << endl;
    cout<<output[0]<<endl;
    cout<<output[n*n-1]<<endl;

    free(image);
    delete[] output;
    free(mask);
    
    return 0;
}