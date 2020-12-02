/*************************** TESTES PARA O EP 3 - AED 1 ********************************/
/** AUTORES: EGYDIO                                                                   **/
/**          EMANUEL @EMMANUCA														  **/
/**          RAUL @rmellos			  												  **/
/**                                                                                   **/
/** ATENCAO: OS TESTES REALIZADOS NESTE ARQUIVO PODEM NAO ABRANGER TODAS AS SITUACOES **/
/** TESTADAS PELOS PROFESSORES                                                        **/
/**                                                                                   **/
/***************************************************************************************/
 
#include "filaShark.c"

int countArray(int arr[], int size) {

    int res = 0;

    for (int i = 0; i < size; i++) {
        printf("Caso: %d \t Deu falso: %d\n", i, arr[i] == 1);
    }

    return res;
}

bool position(PFILA f) {
	for (int i = 0; i < f -> maxElementos; i++) {
		if (i >= f -> elementosNoHeap) break;
		if (f -> heap[i] -> posicao != i) return false;
	}
	return true;
}
 
bool isMaxHeap(PFILA f) {
	if (!f) return true;
	for (int i = 0; i < f -> maxElementos; i++) {
		int esq = 2*i + 1;
		int dir = 2*i + 2;
		if (i >= f -> elementosNoHeap) break;
		 
		if (esq < f -> elementosNoHeap) {
			if ( f -> heap[i] -> prioridade < f -> heap[esq] -> prioridade) return false;
			 
			if (dir < f -> elementosNoHeap && 
				f -> heap[i] -> prioridade < f -> heap[dir] -> prioridade
			   ) return false;
		}
	}
	return true;
}
 
int main() {

	printf("%f\n", 1377.0);
	printf("%f\n", 1377000.0);

	PFILA f = criarFila(11);
	float resposta;
	exibirLog(f);

	int teste0[15];

	printf("TESTE 0 - RESTRICOES\n\n");

	// Remover no heap vazio
	if(removerElemento(f)) {
	    printf("1-incorreto\n");
	    teste0[0] = 1;
	} else printf("1-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Aumentar prioridade no heap vazio
	if(aumentarPrioridade(f,0,1)) {
	    printf("2-incorreto\n");
	    teste0[1] = 1;
	} else printf("2-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Inserir com id negativo
	if(inserirElemento(f,-5,1)) {
	    printf("3-incorreto\n");
	    teste0[2] = 1;
	} else printf("3-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Inserir com prioridade negativa
	if(inserirElemento(f,5,-1)) printf("4-CORRETO\n");
	else {
	    printf("4-incorreto\n");
	    teste0[3] = 1;
	}
	exibirLog(f);

	// Inserir com ID maior que o max.
	if(inserirElemento(f,11,1)) {
	    printf("5-incorreto\n");
	    teste0[4] = 1;
	} else printf("5-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Inserir em condições normais
	if(inserirElemento(f,0,1)) printf("6-CORRETO\n");
	else {
	    printf("6-incorreto\n");
	    teste0[5] = 1;
	}
	exibirLog(f);

	// Inserir em id já existente
	if(inserirElemento(f,0,5)) {
	    printf("7-incorreto\n");
	    teste0[6] = 1;
	} else printf("7-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Consultar a prioridade do primeiro elemento
	if(consultarPrioridade(f,0,&resposta)) {
		if (resposta == 1.0) printf("8-CORRETO:%f\n",resposta);
		else {
		    printf("8-incorreto(Retornou prioridade incorreta");
		    teste0[7] = 1;
		}
	} else {
	    printf("8-incorreto(Retornou falso)\n");
	    teste0[7] = 1;
	}
	exibirLog(f);

	// Reduzir prioridade no heap vazio
	if(reduzirPrioridade(f,0,1)) {
	    printf("9-incorreto\n");
	    teste0[8] = 1;
	} else printf("9-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Aumentar prioridade que jah eh maior que a nova
	if(aumentarPrioridade(f,0,0)) {
	    printf("10-incorreto\n");
	    teste0[9] = 1;
	} else printf("10-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Reduzir prioridade que jah eh menor que a nova
	if(reduzirPrioridade(f,0,10)) {
	    printf("11-incorreto\n");
	    teste0[10] = 1;
	} else printf("11-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Aumentando a prioridade de um ID inexistente no heap
	if(aumentarPrioridade(f,3,1)) {
	    printf("12-incorreto\n");
	    teste0[11] = 1;
	} else printf("12-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Reduzindo a prioridade de um ID inexistente no heap
	if(reduzirPrioridade(f,4,10)) {
	    printf("13-incorreto\n");
	    teste0[12] = 1;
	} else printf("13-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Consultar prioridade de elemento com id maior que o maximo permitido
	if(consultarPrioridade(f,12,&resposta)) {
	    printf("14-incorreto\n");
	    teste0[13] = 1;
	} else printf("14-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Consultar prioridade de elemento nao existente
	if(consultarPrioridade(f,2,&resposta)) {
	    printf("15-incorreto\n");
	    teste0[14] = 1;
	} else printf("15-ERRO (ESPERADO)\n");
	exibirLog(f);

	printf("\nTESTE 1 - REMOCAO\n\n");

	int teste1[18];

	PONT el;
	// Removendo todos os elementos do heap
	if(el = removerElemento(f)) {
		if(el->prioridade == 1.0) printf("1-CORRETO\n");
		else {
		    printf ("1-incorreto(Prioridade incorreta");
		    teste1[0] = 1;
		}
	} else {
	    printf("1-incorreto\n");
        teste1[0] = 1;
	}
	exibirLog(f);
	 
	if(el = removerElemento(f)) {
		if(el->prioridade == -1.0) printf("2-CORRETO\n");
		else {
		    printf ("2-incorreto(Prioridade incorreta)\n");
            teste1[1] = 1;
		}
	} else {
	    printf("2-incorreto(retornou false)\n");
        teste1[1] = 1;
	}
	exibirLog(f);

	// Removendo de um heap vazio após remover elementos
	if(removerElemento(f)) {
	    printf("3-incorreto\n");
        teste1[2] = 1;
	} else printf("3-ERRO (ESPERADO)\n");
	exibirLog(f);

	// Inserindo elementos
	if(inserirElemento(f,3,3)) printf("4-CORRETO\n");
	else {
	    printf("4-incorreto\n");
        teste1[3] = 1;
	}
	exibirLog(f);

	if(inserirElemento(f,1,1)) printf("5-CORRETO\n");
	else {
	    printf("5-incorreto\n");
        teste1[4] = 1;
	}
	exibirLog(f);

	if(inserirElemento(f,2,2)) printf("6-CORRETO\n");
	else {
	    printf("6-incorreto\n");
        teste1[5] = 1;
	}
	exibirLog(f);

	// Reduzindo a prioridade de um elemento 
	if(reduzirPrioridade(f,3,0)) printf("7-CORRETO\n");
	else {
	    printf("7-incorreto\n");
        teste1[6] = 1;
	}
	exibirLog(f);
	
	// Inserindo elementos
	if(inserirElemento(f,9,3)) printf("8-CORRETO\n");
	else {
	    printf("8-incorreto\n");
        teste1[7] = 1;
	}
	exibirLog(f);
	
	if(inserirElemento(f,10,2)) printf("9-CORRETO\n");
	else {
	    printf("9-incorreto\n");
        teste1[8] = 1;
	}
	exibirLog(f);

	if(inserirElemento(f,6,3)) printf("10-CORRETO\n");
	else {
	    printf("10-incorreto\n");
        teste1[9] = 1;
	}
	exibirLog(f);

	// Reduzindo prioridades
	if(reduzirPrioridade(f,2,1)) {
		el = f -> arranjo[2];
		if (el->prioridade == 1.0) printf("11-CORRETO\n");
		else {
		    printf("11-incorreto(prioridade errada)\n");
            teste1[10] = 1;
		}
	} else {
	    printf("11-incorreto(retornou false)\n");
        teste1[10] = 1;
	}
	exibirLog(f);
	
	// Removendo Elementos
	if(el = removerElemento(f)) {
		if (el -> id == 9 ) {
			if (el -> prioridade == 3.0) printf("12-CORRETO\n");
			else {
			    printf("12-incorreto(prioridade errada)");
                teste1[11] = 1;
			}
		} else {
		    printf("12-incorreto(id errado)");
            teste1[11] = 1;
		}
	} else {
	    printf("12-incorreto(retornou false)\n");
        teste1[11] = 1;
	}
	exibirLog(f);
	 
	if(isMaxHeap(f)) printf("13-CORRETO\n");
	else {
	    printf("13-incorreto(propriedades do heap max quebradas)\n");
        teste1[12] = 1;
	}
	
	if(el = removerElemento(f)) {
		if (el -> id == 6 ) {
			if (el -> prioridade == 3.0) printf("14-CORRETO\n");
			else {
			    printf("14-incorreto(prioridade errada)");
                teste1[13] = 1;
			}
		} else {
		    printf("14-incorreto(id errado)");
            teste1[13] = 1;
		}
	} else {
	    printf("14-incorreto(retornou false)\n");
        teste1[13] = 1;
	}
	exibirLog(f);
	 
	if(isMaxHeap(f)) printf("15-CORRETO\n");
	else {
	    printf("15-incorreto(propriedades do heap max quebradas)\n");
        teste1[14] = 1;
	}
	 
	if(el = removerElemento(f)) {
		if (el -> id == 10 ) {
			if (el -> prioridade == 2.0) printf("16-CORRETO\n");
			else {
			    printf("16-incorreto(prioridade errada)");
                teste1[15] = 1;
			}
		} else {
		    printf("16-incorreto(id errado)");
            teste1[15] = 1;
		}
	} else {
	    printf("16-incorreto(retornou false)\n");
        teste1[15] = 1;
	}
	exibirLog(f);
	 
	if(isMaxHeap(f)) printf("17-CORRETO\n");
	else {
	    printf("17-incorreto(propriedades do heap max quebradas)\n");
        teste1[16] = 1;
	}

	// Conferindo posicoes
	if(position(f)) printf("18-CORRETO\n");
	else {
	    printf("18-incorreto(posicoes nao atualizadas\n");
        teste1[17] = 1;
	}
	///////////////////////////////////////////////
	
	printf("\n\nTESTE 2 - INSERCAO\n\n");
	f = criarFila(5);

	int teste2[7];
	
	// Inserir com prioridade em ponto flutuante
	if (inserirElemento(f, 4, 1.337)) {
		el = f -> arranjo[4];
		printf("A prioridade é %f\n", el->prioridade);
		printf("1.33700 é igual a %f\n", 1.337);
		printf("Deu %d\n", 1000 * el->prioridade == 1337.0);
		if (el -> prioridade * 1000 == 1337.0 ) printf("1-CORRETO\n");
		else {
		    printf("1-incorreto(prioridade errada)\n");
		    teste2[0] = 1;
		}
	} else {
	    printf("1-incorreto(retornou false)\n");
        teste2[0] = 1;
	}
	exibirLog(f);
	 
	// Conferindo os campos posicao
	inserirElemento(f,2,24);
	exibirLog(f);
	 
	inserirElemento(f,3,8.0085);
	exibirLog(f);
	 
	if(position(f)) printf("2-CORRETO\n");
	else {
	    printf("2-incorreto(posicoes nao atualizadas\n");
        teste2[1] = 1;
	}
	 
	if(isMaxHeap(f)) printf("3-CORRETO\n");
	else {
	    printf("3-incorreto(propriedades do heap max quebradas)\n");
        teste2[2] = 1;
	}
	 	
	// Conferindo a insercao no arranjo
	if (inserirElemento(f, 1, 42)) {
		if (f -> arranjo[1]) printf("4-CORRETO\n");
		else {
		    printf("4-incorreto(pos no arranjo estah vazia)\n");
            teste2[3] = 1;
		}
	} else {
	    printf("4-incorreto(retornou false)\n");
        teste2[3] = 1;
	}
	exibirLog(f);
	  
	// Conferindo a insercao no heap
	if (inserirElemento(f, 0, 100)) {
		if (f -> heap[0]) printf("5-CORRETO\n");
		else {
		    printf("5-incorreto(pos no heap estah vazia)\n");
            teste2[4] = 1;
		}
	} else {
	    printf("5-incorreto(retornou false)\n");
        teste2[4] = 1;
	}
	 
	// Conferindo se o ponteiro no heap eh o mesmo do ponteiro no arranjo
	if (f -> heap[0] == f -> arranjo[0]) printf("6-CORRETO\n");
	else {
	    printf("6-incorreto(ponteiros no heap e arr de um elem nao sao iguais)\n");
        teste2[5] = 1;
	}
	 
	// Conferindo se o campo elementosNoHeap estah certo
	if (f -> elementosNoHeap == 5) printf("7-CORRETO\n");
	else {
	    printf("7-incorreto(elementosNoHeap errado)\n");
        teste2[6] = 1;
	}

	 
	printf("\n\nTESTE 3 - AUMENTAR E REDUZIR PRIORIDADE\n\n");
	exibirLog(f);

	int teste3[7];
		 
	if (reduzirPrioridade(f, 0, 41)) printf("1-CORRETO\n");
	else {
	    printf("1-incorreto(retornou false\n");
	    teste3[0] = 1;
	}
	exibirLog(f);
	 
	if(isMaxHeap(f)) printf("2-CORRETO\n");
	else {
	    printf("2-incorreto(propriedades do heap max quebradas)\n");
        teste3[1] = 1;
	}
	 
	if (aumentarPrioridade(f, 2, 44)) printf("3-CORRETO\n");
	else {
	    printf("3-incorreto(retornou false)\n");
        teste3[2] = 1;
	}
	exibirLog(f);
	 
	if(isMaxHeap(f)) printf("4-CORRETO\n");
	else {
	    printf("4-incorreto(propriedades do heap max quebradas)\n");
        teste3[3] = 1;
	}
	 
	if (f -> arranjo[0] -> prioridade == 41) printf("5-CORRETO\n");
	else {
	    printf("5-incorreto(prioridade errada)\n");
        teste3[4] = 1;
	}
	 
	if (f -> arranjo[2] -> prioridade == 44) printf("6-CORRETO\n");
	else {
	    printf("6-incorreto(prioridade errada)\n");
        teste3[5] = 1;
	}
	 
	if(position(f)) printf("7-CORRETO\n");
	else {
	    printf("7-incorreto(posicoes nao atualizadas)");
        teste3[6] = 1;
	}

	printf("\n--------------------------------------------------\n");

	printf("RESULTADO TESTES 0:");
	countArray(teste0, 15);

    printf("RESULTADO TESTES 1:");
	countArray(teste1, 18);

    printf("RESULTADO TESTES 2");
	countArray(teste2, 7);

    printf("RESULTADO TESTES 3");
	countArray(teste3, 7);


}
