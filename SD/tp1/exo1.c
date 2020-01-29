#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"


int main(int argc, char const *argv[]) {
  MPI_Init(NULL,NULL);
  int nb_processus;
  int identifiant
  MPI_Comm_size(MPI_COMM_WORLD,&nb_processus);
  MPI_Comm_rank(MPI_COMM_WORLD,&identifiant);

  printf("salut\n");
  MPI_Finalize();
  return 0;
}
