#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define ERRO -1
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX+1];
    int nroElem;
} LISTA;

void inicializarLista(LISTA* l){
    l->nroElem = 0;
}
void exibirLista(LISTA* l){
    int i;
    printf("Lista: \" ");

    for (i=0; i < l->nroElem; i++) printf("%i ", l->A[i].chave);

    printf("\"\n");
}

void ordenaLista(LISTA* l) {
    int temporario;

    for (int i = 1, j = 1; i < l->nroElem; i++, j = i) {
        temporario = l->A[i].chave;

        while (j > 0 && l->A[j-1].chave > temporario) {
            l->A[j].chave = l->A[j-1].chave;
            j--;
        }

        l->A[j].chave = temporario;
    }
}

void main() {
    LISTA* l = (LISTA*) malloc(sizeof(LISTA));
    
    inicializarLista(l);

    // Inserção aleatória de chaves
    l->A[0].chave = 7;
    l->A[1].chave = 1;
    l->A[2].chave = 911;
    l->A[3].chave = 482;
    l->A[4].chave = 78;
    l->A[5].chave = 4;
    l->A[6].chave = 4987;
    l->A[7].chave = 714;

    l->nroElem = 8;

    exibirLista(l);
    // Output: Lista: " 7 1 911 482 78 4 4987 714 "

    ordenaLista(l);

    exibirLista(l);
    // Output: Lista: " 1 4 7 78 482 714 911 4987 "
}
