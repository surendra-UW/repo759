#!/usr/bin/env zsh

#SBATCH -p instruction
#SBATCH -J task6
#SBATCH -o task6.out -e task6.err
#SBATCH -N 1 -c 2
#SBATCH -t 0-00:10:00

g++ task6.cpp -Wall -O3 -std=c++17 -o task6
./task6 6
