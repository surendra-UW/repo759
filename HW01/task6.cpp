#include<stdio.h>
#include<iostream>
#include<string>
#include <cstdlib>


int main(int argc, char * argv[]) { 
    int N = std::stoi(argv[1]);
    for(int i=0;i<N;i++){
        printf("%d ", i);
    }
    printf("%d\n", N);

    for(int i=N;i>0;i--){
        std::cout<<i<<" ";
    }
    std::cout<<"0"<<std::endl;
    return 0;
}
