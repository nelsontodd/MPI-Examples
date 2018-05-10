/****************************************************************
 ****
 **** This program file is part of the book 
 **** `Parallel programming with MPI and OpenMP'
 **** by Victor Eijkhout, eijkhout@tacc.utexas.edu
 ****
 **** copyright Victor Eijkhout 2012-7
 ****
 **** MPI Exercise
 ****
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc,char **argv) {

	int world_size;
	int world_rank;
	int irec = 5;
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank); 
	if (world_rank == 0) {
		fprintf(stderr,"Current Process Rank: %i\n",world_rank);
		fprintf(stderr,"Sending to 1\n");
		MPI_Send(&world_rank,1,MPI_INT,1,9,MPI_COMM_WORLD); 
	}
	if (world_rank == 1) {
		fprintf(stderr,"irec: %i\n",irec);
		fprintf(stderr,"Current Process Rank: %i\n",world_rank);
		fprintf(stderr,"Recieving from 0. \n");
		MPI_Recv(&irec,1,MPI_INT,0,9,MPI_COMM_WORLD,&status); 
		fprintf(stderr,"irec: %i\n",irec);
	}
	MPI_Finalize();
  
  	return 0;
}
