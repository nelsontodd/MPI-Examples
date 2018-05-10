/****************************************************************
 **** Calculates PI based off of the trapezoidal rule. The more nodes and the higher N is, the better until nodes=16. That is the saturation point. Scaling with N=1000000000: 
  4  19.85s
  8  10.99s
  16 6.61s
  32 6.10s
 **** Overall much slower than monte carlo method.
 ***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

void main(int argc, char* argv[])
{
  int n = 1000000000;
  double x2;
  int i, world_rank, world_size;
  double pi, result;
  srand(time(NULL));

	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank); 
  int starting_point = (int)( (double)n * (double)(world_rank)/world_size);
  int stopping_point = (int)( (double)n * (double)(world_rank+1.0)/world_size);
  double d      = 1.0 / n;
  long double d2     = d*d;

  //init  
  for (i=starting_point; i<stopping_point; i+=1)
  {
    x2     = d2*i*i;
    result+=sqrt(1-x2);
  }
  result = d*result;

  MPI_Reduce(&result, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  if (world_rank == 0) {
    printf("Pi: %f\n", 4.0*pi);
  }


}
