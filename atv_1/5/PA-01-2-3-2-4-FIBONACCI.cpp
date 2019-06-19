#include<stdio.h>

unsigned int FibIter(unsigned int n)
{ unsigned int i = 1, k, F=0;
  for (k = 1; k <= n; k++)
    { F += i;  i = F - i;
    }
  return F;
}

unsigned int  FibRec(unsigned int n)
{ 
  if (n < 2) return n;
  else return (FibRec(n - 1) + FibRec(n - 2));
}

int main(int argc, char *argv[])
{ 
  printf("%d\n", FibIter(5));
  printf("%d\n", FibRec(5));
  return(0);
}
