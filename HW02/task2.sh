#!/usr/bin/env zsh

#SBATCH -p instruction
#SBATCH -J task2
#SBATCH -o task2.out -e task2.err
#SBATCH -N 1 -c 2
#SBATCH -t 0-00:10:00

g++ convolution.cpp task2.cpp -Wall -O3 -std=c++17 -o task2
./task2 4 3
