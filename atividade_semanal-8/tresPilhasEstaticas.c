/******************************************************************************
//     duasPilhasEstaticas.c
// Este programa gerencia duas pilhas implementadas em um arranjo
   (implementacao estatica).
// As pilhas gerenciadas podem ter um numero de no maximo MAX elementos (juntas).
// N�o usaremos sentinela nesta estrutura.
******************************************************************************/
#include <stdio.h>
#define true 1
#define false 0
#define MAX 6

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO A[MAX];
  int topo1;
  int base2;
  int topo2;
  int topo3;
} PILHATRIPLA;


/* Inicializa��o da PILHATRIPLA (a PILHATRIPLA jah esta criada e eh apontada 
pelo endereco em p) */
void inicializarPilhaTripla(PILHATRIPLA* p){
  p->topo1 = -1;
  p->base2 = MAX/3;
  p->topo2 = p->base2-1;
  p->topo3 = MAX;
} /* inicializarPILHATRIPLA* /


/* Retornar o tamanho da PILHATRIPLA (numero de elementos das duas somadas) */
int tamanhoPilhaTripla(PILHATRIPLA* p) {
  return p->topo1 + MAX - p->topo3 + p->topo2 - p->base2 + 2;
} /* tamanhoPILHATRIPLA* /

/* Retornar o tamanho de uma das pilhas */
int tamanhoUmaPilha(PILHATRIPLA* p, int pilha) {
  if (pilha < 1 || pilha > 3) return -1;
  if (pilha == 1) return p->topo1+1;
  else if (pilha == 2) return p->topo2 - p->base2 + 1;
  return MAX-p->topo3;
} /* tamanhoUmaPilha */

/* Exibi��o de uma das pilhas */
void exibirUmaPilha(PILHATRIPLA* p, int pilha){
  if (pilha < 1 || pilha > 3) return;
  printf("Pilha %i: \" ", pilha);
  int i;
  if (pilha == 1) for (i=p->topo1;i>=0;i--) printf("%i ", p->A[i].chave);
  else if (pilha == 2) for (i=p->topo2;i>=p->base2;i--) printf("%i ", p->A[i].chave);
  else for (i=p->topo3;i<MAX;i++) printf("%i ", p->A[i].chave);
  printf("\"\n");
} /* exibirPilha */ 

/* Retornar o tamanho em bytes da pilha. Neste caso, isto nao depende do numero
   de elementos que estao sendo usados.   */
int tamanhoEmBytesPilha(PILHATRIPLA* p) {
  return sizeof(PILHATRIPLA);
} /* tamanhoEmBytes */

void reinicializarPilha(PILHATRIPLA* p) {
  p->topo1 = -1;
  p->base2 = MAX/3;
  p->topo2 = p->base2-1;
  p->topo3 = MAX;
}

/* Destrui��o da pilha */
void reinicializarPilha2(PILHATRIPLA* p) {
     inicializarPilhaTripla(p);
} /* destruirPilha */

/* Desloca a pilha 2 uma posi��o � esquerda */
bool deslocarAEsquerda(PILHATRIPLA* p){
   if (p->base2==p->topo1+1) return false;
   int x;
   for (x=p->base2; x<=p->topo2; x++) p->A[x-1] = p->A[x];
   p->base2--;
   p->topo2--;
   return true;     
} /* deslocarAEsquerda */


/* Desloca a pilha 2 uma posi��o � direita */
bool deslocarADireita(PILHATRIPLA* p){
   if (p->topo2==p->topo3-1) return false;
   int x;
   for (x=p->topo2; x>=p->base2; x--) p->A[x+1] = p->A[x];
   p->base2++;
   p->topo2++;
   return true;     
} /* deslocarAEsquerda */

/* inserirElementoPilha - insere elemento no fim da pilha   */
bool inserirElementoPilha(PILHATRIPLA* p, REGISTRO reg, int pilha){
   if (pilha < 1 || pilha > 3) return false;
   if (tamanhoPilhaTripla(p) == MAX) return false;
   if (pilha == 1) {
       if (p->topo1 == p->base2-1) deslocarADireita(p);
       p->topo1 = p->topo1+1;
       p->A[p->topo1] = reg;
   }else if(pilha==2){
       if (p->topo2 == p->topo3-1) deslocarAEsquerda(p);
       p->topo2++;
       p->A[p->topo2] = reg;
   }else{
       if (p->topo2 == p->topo3-1) deslocarAEsquerda(p);
       p->topo3 = p->topo3-1;
       p->A[p->topo3] = reg;        
   }
   return true;
} /* inserirElementoPilha */


/* excluirElementoPilha - copia para o endere�o reg e exclui o registro do topo
 da pilha solicitada e retorna true; 
 ou retorna false se nao houver elemento a ser retirado na respectiva pilha */
bool excluirElementoPilha(PILHATRIPLA* p, REGISTRO* reg, int pilha){
  bool resposta = false;

  if (!(1 <= pilha && pilha <= 3)) return resposta;

  switch (pilha) {
    case 1:
      if (p->topo1 >= 0) {
        *reg = p->A[p->topo1];
        p->topo1--;
        resposta = true;
      }
      break;
    case 2:
      if (p->topo2 >= p->base2) {
        *reg = p->A[p->topo2];
        p->topo2--;
        resposta = true;
      }
      break;
    case 3:
      if (p->topo3 <= MAX - 1) {
        *reg = p->A[p->topo3];
        p->topo3++;
        resposta = true;
      }
  }

  return resposta;
} /* excluirElementoPilha */

/* retornarPrimeiroPilha
retorna a posicao do primeiro (topo) elemento da pilha e o valor de sua chave no 
conteudo do endereco ch. Retorna -1 caso a lista esteja vazia */
int retornarPrimeiroPilha(PILHATRIPLA* p, TIPOCHAVE* ch, int pilha){
  if (pilha < 1 || pilha > 3) return -1;
  if (pilha == 1){
    if (p->topo1==-1)return -1;
    *ch = p->A[p->topo1].chave;
    return p->topo1;
  }else if (pilha == 2){
    if (p->topo2<p->base2)return -1;
    *ch = p->A[p->topo2].chave;
    return p->topo2;
  }else{
    if (p->topo3==MAX)return -1;
    *ch = p->A[p->topo3].chave;          
    return p->topo3;
  }
}
