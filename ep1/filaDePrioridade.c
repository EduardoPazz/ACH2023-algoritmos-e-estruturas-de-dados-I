/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   Turma 94 - Prof. Luciano Antonio Digiampietri                 **/
/**                                                                 **/
/**   EP1 - Fila de Prioridade                                      **/
/**                                                                 **/
/**   João Eduardo da Paz Silva                   11845514          **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"

PFILA criarFila(int max){
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->maxElementos = max;
  res->arranjo = (PONT*) malloc(sizeof(PONT)*max);
  int i;
  for (i=0;i<max;i++) res->arranjo[i] = NULL;
  PONT cabeca = (PONT) malloc(sizeof(ELEMENTO));
  res->fila = cabeca;
  cabeca->ant = cabeca;
  cabeca->prox = cabeca;
  cabeca->id = -1;
  cabeca->prioridade = 1000000;
  return res;
}

void exibirLog(PFILA f){
  printf("Log [elementos: %i (alem do no cabeca)]\n", tamanho(f));
  PONT atual = f->fila;
  printf("%p[%i;%f;%p]%p \n", atual->ant, atual->id, atual->prioridade, atual, atual->prox);
  atual = atual->prox;
  while (atual != f->fila){
    printf("%p[%i;%f;%p]%p \n", atual->ant, atual->id, atual->prioridade, atual, atual->prox);
    atual = atual->prox;
  }
  printf("\nElementos validos: \n");
  atual = atual->prox;
  while (atual != f->fila){
    printf("[%i;%f;%p] \n", atual->id, atual->prioridade, atual);
    atual = atual->prox;
  }

  printf("\nValores do arranjo:\n\[ ");
  int x;
  for (x=0;x<f->maxElementos;x++) printf("%p ",f->arranjo[x]);
  printf("]\n\n");
}



int tamanho(PFILA f){
  int tam = 0;

  PONT jumper = f->fila->prox;

  while (jumper != f->fila) {
    tam++;
    jumper = jumper->prox;
  }

  return tam;
}

void buscaSeqExc(PFILA f, float prioridade, PONT* pToPos, PONT* pToAnt) {
  *pToAnt = f->fila;
  *pToPos = (*pToAnt)->prox;

  while ((*pToPos)->prioridade > prioridade && (*pToPos)->prioridade != f->fila->prioridade) {
    *pToAnt = *pToPos;
    *pToPos = (*pToPos)->prox;
  }
}

bool inserirElemento(PFILA f, int id, float prioridade){
  bool resposta = false;

  if (id < 0 || id >= f->maxElementos || f->arranjo[id] != NULL) return resposta; 

  PONT pos;
  PONT ant;

  buscaSeqExc(f, prioridade, &pos, &ant);

  PONT novoElemento = (PONT) malloc(sizeof(ELEMENTO));

  f->arranjo[id] = novoElemento;

  ant->prox = novoElemento;
  novoElemento->ant = ant;
  novoElemento->prox = pos;
  pos->ant = novoElemento;

  novoElemento->id = id;
  novoElemento->prioridade = prioridade;

  /* printf("(111) f: %p ant: %p pos: %p\n", f->fila, ant, pos); fflush(stdout); */

  resposta = true;

  return resposta;
}



bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  bool resposta = false;

  /* COMPLETAR */

  return resposta;
}



bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  bool resposta = false;

  /* COMPLETAR */

  return resposta;
}



PONT removerElemento(PFILA f){
  PONT resposta = NULL;

  /* COMPLETAR */

  return resposta;
}



bool consultarPrioridade(PFILA f, int id, float* resposta){
  bool resp = false;

  /* COMPLETAR */

  return resp;
}


void main() {
  PFILA f = criarFila(5);
  inserirElemento(f, 0, 5);
  inserirElemento(f, 4, 5);
  inserirElemento(f, 3, 5);
  exibirLog(f);
}