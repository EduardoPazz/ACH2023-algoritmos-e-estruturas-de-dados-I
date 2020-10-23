/******************************************************************************
     usaTresPilhasEstaticas.c
  Este programa interage com o usuario para o gerenciamento de tres pilhas
  alocadas num mesmo arranjo.
******************************************************************************/
#include "tresPilhasEstaticas.c"
#include <stdio.h>

void inserir1(PILHATRIPLA* p){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElementoPilha(p,reg,1)) printf("Elemento %i inserido corretamente na pilha 1.\n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n",ch);
}

void inserir2(PILHATRIPLA* p){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElementoPilha(p,reg,2)) printf("Elemento %i inserido corretamente na pilha 2.\n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n",ch);
}

void inserir3(PILHATRIPLA* p){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElementoPilha(p,reg,3)) printf("Elemento %i inserido corretamente na pilha 3.\n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n",ch);
}

void exibirPrimeiro1(PILHATRIPLA* p){
  TIPOCHAVE ch;
  int posicao = retornarPrimeiroPilha(p,&ch,1);
  if (posicao != -1) printf("Primeiro elemento pilha 1: %i encontrado no endereco %i.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (pilha vazia).\n");
}

void exibirPrimeiro2(PILHATRIPLA* p){
  TIPOCHAVE ch;
  int posicao = retornarPrimeiroPilha(p,&ch,2);
  if (posicao != -1) printf("Primeiro elemento pilha 2: %i encontrado no endereco %i.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (pilha vazia).\n");
}

void exibirPrimeiro3(PILHATRIPLA* p){
  TIPOCHAVE ch;
  int posicao = retornarPrimeiroPilha(p,&ch,3);
  if (posicao != -1) printf("Primeiro elemento pilha 3: %i encontrado no endereco %i.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (pilha vazia).\n");
}

void excluir1(PILHATRIPLA* p){
  REGISTRO reg;
  if (excluirElementoPilha(p,&reg,1)) printf("Elemento %i excluido corretamente da pilha 1.\n",reg.chave);
  else printf("Nao foi possivel excluir elemento pilha 1 - pilha vazio.\n");
}

void excluir2(PILHATRIPLA* p){
  REGISTRO reg;
  if (excluirElementoPilha(p, &reg,2)) printf("Elemento %i excluido corretamente da pilha 2.\n",reg.chave);
  else printf("Nao foi possivel excluir elemento pilha 2 - pilha vazio.\n");
}

void excluir3(PILHATRIPLA* p){
  REGISTRO reg;
  if (excluirElementoPilha(p, &reg,3)) printf("Elemento %i excluido corretamente da pilha 3.\n",reg.chave);
  else printf("Nao foi possivel excluir elemento pilha 3 - pilha vazio.\n");
}

void exibir1(PILHATRIPLA* p){
  exibirUmaPilha(p,1);
}

void exibir2(PILHATRIPLA* p){
  exibirUmaPilha(p,2);
}

void exibir3(PILHATRIPLA* p){
  exibirUmaPilha(p,3);
}

void meuLog(PILHATRIPLA* p){
  printf("Numero de elementos na pilha 1: %i.\n",tamanhoUmaPilha(p,1));
  printf("Numero de elementos na pilha 2: %i.\n",tamanhoUmaPilha(p,2));
  printf("Numero de elementos na pilha 3: %i.\n",tamanhoUmaPilha(p,3));
  printf("Tamanho do pilha (em bytes): %i.\n",tamanhoEmBytesPilha(p));
}

void help(){
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1, na pilha 1\n");
  printf("   j <chave1>: inserir elemento com chave=chave1, na pilha 2\n");
  printf("   k <chave1>: inserir elemento com chave=chave1, na pilha 3\n");
  printf("   e : excluir elemento com chave=chave1, na pilha 1\n");
  printf("   f : excluir elemento com chave=chave1, na pilha 2\n");
  printf("   g : excluir elemento com chave=chave1, na pilha 3\n");
  printf("   n : imprimir pilha 1\n");
  printf("   o : imprimir pilha 2\n");
  printf("   p : imprimir pilha 2\n");
  printf("   d : destruir (zerar) pilhas\n");
  printf("   l : exibir log de utilizacao do pilha\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   1 : exibir a chave e o endereco do topo, pilha 1\n");
  printf("   2 : exibir a chave e o endereco do topo, pilha 2\n");
  printf("   3 : exibir a chave e o endereco do topo, pilha 3\n");
  printf("   q : sair (quit)\n");
}

void destruir(PILHATRIPLA* p){
     reinicializarPilha(p);
     printf("Pilhas zeradas.\n");
}

int main(){
  PILHATRIPLA pilha;
  inicializarPilhaTripla(&pilha);
  help();
  char comando = ' ';
  scanf("%c",&comando);
  while (comando != 'q'){
    switch (comando) {
      case 'i' : inserir1(&pilha); break;
      case 'j' : inserir2(&pilha); break;
      case 'k' : inserir3(&pilha); break;
      case 'e' : excluir1(&pilha); break;
      case 'f' : excluir2(&pilha); break;
      case 'g' : excluir3(&pilha); break;
      case 'n' : exibir1(&pilha); break;
      case 'o' : exibir2(&pilha); break;
      case 'p' : exibir3(&pilha); break;
      case 'd' : destruir(&pilha); break;
      case 'l' : meuLog(&pilha); break;
      case 'h' : help(); break;
      case '1' : exibirPrimeiro1(&pilha); break;
      case '2' : exibirPrimeiro2(&pilha); break;
      case '3' : exibirPrimeiro3(&pilha); break;

      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    scanf("%c",&comando);
  }

  return 0;
}
