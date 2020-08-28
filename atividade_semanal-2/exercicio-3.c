#include <stdio.h>
#include <stdlib.h>

typedef struct aux {
	int id;
	struct aux* mae;
	struct aux* pai;
} PESSOA;

PESSOA* inicializar(int id) {
	PESSOA* pessoa = (PESSOA*) malloc(sizeof(PESSOA));

	pessoa->id = id;
	pessoa-> mae = NULL;
	pessoa-> pai = NULL;

	return pessoa;
}

void registrar(PESSOA* filho, PESSOA* mae, PESSOA* pai) {
	filho->mae = mae;
	filho->pai = pai;
}

void relatorio(PESSOA* filho) {
	printf("ID do filho: %i \n", filho->id);
	printf("ID da mãe: %i \n", filho->mae->id);
	printf("ID do pai: %i \n", filho->pai->id);
}

void main() {
	PESSOA* filho = inicializar(rand());
	PESSOA* pai = inicializar(rand());
	PESSOA* mae = inicializar(rand());

	registrar(filho, mae, pai);

	relatorio(filho);
}
