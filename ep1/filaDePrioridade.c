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

typedef char CATEGORIA;

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

bool testaID(PFILA f, int id, CATEGORIA cat) {
  /* 
    Categorias:
    I: Inserção de elemento
    P: Alteração de prioridade
  */


  if (id < 0 || id >= f->maxElementos) return false;

  switch (cat) { // TODO: aprimorar este bloco
    case 'I': if (f->arranjo[id] != NULL) return false; else break;
    case 'P': if (f->arranjo[id] == NULL) return false; else break;
  }

  return true;
}

void corrigePonteiros(PONT ant, PONT meio, PONT pos, bool gap) {
  if (gap) {
    /* 
      Corrige o gap deixado pela antiga posição do elemento "meio",
      no caso de ele ter mudado de posição por conta de uma mudança de prioridade.
    */
    meio->ant->prox = meio->prox;
    meio->prox->ant = meio->ant;
  }

  ant->prox = meio;
  pos->ant = meio;
  meio->ant = ant;
  meio->prox = pos;
}

void buscaSeqInsercao(PFILA f, float prioridade, PONT* pParaPos, PONT* pParaAnt) {
  *pParaAnt = f->fila;
  *pParaPos = (*pParaAnt)->prox;

  while ((*pParaPos)->prioridade > prioridade && *pParaPos != f->fila) {
    *pParaAnt = *pParaPos;
    *pParaPos = (*pParaPos)->prox;
  }
}

bool inserirElemento(PFILA f, int id, float prioridade){
  bool resposta = false;

  if (!testaID(f, id, 'I')) return resposta;

  PONT pos;
  PONT ant;

  buscaSeqInsercao(f, prioridade, &pos, &ant);

  PONT novoElemento = (PONT) malloc(sizeof(ELEMENTO));

  f->arranjo[id] = novoElemento;

  novoElemento->id = id;
  novoElemento->prioridade = prioridade;

  corrigePonteiros(ant, novoElemento, pos, false);

  resposta = true;

  return resposta;
}

void buscaSeqPrioridade(PFILA f, PONT* pParaAnt, PONT escolhido, PONT* pParaPos, CATEGORIA cat) {
  *pParaAnt = escolhido->ant;
  *pParaPos = escolhido->prox;

  switch (cat) {
    case 'A':
      while ((*pParaAnt)->prioridade <= escolhido->prioridade) { 
        *pParaPos = *pParaAnt;
        *pParaAnt = (*pParaAnt)->ant;
      }
      break;
    case 'R':
      while ((*pParaPos)->prioridade >= escolhido->prioridade && *pParaPos != f->fila) { 
        *pParaAnt = *pParaPos;
        *pParaPos = (*pParaPos)->prox;
      }
  }  
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  bool resposta = false;

  if(!testaID(f, id, 'P') || f->arranjo[id]->prioridade >= novaPrioridade) return resposta;

  PONT escolhido = f->arranjo[id];

  escolhido->prioridade = novaPrioridade;

  // Seção para corrigir ponteiros

  PONT ant;
  PONT pos;

  buscaSeqPrioridade(f, &ant, escolhido, &pos, 'A');
  
  corrigePonteiros(ant, escolhido, pos, true);

  resposta = true;

  return resposta;
}



bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  bool resposta = false;

  if(!testaID(f, id, 'P') || f->arranjo[id]->prioridade <= novaPrioridade) return resposta;

  PONT escolhido = f->arranjo[id];

  escolhido->prioridade = novaPrioridade;

  // Seção para corrigir ponteiros

  PONT ant;
  PONT pos;

  buscaSeqPrioridade(f, &ant, escolhido, &pos, 'R');
  
  corrigePonteiros(ant, escolhido, pos, true);

  resposta = true;

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
  inserirElemento(f, 0, 40);
  inserirElemento(f, 4, 70);
  inserirElemento(f, 3, 78);
  exibirLog(f);
  aumentarPrioridade(f, 4, 500);
  exibirLog(f);
  aumentarPrioridade(f, 0, 7000);
  exibirLog(f);
  aumentarPrioridade(f, 4, 700);
  exibirLog(f);
  reduzirPrioridade(f, 4, 10);
  exibirLog(f);
}
