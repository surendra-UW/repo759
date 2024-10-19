#!/usr/bin/env zsh

#SBATCH -p instruction
#SBATCH -J task1
#SBATCH -o task1.out -e task1.err
#SBATCH -N 1 -c 20
#SBATCH -t 0-00:10:00


g++ task1.cpp matmul.cpp -Wall -O3 -std=c++17 -o task1 -fopenmp

for i in {1..20}; 
do 
./task1 1024 $i
done
