#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

void main(int argc, char **argv ) { 
  int mytid, ntids;
	int randomfraction;
  MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&ntids);
	MPI_Comm_rank(MPI_COMM_WORLD,&mytid); 
	
  // Initialize the random number generator
  srand((int)(mytid*(double)RAND_MAX/ntids));
  // compute a random number
  randomfraction = (rand() / (double)RAND_MAX);

  fprintf(stderr,"ntids : %i\n",ntids);
  fprintf(stderr,"Random Fraction: %f\n",randomfraction);
  fprintf(stderr,"Random Fraction: %f\n",RAND_MAX);
	MPI_Finalize();

}
