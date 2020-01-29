#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main( int argc,char **argv)
{
   MPI_Init( &argc,&argv);
   int nb_processus = 0;
   int identifiant = 0;
   MPI_Comm_size(MPI_COMM_WORLD,&nb_processus);
   MPI_Comm_rank(MPI_COMM_WORLD,&identifiant);

   if (nb_processus == 2) {

     int id_recv;
     MPI_Status status;
     int nbr;

     if(identifiant == 0){
	nbr=100;
       MPI_Send(&nbr,1,MPI_INT,1,1,MPI_COMM_WORLD);
       MPI_Recv(&id_recv,1,MPI_INT,1,1,MPI_COMM_WORLD,&status);
       printf("je suis le processus no %d, j'ai recu le message  %d\n",identifiant, id_recv );
     }

     if(identifiant == 1){
	nbr=200;
     	MPI_Send(&nbr,1,MPI_INT,0,1,MPI_COMM_WORLD);
     	MPI_Recv(&id_recv,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
      printf("je suis le processus no %d, j'ai recu le message  %d\n",identifiant, id_recv );
    }
 }
   MPI_Finalize();
   return 0;

}



