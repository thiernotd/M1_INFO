#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int main( int argc,char **argv)
{
   MPI_Init( &argc,&argv);
   int nb_processus = 0;
   int identifiant = 0;
   MPI_Comm_size(MPI_COMM_WORLD,&nb_processus);
   MPI_Comm_rank(MPI_COMM_WORLD,&identifiant);


   int id_recv;
   MPI_Status status;
   int tab[2];

   if(identifiant == 0){
     tab[0] = rand() % 10 + 2;
     tab[1] = rand() % 10 + 1;
     MPI_Send(tab,2,MPI_INT,1,1,MPI_COMM_WORLD);
     MPI_Send(tab,2,MPI_INT,2,1,MPI_COMM_WORLD);
   }

   if (identifiant!=0) {
     id_recv = floor((identifiant-1)/2);
     MPI_Recv(tab,2,MPI_INT,id_recv,1,MPI_COMM_WORLD,&status);
    printf("je suis le noeud %d j'ai reçu (%d,%d)\n",identifiant,tab[0],tab[1] );

   }

   if (2*identifiant+1 < nb_processus) {
     MPI_Send(tab,2,MPI_INT,2*identifiant+1,1,MPI_COMM_WORLD);

   }
   if (2*identifiant+2 < nb_processus) {
     MPI_Send(tab,2,MPI_INT,2*identifiant+2,1,MPI_COMM_WORLD);
   }

   MPI_Finalize();
   return 0;
}
