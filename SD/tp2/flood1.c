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
   MPI_Status status;
   int *tab;

   if(identifiant == 0){
     int i;
     int t = rand() % 10 + 1;
     tab = malloc(t * sizeof(int));
     for ( i = 0; i < t; i++) {
        tab[i] = rand() % 10 + 1;
     }
     for ( i = 1; i < nb_processus; i++) {
       MPI_Send(tab,t,MPI_INT,i,1,MPI_COMM_WORLD);
     }
   }

   if (identifiant!=0) {

     int i;
     int j;
     int taille;
     MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
     MPI_Get_count(&status, MPI_INT, &taille);
     int  origine_id=status.MPI_SOURCE;
     int balise=status.MPI_TAG;
     tab = malloc(taille * sizeof(int));
     MPI_Recv(tab,taille,MPI_INT,origine_id,balise,MPI_COMM_WORLD,&status);

     for (i = 0; i < nb_processus; i++) {
       if (i!=origine_id && i!=identifiant) {
         MPI_Send(tab,taille,MPI_INT,i,balise,MPI_COMM_WORLD);
       }
     }

     printf("le noeud %d a reçu de la part de %d un message de taille %d :\n",identifiant,origine_id,taille );
     for (j = 0; j < taille; j++) {
       printf("\t %d\n",tab[j] );
     }

   }


   MPI_Finalize();
   return 0;
}
