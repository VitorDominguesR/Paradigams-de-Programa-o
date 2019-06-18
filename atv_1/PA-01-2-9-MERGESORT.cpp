#include<stdio.h>
typedef int Vetor[10];

void Merge(Vetor A, int i, int m, int j){
  int temp;
  int k = i;
  int l = m+1;
  while(k<=m || l<=j) {
    if (A[k] <= A[l]) k++;
    else{
      temp = A[k];
      A[k] = A[l];
      A[l] = temp;
      l++;
    }
   
  }
}

void Mergesort(Vetor A, int i, int j)
{ int m;
  if (i < j)
  { m = (i + j - 1) / 2;
    Mergesort(A, i, m);  Mergesort(A, m + 1, j);
    Merge(A,  i,  m, j); /*Intercala A[i..m] e A[m+1..j] em A[i..j] */
  }
}

int main(){
  Vetor A;
  short i;
  for (i=0;i<10;i++) A[i] = 9-i;
  for (i=0;i<10;i++) printf ("A[%d] = %d ",i, A[i]);
  Mergesort(A,0,9);
  for (i=0;i<10;i++) printf ("A[%d] = %d ",i, A[i]);
  printf("\n");
  return 0;
}   

/* End. */
