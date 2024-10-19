#include<stdio.h>
#include<string>
#include<random>
#include<chrono>
#include<iostream>
#include <omp.h>
#include"msort.h"

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main(int argc, char * argv[]) { 
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, milli> duration_sec;

    int n = stoi(argv[1]);
    int T = stoi(argv[2]);
    int ts = stoi(argv[3]);
    int *arr = (int *)malloc(n*sizeof(int));

    random_device rd;  // Seed generator
    mt19937 gen(rd()); 
    uniform_real_distribution<> distribution(-1000, 1000);
    omp_set_num_threads(T);
    for (int i =0;i<n;i++) {
        arr[i] = static_cast<int> (distribution(gen));
    }

    start = high_resolution_clock::now();
    msort(arr, n, ts);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);

    cout<<arr[0]<<endl;
    cout<<arr[n-1]<<endl;
    cout << duration_sec.count() << endl;


    free(arr);
    return 0;
}