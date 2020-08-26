#!/usr/bin/env
for n in 2 4 8 16 32 64 128 256
do 
mpirun -n $n ./build/bench
done