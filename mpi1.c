#include <stdio.h>
#include <string.h>  
#include <mpi.h>     

int main(void) {
   int        comm_sz;               /* Número de processos    */
   int        my_rank;               /* Rank   do processo     */
   int        a = 2;
   int        b = 3;
   
  

   /* Inicia MPI */
   MPI_Init(NULL, NULL); 

   /* Obter número de processos */
   MPI_Comm_size(MPI_COMM_WORLD, &comm_sz); 

   /* Obter rank (id) do processo */
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 

   printf("Número de processos: %d Rank do processos corrente: %d \n", comm_sz, my_rank);
   if(my_rank != 0){
      int resultado = 0;
      if (my_rank == 1){
         int resultado = a+b;
         printf("a + b = %d\n",resultado);
         MPI_Send(&resultado, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); 
      }
         if (my_rank == 2){
         int resultado = b-a;
         printf("b - a = %d\n",resultado);
         MPI_Send(&resultado, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); 
      }
         if (my_rank == 3){
         int resultado = a*b;
         printf("a * b = %d\n",resultado);
         MPI_Send(&resultado, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); 
      }
         if (my_rank == 4){
         int resultado = a - b;
         printf("a - b = %d\n",resultado);
         MPI_Send(&resultado, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); 
      }
   }else{
      int resultado = 0;
      int final = 0;
      for (int q = 1; q < comm_sz; q++) {
        
         /* Recepção da mensagem do processo q */
         MPI_Recv(&resultado ,1, MPI_INT, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
         final+=resultado;

      } 
      printf("Soma de todos os resultados = %d ",final);
   }
   
   
   /* Encerra MPI */
   MPI_Finalize(); 

   return 0;
}  /* main */
