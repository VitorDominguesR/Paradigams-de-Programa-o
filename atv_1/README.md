# 1

## O que esse programa  faz? 

---
## Qual é a entrada? 
A entrada é o arquivo vetor.txt

arq = fopen("vetor.txt","r");


---
## Qual é o resultado (saída)? 
A saída é
o print de cada número com o vetor de forma decimal
```
  for (i = 1; i <= N; i++) 
                { fscanf(arq, "%d", &A[i-1]);
        printf("%10d\n", A[i-1]); 
                }
```
e a chave de maior valor

Vetor a ser pesquisado:

        50
        30
         0
        40
        21
        99
       100
         2
         9
        65

Chave de maior valor = 100


---
## Encontrou algum erro? Se encontrou, conserte-o!

---
## Qual a complexidade assintótica de pior caso (tempo e espaço)?

complexidade assintótica: O(n)

---
## Cite duas  características  quedefinem  esse  código  como  de paradigma de  programação imperativo?Justifique  suas respostas.

Alguns elementos da programação imperativa presentes no código são:

Definição de tipos de dados

Esse código possui declaração explicita do tipo de dado ao qual aquela variavel se refere
typedef int TipoVetor[N];
TipoVetor A;
FILE *arq;
int i, Maxi;
int Max(TipoVetor A)


Expressões e atribuições
Nesse código, conseguimos modificar os valores de variaveis, eliminando o antigo e atribuindo um novo
Maxi = Max(A);
Temp = A[i]



---

# 2

*Estude e analise o código.* Compile e execute. 

---
## O que esse programa faz? 

No método principal main, ele passa a referencia do endereço de memória do vetor de inteiros dentro do arquivo vetor.tx para a função MaxMin3 e essa função aloca o maior e menor valor dentro das referencias de memorias passadas para a função.

---
## Qual é a entrada? 

os valores dentro do arquivo vetor.txt

---

## Qual é o resultado (saída)? Encontrou algum erro? Se encontrou, conserte-o! 

Saída

```
Vetor a ser pesquisado:

        50
        30
         0
        40
        21
        99
       100
         2
         9
        65

Chave de maior valor = 100
Chave de menor valor = 0
```

---
## Qual a complexidade assintótica de pior caso (tempo e espaço)?

O(n²)

---
## Cite três características  quedefinem  esse  código  como  de paradigma de  programação imperativo?

Ele utiliza variaveis, executa os procedimentos sequencialmente e utiliza comando de atribuição e repetição para leitura dos valores e execução de tarefas

---
## Qual a  diferença de propósito entre  este  programa  e  aquele  da  questão  anterior?  O  que  foi  modificado no código(estruturas  de  dados, comandos, etc.?)para ter-se o novo propósito? Justifique suas respostas. 

No primeiro, ele possui uma função chamada Max que armazenava o primeiro número do vetor e verificava se os próximos eram maiores ou não, se fossem ele era colocado na váriavel Temp, se não ele continuava para o próximo item e no final ele retirnava o valor utilizado na variavel Temp

No segundo caso a primeira modificação mais notável foi o uso de ponteiros indicando as regios de memória para as variaveis Min e Max. Nesse caso o nome da função também foi alterado para MinMax3.

No começo da função confesso que não entendi muito bem o pq ele fazia, então fui pesquisar e vi que ele faz um "bitwise and" para verificar se o tamanho do vetor é adequado a quantidade de número do arquivo vertor.txt, caso fosse maior, ele replicava o último numero para a ultima posição que provavelmente só teria um valor aleatório e dentro do espaço de memória alocado e interferiria no resultado.

Passando isso, ele executa a instrução while para percorrer o vetor e caso o número anterior da possição atual do vetor for maior que o da posição atual ele verifica se é maior ou menor que o mínimo já alocado nos ponteiros.

Duas coisas que não entendi foi o laço while começando em i=3 e o bitwise no começo

---

# 3

*Estude e analise o código.* Compile e execute. 

---
## O que esse programa faz? 

Ordena os valores contidos no arquivo vetor.txt

---
## Qual é a entrada? 

os valores dentro do arquivo vetor.txt

---

## Qual é o resultado (saída)? Encontrou algum erro? Se encontrou, conserte-o! 

Saída

```
Vetor a ser pesquisado:

50
30
0
40
21
99
100
2
9
65

Vetor ordenado: 0 2 9 21 30 40 50 65 99 100
```

---
## Qual a complexidade assintótica de pior caso (tempo e espaço)?

O(n²)

---
## Cite três características  quedefinem  esse  código  como  de paradigma de  programação imperativo?

Ele utiliza variaveis, executa os procedimentos sequencialmente e utiliza comando de atribuição e repetição para leitura dos valores e execução de tarefas

---
## Considerando o propósito identificado por você, seria possível realiza-lo de forma mais eficiente (i.e., menor complexidade)? Em caso positivo, reescreva esse código da forma mais eficiente imaginada por você. Essa nova forma ainda se conforma ao paradigma de programação imperativo?

Dado o propósito de ordenação de um vetor com entradas aleatórias do ponto de vista de ordem, pesquisando achei o algoritimo quicksort que foi implementado com o código a seguir

```
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
```
Essa nova forma não segue totalmente a forma imperativa, pois também recorre a recursão, caracteristica da linguagem funcional
