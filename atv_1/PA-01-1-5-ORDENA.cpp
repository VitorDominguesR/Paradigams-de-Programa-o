#include <stdio.h>
#define n 10

typedef int TipoVetor[n];
TipoVetor A;
FILE *arq;
int i;

void Ordena(TipoVetor A)
{ /*ordena o vetor A em ordem ascendente*/
  int i, j, min,x;
  for (i = 1; i < n; i++) 
    { min = i;
      for (j = i + 1; j <= n; j++) 
	if ( A[j - 1] < A[min - 1] ) min = j;
      /*troca A[min] e A[i]*/
      x = A[min - 1];
      A[min - 1] = A[i - 1]; 
      A[i - 1] = x;
    }
} 

int main(int argc, char *argv[])
{
  arq = fopen("vetor.txt","r");
  printf("Vetor a ser pesquisado:\n\n");
  for (i = 1; i <= n; i++)
    { fscanf(arq, "%d", &A[i-1]);
      printf("%d\n", A[i-1]);
    }
  Ordena(A);
  printf("\nVetor ordenado: ");
  for (i = 1; i <= n; i++) printf("%d ", A[i - 1]);
  printf("\n");
  fclose(arq);
  return(0);
}  /* maxmin */
/* End. */
