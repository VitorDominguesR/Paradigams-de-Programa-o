#include <stdio.h>
#define n 10

typedef int TipoVetor[n];
TipoVetor A;
FILE *arq;
int i;

void Ordena(int * a, int left, int right)
{ /*ordena o vetor A em ordem ascendente*/
  int i, j, x, y;
    
    /* Inicio vetor*/
    i = left;
    /* final do vetor */
    j = right;
    /*pivot */
    x = a[(left + right) / 2];
     
    while(i <= j) {/*enquanto eu não chegar no pivot (x) */
      /*verifico se numeros a esquerda maiores que o pivo e da direita menores que o pivot */
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        /*Faço a troca de valores entre a[i] que é maior que o pivot e a[j] que é menor que o pivot*/
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     /* Aqui ocorre a divisão em subvetores para ordenação das partes restantes  */
    if(j > left) {
        Ordena(a, left, j);
    }
    if(i < right) {
        Ordena(a, i, right);
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
  Ordena(A, 0, n - 1);
  printf("\nVetor ordenado: ");
  for (i = 1; i <= n; i++) printf("%d ", A[i - 1]);
  printf("\n");
  fclose(arq);
  return(0);
}  /* maxmin */
/* End. */
