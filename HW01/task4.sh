#!/usr/bin/env zsh

#SBATCH -p instruction
#SBATCH -J FirstSlurm
#SBATCH -o FirstSlurm.out -e FirstSlurm.err
#SBATCH -N 1 -c 2
#SBATCH -t 0-00:10:00
echo $HOSTNAME
