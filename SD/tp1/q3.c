#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"


int main(int argc, char const *argv[]) {

  MPI_Init(NULL,NULL);
  int nb_processus;
  int identifiant;
  MPI_Comm_size(MPI_COMM_WORLD,&nb_processus);
  MPI_Comm_rank(MPI_COMM_WORLD,&identifiant);
  double w_time =  MPI_Wtime();

  printf("identifiant N %d  temps ecouler %f\n", identifiant, (MPI_Wtime()-(w_time)));
  
  MPI_Finalize();
  
  return 0;
}
