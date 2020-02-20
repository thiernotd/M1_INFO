#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int main( int argc,char **argv)
{
  // MPI_Init( &argc,&argv);
MPI_Init( NULL,NULL);
   int nb_processus ;
   int identifiant;
   MPI_Comm_size(MPI_COMM_WORLD,&nb_processus);
   MPI_Comm_rank(MPI_COMM_WORLD,&identifiant);
   MPI_Status status;
  // int fin=0;
   int fils[nb_processus-1];
   int pere;
   int i;
   int j = 0;
   int msg;
    int c=0;

   if (identifiant == 0) {
     for (i = 1; i < nb_processus; i++) {
       MPI_Send(&identifiant,1,MPI_INT,i,0,MPI_COMM_WORLD);
     }
     int c = 2 * (nb_processus-1);
     while (c > 0) {
       MPI_Recv(&msg,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
       int id = status.MPI_SOURCE;
       int balise = status.MPI_TAG;
       if (balise == 0) {
         int accuse = 1;
         MPI_Send(&accuse,1,MPI_INT,id,1,MPI_COMM_WORLD);
         c--;
       }
       if (balise == 1) {
         c--;
       }
       if (balise == 2) {
         c = c - 2;
         fils[j]= id;
         j++;
       }
     }
     printf("Je suis la racine %d mes fils sont: ", identifiant);
     int k;
     for ( k = 0; k < j; k++) {
       printf("|%d|",fils[k] );
     } printf("\n");
   }else{
       MPI_Recv(&msg,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
       int id = status.MPI_SOURCE;
       pere=id;
       MPI_Send(&identifiant,1,MPI_INT,id,2,MPI_COMM_WORLD);
       int m = msg;
       for ( i = 0; i < nb_processus; i++) {
         if (i != id && i!= identifiant) {
           MPI_Send(&m,1,MPI_INT,i,0,MPI_COMM_WORLD);
           c++;
         }
       }
        c = 2 * c;
       while (c > 0) {
         MPI_Recv(&msg,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
         int id1 = status.MPI_SOURCE;
         int balise = status.MPI_TAG;
         if (balise == 0) {
           int accuse = 1;
           MPI_Send(&accuse,1,MPI_INT,id1,1,MPI_COMM_WORLD);
           c--;
         }
         if (balise == 1) {
           c--;
         }
         if (balise == 2) {
           c = c -2;
           fils[j]= id1;
           j++;
         }
       }
       printf("Je suis l\'entite %d mon pere c\'est %d et mes fils sont:  ", identifiant,pere);
       int k;
       for ( k = 0; k < j; k++) {
         printf("| %d |",fils[k] );
       }
       printf("\n");
     }


     if (j==0 && identifiant != 0) {
       MPI_Send(&identifiant,1,MPI_INT,pere,3,MPI_COMM_WORLD);
     }else{
       int taille;
       int M[nb_processus];
       M[0]=identifiant;
       int l,ck = 0;
       int *tab;
       while (j > 0) {
         MPI_Probe(MPI_ANY_SOURCE, 3, MPI_COMM_WORLD, &status);
         int  origine=status.MPI_SOURCE;
         MPI_Get_count(&status, MPI_INT, &taille);
         tab = malloc(taille * sizeof(int));
         MPI_Recv(tab,taille,MPI_INT,origine,3,MPI_COMM_WORLD,&status);
         int indice=0;
         for (l = ck+1 ; l <=  ck+taille; l++) {
           M[l] = tab[indice];
           indice++;
         }
         ck=ck+taille;
         j--;
       }
       if (identifiant != 0) {

         MPI_Send(&M,ck,MPI_INT,pere,3,MPI_COMM_WORLD);
       }else{
         for (i = 0; i < nb_processus; i++) {
           printf(" %d --",M[i] );
         }
       }
     }


   MPI_Finalize();
   return 0;
}
