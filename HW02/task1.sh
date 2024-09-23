#!/usr/bin/env zsh

#SBATCH -p instruction
#SBATCH -J task1b
#SBATCH -o task1b.out -e task1b.err
#SBATCH -N 1 -c 2
#SBATCH -t 0-00:10:00

g++ scan.cpp task1.cpp -Wall -O3 -std=c++17 -o task1b
./task1b 10000
