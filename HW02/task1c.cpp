#include<stdio.h>
#include<string>
#include <random>
#include<chrono>
#include<iostream>
#include "scan.h"

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main(int argc, char * argv[]) { 
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, milli> duration_sec;

    for (int t =10;t<=30;t++) {
        int n = 1<<t;
        float *arr = (float *)malloc(n*sizeof(float));
        float *output = (float *)malloc(n*sizeof(float));
        random_device rd;  // Seed generator
        mt19937 gen(rd()); 
        uniform_real_distribution<> distribution(-1.0, 1.0);

        for (int i =0;i<n;i++) {
            arr[i] = distribution(gen);
        }

        start = high_resolution_clock::now();
        scan(arr, output, n);
        end = high_resolution_clock::now();

        // Convert the calculated duration to a double using the standard library
        duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
        free(arr);
        free(output);
        cout << t <<" " << duration_sec.count() << endl;
    }
    
    return 0;
}