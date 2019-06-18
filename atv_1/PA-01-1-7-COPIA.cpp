#include <stdio.h>
#include <stdlib.h>
/* copia o arquivo Velho no arquivo Novo */

#define N 30
typedef char TipoAlfa[N];
typedef struct { int Dia; int Mes;} TipoData;
typedef struct {
  TipoAlfa Sobrenome, PrimeiroNome;
  TipoData Aniversario;
  enum { Mas, Fem } Sexo;
} Pessoa;

int main(int argc, char* argv[])
{
 FILE *Velho, *Novo;
  Pessoa Registro;
  if( (Velho = fopen(argv[1],"r")) == NULL )
  { printf("arquivo nao pode ser aberto\n");exit(1);
  }
  if( (Novo = fopen(argv[2],"w")) == NULL)
  { printf("arquivo nao pode ser aberto\n");exit(1);
  }
  while (fread(&Registro, sizeof(Pessoa), 1, Velho) > 0) 
    fwrite(&Registro, sizeof(Pessoa), 1, Novo);
  fclose(Velho);
  fclose(Novo);
  return (0);
} 
