#include <stdio.h>
#include <omp.h>

void openMP1() {
    #pragma omp parallel
    {
        printf("Oi mundo! Sou a thread %d \n", omp_get_thread_num());
    }
}

void openMP2() {
    #pragma omp parallel
    {
        printf("Sou a thread %d \n", omp_get_thread_num());
        for (int i = 0; i < 3; i++)
          printf("i = %d \n", i);
    }
}

int main(){
    long LIMITE_MAX = 2000000;
    double initial = omp_get_wtime();
    printf("Região sequencial 1. Thread master.  Número de threads: %d\n", omp_get_num_threads());
    printf("Numero de processadores: %d\n", omp_get_num_procs());
    printf("Entrando na primeira região paralela...\n");

    openMP1();

    printf("Fim da primeira região paralela...\n");

    printf("\nRegião sequencial 2. Thread master. Número de threads: %d\n", omp_get_num_threads());
    printf("Numero de processadores: %d\n", omp_get_num_procs());
    printf("Entrando na segunda região paralela...\n");

    openMP2();

    printf("Fim da segunda região paralela...\n");
    printf("\nRegião sequencial 3. Thread master. Número de threads: %d\n", omp_get_num_threads());
    printf("Numero de processadores: %d\n", omp_get_num_procs());
    printf("Terminando o programa...\n");
    double end = omp_get_wtime();
    
    if (LIMITE_MAX <= 1)
    soma = 0;
  else {
    soma = 1;
 
	#pragma omp parallel for private (contaPrimo) reduction(+:soma) schedule (dynamic,MAX_CHUNK)
    for (n = 3; n < LIMITE_MAX; n += 2){
      contaPrimo = ehPrimo(n);
      #pragma omp critical
      soma = soma + contaPrimo;
    }
  }
    double time = end - initial;
    printf("Número total de primos: %ld\n", soma);
    
    printf("É dificil ser humilde quando se é o melhor.\n");
    return 0;
}
