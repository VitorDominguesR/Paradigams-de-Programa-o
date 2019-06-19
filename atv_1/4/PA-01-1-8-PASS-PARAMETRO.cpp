#include<stdio.h>

void SomaUm(int x, int*y)
{ x = x+1;
  *y = (*y)+1;
  printf("Funcao SomaUm: %d %d\n", x,*y);
}

int main()
{ int a=0, b=0;
  SomaUm(a,&b);
  printf("Programa principal: %d %d\n", a,b);
  return(0);
}
