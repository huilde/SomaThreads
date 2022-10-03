// C Program to multiply two matrix using pthreads without
// use of global variables
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<iostream>

#define MAX 3

int NUM_THREADS = 3;
int NUM_P = 4;


int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];

int linha = 0;
int coluna = 0;
int algo = 0;
void* tarefa(void *tid)
{
    int QuantosCalcular = 0; 
      printf("\nThread\n");
      printf("%d",((int)(size_t) tid));
      for( linha ; linha < MAX; ++linha){
        if(QuantosCalcular==NUM_P){
            break;
        }
        for(algo  ; algo < MAX; ++algo){
             if(QuantosCalcular==NUM_P){
            break;
        }
            for(coluna = 0 ; coluna < MAX; ++coluna)
            {
                matC[linha][algo] += matA[linha][coluna] * matB[coluna][algo];
            }
        printf("%d", algo);
        printf("\n");
        QuantosCalcular++;
}
}
}



int main()
{
    int r1=MAX,c1=MAX,r2=MAX,c2=MAX,i,j,k;

    // Generating random values in matA
    for (i = 0; i < r1; i++)
            for (j = 0; j < c1; j++)
                   matA[i][j] = rand() % 10;
           
        // Generating random values in matB
    for (i = 0; i < r1; i++)
            for (j = 0; j < c1; j++)
                   matB[i][j] = rand() % 10;
    
    pthread_t threads[NUM_THREADS];
   printf("Inicio das Threads...\n");
   
    // inicia as  threads, passando como parametroa thread e a função que cada uma deve executar
   for (size_t i = 0; i < NUM_THREADS; i++)
   {
    pthread_create(&threads[i], NULL, tarefa, NULL);

   }

   
    // faz com que a thread principal espere as threads acabarem;

 for (size_t i = 0; i < NUM_THREADS; i++)
   {
    pthread_join(threads[i], NULL);
   }
    
    printf("resultado da tabela 3\n");

    
        for(int i = 0;i<MAX; i++){
                for(int j= 0; j<MAX;j++){
              printf("%i\t  ",matC[i][j]);
                }
                printf("\n");
        }
    exit(0);
}