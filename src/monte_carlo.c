/****************************************************************
 **** Calculates PI based off of a monte carlo simulation. Scaling is terrible. But the higher N is, the better. Scaling with N=10000000: 
  4  2.64s
  8  2.37s
  16 2.29s
  32 3.99s
 ****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

void main(int argc, char* argv[])
{
  int n = 10000000;
  double x,y;
  int i, world_rank, world_size, count;
  double z;
  double pi;
  srand(time(NULL));

	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank); 
  int starting_point = (int)( (double)n * (double)(world_rank)/world_size);
  int stopping_point = (int)( (double)n * (double)(world_rank+1.0)/world_size);
  
  //MPI_Scatter();
  //main loop
  if (world_rank == 0) {
    int count = 0;
  }
  MPI_Bcast(&count, 1, MPI_INT, 0, MPI_COMM_WORLD);
  for (i=starting_point; i<stopping_point; ++i)  {
    //get random points
    x = (double)random()/RAND_MAX;
    y = (double)random()/RAND_MAX;
    z = sqrt((x*x)+(y*y));
    //check to see if point is in unit circle
    if (z<=1)
    {
      ++count;
    }
  }
  int sum = 0; 
  MPI_Reduce(&count, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  if (world_rank == 0) {
    pi = ((float)sum/(float)n)*4.0;
    printf("Pi: %f\n", pi);
  }


}
