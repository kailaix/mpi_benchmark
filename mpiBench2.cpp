#include <mpi.h>
#include <stdio.h>
#include <vector>
int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);
    double t0 = MPI_Wtime();
    int nranks;
    MPI_Comm_size(MPI_COMM_WORLD, &nranks);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int N = (1024*1024*128) / nranks;
    std::vector<double> v(N, (double)rank);
    double s;
    for(int i = 0; i < N; i++) s += v[i];
    double total = 0.0;
    MPI_Allreduce(&s, &total, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
    double total_ref = ((double)N) * ( ((double)nranks) * ( ((double)nranks) - 1.0) / 2.0);
    t0 = MPI_Wtime() - t0;
    if (rank==0)
        printf("[nranks = %d] total = %e ref = %e time = %0.4f sec\n", nranks, total, total_ref, t0);
    // Finalize the MPI environment.
    MPI_Finalize();
}