#include <stdio.h>
#include "mpi.h"

int main( int argc,char **argv)
{
  MPI_Init( &argc,&argv);
  int nb_processus = 0;
  int identifiant = 0;
  MPI_Comm_size(MPI_COMM_WORLD,&nb_processus);
  MPI_Comm_rank(MPI_COMM_WORLD,&identifiant);

  if (nb_processus == 2) {
    int nbr_recv;
    int nbr;
    MPI_Status status;
    int i ;
    int k =10;
    for (i = 0; i < k; i++) {
      if(identifiant == 0){
        nbr = 100;
        MPI_Send(&nbr,1,MPI_INT,1,1,MPI_COMM_WORLD);
        MPI_Recv(&nbr_recv,1,MPI_INT,1,1,MPI_COMM_WORLD,&status);

        printf("processus 0 : j\'envoi %d j\'ai reçu %d \n",nbr,nbr_recv );
      }

      if(identifiant == 1){
        MPI_Recv(&nbr_recv,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        MPI_Send(&nbr_recv,1,MPI_INT,0,1,MPI_COMM_WORLD);
        printf("processus 1 : j\'ai reçu %d je renvoi %d \n",nbr_recv,nbr_recv );
      }
    }

  }
  MPI_Finalize();
  return 0;
}
