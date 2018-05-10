/****************************************************************
 **** Experiment #3 - Send & Recieve
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

void linspace(int min, int max, int *arr) {
  int i;
  for (i = min; i <= max; i++) {
    *(arr + i) = i;
  }
}

int main(int argc,char **argv) {

  int i;
  int world_rank, world_size, target, source;
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank); 
  source = world_rank;
  for (i = world_rank; i < world_rank+world_size; i++) {
    target = i+1;
    source = source-1;
    if (target >= world_size) 
      target = target - world_rank;
    if (source <= 0) 
      source = world_size - 1;
    fprintf(stderr, "Target: %i, World rank: %i, Source: %i\n", target, world_rank, source);
    MPI_Send(
      &world_rank,
      1,
      MPI_INT,
      target,
      5,
    MPI_COMM_WORLD);
    //Define our recv buffer with predetermined value to test
    int recv_data = 100;
    MPI_Recv(
      &recv_data,
      1,
      MPI_INT,
      source,
      5,
      MPI_COMM_WORLD,
      &status);
    if (world_rank == 7) 
      fprintf(stderr, "Received data from: %i, World rank: %i\n", recv_data, world_rank);
  }
  /*Print out the results for one node only, the rest are silent. Iterates thru a list and sends/recieves based off of index*/
	MPI_Finalize();
  return 0;
}
