#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"


int main(int argc, char const *argv[]) {
  MPI_Init(NULL,NULL);
  int nb_processus;
  int identifiant;
  char c;
  MPI_Comm_size(MPI_COMM_WORLD,&nb_processus);
  MPI_Comm_rank(MPI_COMM_WORLD,&identifiant);
  if(nb_processus == 2){
    if (identifiant =0){
      MPI_Send(&identifiant,1,MPI_INT,1,1,MPI_COMM_WORLD);
      c = MPI_Recv(&identifiant,1,MPI_INT,0,2,MPI_COMM_WORLD,MPI_Status);
      printf("%s\n",c);
    }

   if(identifiant= 1){
     MPI_Recv(&identifiant,1,MPI_INT,0,1,MPI_COMM_WORLD,MPI_Status);
     MPI_Send(&identifiant,1,MPI_INT,1,1,MPI_COMM_WORLD);
   }
  }
  else
    return 0;



  return 0;
}
