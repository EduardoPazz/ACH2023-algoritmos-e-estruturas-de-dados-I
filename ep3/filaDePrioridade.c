/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   94 - Prof. Luciano Antonio Digiampietri                       **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   João Eduardo da Paz Silva                   11884414          **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"

enum lado {esquerdo, direito};

PFILA criarFila(int max){
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->maxElementos = max;
  res->arranjo = (PONT*) malloc(sizeof(PONT)*max);
  res->heap = (PONT*) malloc(sizeof(PONT)*max);
  int i;
  for (i=0;i<max;i++) {
    res->arranjo[i] = NULL;
    res->heap[i] = NULL;
  }
  res->elementosNoHeap = 0;
  return res;
}



void exibirLog(PFILA f){
  printf("Log [elementos: %i]\n", f->elementosNoHeap);
  PONT atual;
  int i;
  for (i=0;i<f->elementosNoHeap;i++){
    atual = f->heap[i];
    printf("[%i;%f;%i] ", atual->id, atual->prioridade, atual->posicao);
  }
  printf("\n\n");
}

int tamanho(PFILA f){
  int tam = 0, i = 0;

  while (f->heap[i] != NULL) {
    tam++;
    i++;
  }
  
  return tam;
}

void maxHeapfy(PFILA f, PONT elemento) {
  // Nó Raiz não possui pai
  if (elemento->posicao == 0) return;

  int indicePai = (elemento->posicao - 1) / 2;

  if (elemento->prioridade > f->heap[indicePai]->prioridade) {
    PONT tmpNo = f->heap[indicePai];
    int tmpPosicao = elemento->posicao;

    // Coloca o ex-filho no lugar do pai
    f->heap[indicePai] = elemento;
    elemento->posicao = indicePai;

    // Coloca o ex-pai no lugar do filho
    f->heap[tmpPosicao] = tmpNo;
    tmpNo->posicao = tmpPosicao;

    maxHeapfy(f, elemento);
  }
}

bool inserirElemento(PFILA f, int id, float prioridade){
  bool res = false;
  
  // Condições de escape
  if (id < 0 || id >= f->maxElementos) return res;
  if (f->arranjo[id] != NULL) return res;
  
  // Aloca memória pro novo elemento
  PONT novoElemento = (PONT) malloc(sizeof(ELEMENTO));

  // Preenche os campos do novo elemento (a posição pode ser atualizada na função maxHeapfy)
  novoElemento->id = id;
  novoElemento->prioridade = prioridade;
  novoElemento->posicao = f->elementosNoHeap;
  /* printf("posicao: %i\n", f->elementosNoHeap); fflush(stdout); */
  // Atualiza informações da fila
  f->arranjo[id] = novoElemento;
  f->heap[f->elementosNoHeap] = novoElemento;
  (f->elementosNoHeap)++;  

  maxHeapfy(f, novoElemento);


  // Fim
  res = true;

  return res;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  /* COMPLETAR */
  
  return res;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  /* COMPLETAR */
  
  return res;
}

PONT removerElemento(PFILA f){
  PONT res = NULL;
  
  /* COMPLETAR */
  
  return res;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  bool res = false;
  
  /* COMPLETAR */
  
  return res;
}

