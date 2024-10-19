#!/usr/bin/env zsh

#SBATCH -p instruction
#SBATCH -J task3b
#SBATCH -o task3b.out -e task3b.err
#SBATCH -N 1 -c 20
#SBATCH -t 0-00:10:00


g++ task3.cpp msort.cpp -Wall -O3 -std=c++17 -o task3 -fopenmp

for i in {1..20}; 
do 
./task3 1000000 $i 16
done

