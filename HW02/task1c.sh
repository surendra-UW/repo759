#!/usr/bin/env zsh

#SBATCH -p instruction
#SBATCH -J task1c
#SBATCH -o task1c.out -e task1c.err
#SBATCH -N 1 -c 2
#SBATCH -t 0-00:10:00

g++ scan.cpp task1c.cpp -Wall -O3 -std=c++17 -o task1c
./task1c
