/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   94 - Prof. Luciano Antonio Digiampietri                       **/
/**                                                                 **/
/**   EP2 - Fila Preferencial                                       **/
/**                                                                 **/
/**   João Eduardo da Paz Silva                   11845514          **/
/**                                                                 **/
/*********************************************************************/

#include "filapreferencial.h"

PFILA criarFila(){
  PFILA res = (PFILA) malloc(sizeof(FILAPREFERENCIAL));
  res->inicioPref = NULL;
  res->fimPref = NULL;
  res->inicioGeral = NULL;
  res->fimGeral = NULL;
  return res;
}

int tamanho(PFILA f){
  PONT atual = f->inicioGeral;
  int tam = 0;
  while (atual) {
    atual = atual->prox;
    tam++;
  }
  return tam;
}

int tamanhoFilaPreferencial(PFILA f){
  PONT atual = f->inicioPref;
  int tam = 0;
  while (atual) {
    atual = atual->prox;
    tam++;
  }
  return tam;
}

PONT buscarID(PFILA f, int id){
  PONT atual = f->inicioGeral;
   while (atual) {
    if (atual->id == id) return atual;
    atual = atual->prox;
  }
  return NULL;
}

void exibirLog(PFILA f){
  int numElementos = tamanho(f);
  printf("\nLog fila geral [elementos: %i] - Inicio:", numElementos);
  PONT atual = f->inicioGeral;
  while (atual){
    printf(" [%i;%i]", atual->id, atual->ehPreferencial);
    atual = atual->prox;
  }
  printf("\n");
  numElementos = tamanhoFilaPreferencial(f);
  printf("\nLog fila preferencial [elementos: %i] - Inicio:", numElementos);
  atual = f->inicioPref;
  while (atual){
    printf(" [%i;%i]", atual->id, atual->ehPreferencial);
    atual = atual->prox;
  }
  printf("\n\n");
}


bool inserirPessoaNaFila(PFILA f, int id, int ehPreferencial){
  bool resposta = false;

  // Condições de escape
  if (id < 0 || buscarID(f, id) != NULL) return resposta;

  // Alocação
  PONT novoElemento = (PONT) malloc(sizeof(ELEMENTO));

  // Preenchimento dos campos
  novoElemento->id = id;
  novoElemento->ehPreferencial = ehPreferencial;

  // Inserção na fila
  PONT ant = f->fimGeral;

  if (ant != NULL) ant->prox = novoElemento;
  else f->inicioGeral = novoElemento; // Caso o novoElemento seja o primeiro a ser inserido na fila

  f->fimGeral = novoElemento;

  // Refazer o processo de alocação, preenchimento e inserção caso o novo elemento seja preferencial
  if (ehPreferencial) {
    // Alocação
    PONT novoElementoPreferencial = (PONT) malloc(sizeof(ELEMENTO));

    // Preenchimento dos campos
    novoElementoPreferencial->id = id;
    novoElementoPreferencial->ehPreferencial = ehPreferencial;

    // Inserção na fila
    ant = f->fimPref;
    if (ant != NULL) ant->prox = novoElementoPreferencial;
    else f->inicioPref = novoElementoPreferencial; // Caso o novoElementoPreferencial seja o primeiro a ser inserido na fila

    f->fimPref = novoElementoPreferencial;    
  }

  resposta = true;
  return resposta;
}


void removerDaFilaGeral(PFILA f, int id) {
  // Encontra o elemento a ser removido e seu anterior
  PONT ant = NULL;
  PONT atual = f->inicioGeral;

  while (true) {
    if (atual->id == id) break;
    ant = atual;
    atual = atual->prox;
  }

  if (ant == NULL) { // Se "atual" for o primeiro da fila
    f->inicioGeral = atual->prox;
    if (f->inicioGeral == NULL) f->fimGeral = NULL; // Se "atual" era o único elemento, a fila fica vazia
  } else { 
    ant->prox = atual->prox; 
    if (atual->prox == NULL) f->fimGeral = ant; // Se "atual" era o último elemento da fila
  }
  
  free(atual);
}

void removerDaFilaPreferencial(PFILA f, int id) {
  // Encontra o elemento a ser removido e seu anterior
  PONT ant = NULL;
  PONT atual = f->inicioPref;

  while (true) {
    if (atual->id == id) break;
    ant = atual;
    atual = atual->prox;
  }

  if (ant == NULL) { // Se "atual" for o primeiro da fila
    f->inicioPref = atual->prox;
    if (f->inicioPref == NULL) f->fimPref = NULL; // Se "atual" era o único elemento, a fila fica vazia
  } else { 
    ant->prox = atual->prox; 
    if (atual->prox == NULL) f->fimPref = ant; // Se "atual" era o último elemento da fila
  }
  
  free(atual);
}



bool atenderPrimeiraDaFilaPreferencial(PFILA f, int* id){
  bool resposta = false;

  if (f->inicioGeral == NULL) return resposta;

  if (f->inicioPref != NULL) {
    *id = f->inicioPref->id;
    removerDaFilaPreferencial(f, *id);
    removerDaFilaGeral(f, *id);
  } else { 
    *id = f->inicioGeral->id;
    removerDaFilaGeral(f, *id);
  }

  resposta = true;
  return resposta;
}



bool atenderPrimeiraDaFilaGeral(PFILA f, int* id){
  bool resposta = false;

  if (f->inicioGeral == NULL) return resposta;

  *id = f->inicioGeral->id;

  if (f->inicioGeral->ehPreferencial) removerDaFilaPreferencial(f, *id);
  removerDaFilaGeral(f, *id);

  resposta = true;
  return resposta;
}



bool desistirDaFila(PFILA f, int id){
  bool resposta = false;

  PONT aSerRemovido = buscarID(f, id);

  if (aSerRemovido == NULL) return resposta;

  if (aSerRemovido->ehPreferencial) removerDaFilaPreferencial(f, id);
  removerDaFilaGeral(f, id);

  resposta = true;
  return resposta;
}

