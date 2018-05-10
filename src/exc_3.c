/****************************************************************
 **** MPI Exercise
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc,char **argv) {

  char name[MPI_MAX_PROCESSOR_NAME];
  int resultlen;
  fprintf(stderr, "Processor name: %s\n", name);
  fprintf(stderr, "Before MPI\n");
  MPI_Init(&argc, &argv);
  fprintf(stderr, "Inside of MPI\n");
  MPI_Get_processor_name(name, &resultlen);
  fprintf(stderr, "Processor name: %s\n", name);
  MPI_Finalize();
  fprintf(stderr, "After MPI\n");
  /*This will print Hello world! \n 32 times when ran with mpiexec because I requested 32 nodes.*/
}
