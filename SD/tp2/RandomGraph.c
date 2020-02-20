#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#define  d 8
int main( int argc,char **argv)
{
   MPI_Init( &argc,&argv);
   int nb_processus = 0;
   int identifiant = 0;
   MPI_Comm_size(MPI_COMM_WORLD,&nb_processus);
   MPI_Comm_rank(MPI_COMM_WORLD,&identifiant);
   MPI_Status status;
   int *tab = malloc(d * sizeof(int));
   int cpt=0;
   int t,t2;
   int i=0;
   int blean=0;
   //if(identifiant == 0){
     while ( cpt < d ) {
       t = rand() % nb_processus ;
       i=0;
       blean=  inTable(tab , t );

       if (t != identifiant && blean==0) {
         tab[cpt]=t;
         cpt++;
       }
     }

     for (i = 0; i < nb_processus; i++) {
       if (inTable(tab,i)== 1 && i !=identifiant ) {
         MPI_Send(&identifiant,1,MPI_INT,tab[i],0,MPI_COMM_WORLD);
       }else{
         MPI_Send(&identifiant,1,MPI_INT,tab[i],1,MPI_COMM_WORLD);
       }
     }
int size = d;
  int  origine_id;
  int balise;
  int voisin;
     for (i = 0; i < nb_processus-1; i++) {

        MPI_Recv(&voisin,1,MPI_INT,MPI_ANY_SOURCE, MPI_ANY_TAG,MPI_COMM_WORLD,&status);
         origine_id=status.MPI_SOURCE;
         balise=status.MPI_TAG;
       if (balise==0 && inTable(tab,origine_id)== 0) {
         tab = realloc(tab, size+1 * sizeof(int));
         tab[size]= voisin;
         size ++;
       }
     }


     printf(" tab de %d :",identifiant );
     for (i = 0; i < d; i++) {
       printf(" %d", tab[i]);
     }
     printf("\n");
   //}*/


   MPI_Finalize();
   return 0;
}

int inTable(int * tab , int val ){

  int i = 0;
  int blean=0;

  while(blean == 0 && i < d){
    if(tab[i] == val){
      blean = 1;
    }
    i++;
  }
return blean;
}
