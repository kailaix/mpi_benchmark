#!/usr/bin/env bash
for n in 2 4 8 16 32 64 128 256
do 
/opt/ohpc/pub/compiler/intel-18/compilers_and_libraries_2018.2.199/linux/mpi/intel64/bin/mpirun -n $n ./build/bench
done
