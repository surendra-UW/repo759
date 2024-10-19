#!/usr/bin/env zsh

#SBATCH -p instruction
#SBATCH -J task3a
#SBATCH -o task3a.out -e task3a.err
#SBATCH -N 1 -c 20
#SBATCH -t 0-00:10:00


g++ task3.cpp msort.cpp -Wall -O3 -std=c++17 -o task3 -fopenmp

for i in {1..10}; 
do 
ts=$((2**i))
./task3 1000000 8 $ts
done

