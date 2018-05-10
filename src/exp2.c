/****************************************************************
 ** Practice send and recieve
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
  int world_rank, world_size;
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank); 
  for (i = 0; i < world_size; i++) {
    if (i != world_rank) {
      MPI_Send(
        &world_rank,
        1,
        MPI_INT,
        i,
        5,
      MPI_COMM_WORLD);
      //Define our recv buffer with predetermined value to test
      int recv_data = 100;
      MPI_Recv(
        &recv_data,
        1,
        MPI_INT,
        i,
        5,
        MPI_COMM_WORLD,
        &status);
      if (world_rank == 5)
        fprintf(stderr, "Received data: %i\n", recv_data);
    }
  
  }
	MPI_Finalize();
  return 0;
}
