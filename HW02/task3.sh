#!/usr/bin/env zsh

#SBATCH -p instruction
#SBATCH -J task3
#SBATCH -o task3.out -e task3.err
#SBATCH -N 1 -c 2
#SBATCH -t 0-00:10:00

g++ task3.cpp matmul.cpp -Wall -O3 -std=c++17 -o task3
./task3
