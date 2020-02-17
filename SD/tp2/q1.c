#include <stdio.h>
#include "mpi.h"

int main( int argc,char **argv)
{
  MPI_Init( &argc,&argv);
  int nb_processus = 0;
  int identifiant = 0;
  MPI_Comm_size(MPI_COMM_WORLD,&nb_processus);
  MPI_Comm_rank(MPI_COMM_WORLD,&identifiant);

  if (identifiant =!0) {
        MPI_Recv(&nbr_recv,1,MPI_INT,1,1,MPI_COMM_WORLD,&status);
        printf("processus 0 : j\'envoi %d j\'ai reçu %d \n",nbr,nbr_recv );
  }
  if(identifiant           ){
        MPI_Recv(&nbr_recv,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        MPI_Send(&nbr_recv,1,MPI_INT,0,1,MPI_COMM_WORLD);
        printf("processus 1 : j\'ai reçu %d je renvoi %d \n",nbr_recv,nbr_recv );
      }
    }

  }
  MPI_Finalize();
  return 0;
}
