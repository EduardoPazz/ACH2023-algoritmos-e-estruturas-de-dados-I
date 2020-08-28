#include <malloc.h>

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

