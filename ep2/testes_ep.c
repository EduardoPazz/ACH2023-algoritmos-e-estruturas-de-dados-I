printf("################# INSERINDO #######################\n");

  exibirLog(f);
  res = inserirPessoaNaFila(f, -1, false);
  if(res) printf("Insercao retornou true (0).\n");
  else printf("Insercao retornou false (0). Não pode inserir -1 [OK]\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 1, false);
  if(res) printf("Insercao retornou true (1). Inserindo 1 [OK]\n");
  else printf("Insercao retornou false (1).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 2, true);
  if(res) printf("Insercao retornou true (2). Inserindo 2 [OK]\n");
  else printf("Insercao retornou false (2).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 3, false);
  if(res) printf("Insercao retornou true (3). Inserindo 3 [OK]\n");
  else printf("Insercao retornou false (3).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 4, true);
  if(res) printf("Insercao retornou true (4). Inserindo 4 [OK]\n");
  else printf("Insercao retornou false (4).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 5, true);
  if(res) printf("Insercao retornou true (5). Inserindo 5[OK]\n");
  else printf("Insercao retornou false (5).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 6, false);
  if(res) printf("Insercao retornou true (6). Inserindo 6 [OK]\n");
  else printf("Insercao retornou false (6).\n");
  exibirLog(f);

        
  printf("################# ATENDENDO #######################\n");
  exibirLog(f);
  res = atenderPrimeiraDaFilaPreferencial(f, &id);
  if(res) printf("Atendimento retornou true (7), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (7).\n");

  exibirLog(f);
  res = atenderPrimeiraDaFilaGeral(f, &id);
  if(res) printf("Atendimento retornou true (8), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (8).\n");

  exibirLog(f);
  res = atenderPrimeiraDaFilaPreferencial(f, &id);
  if(res) printf("Atendimento retornou true (9), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (9).\n");

  exibirLog(f);
  res = atenderPrimeiraDaFilaGeral(f, &id);
  if(res) printf("Atendimento retornou true (10), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (10).\n");

  exibirLog(f);
  res = atenderPrimeiraDaFilaPreferencial(f, &id);
  if(res) printf("Atendimento retornou true (11), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (11).\n");

  exibirLog(f);
  res = atenderPrimeiraDaFilaGeral(f, &id);
  if(res) printf("Atendimento retornou true (12), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (12).\n");

  exibirLog(f);
  res = atenderPrimeiraDaFilaPreferencial(f, &id);
  if(res) printf("Atendimento retornou true (13), id=%i.\n",id);
  else printf("Atendimento retornou false (13). [OK]\n");
  exibirLog(f);

        

  printf("################# INSERINDO PARTE 2 ###############\n");

  exibirLog(f);
  res = inserirPessoaNaFila(f, 7, false);
  if(res) printf("Insercao retornou true (14). Inserindo 7 [OK]\n");
  else printf("Insercao retornou false (14).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 8, true);
  if(res) printf("Insercao retornou true (15). Inserindo 8 [OK]\n");
  else printf("Insercao retornou false (15).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 9, false);
  if(res) printf("Insercao retornou true (16). Inserindo 9 [OK]\n");
  else printf("Insercao retornou false (16).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 10, true);
  if(res) printf("Insercao retornou true (17). Inserindo 10 [OK]\n");
  else printf("Insercao retornou false (17).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 12, true);
  if(res) printf("Insercao retornou true (18). Inserindo 12 [OK]\n");
  else printf("Insercao retornou false (18).\n");
  exibirLog(f);

        
  printf("################# SAINDO DA FILA ##################\n");

  exibirLog(f);
  res = desistirDaFila(f, 6);
  if(res) printf("Desistindo da fila retornou true (19).\n");
  else printf("Desistindo da fila retornou false (19). Não tenho 6 [OK]\n");
  exibirLog(f);
  res = desistirDaFila(f, 7);
  if(res) printf("Desistindo da fila retornou true (20). Saindo 7 [OK]\n");
  else printf("Desistindo da fila retornou false (20).\n");
  exibirLog(f);
  res = desistirDaFila(f, 10);
  if(res) printf("Desistindo da fila retornou true (21). Sainto 10 [OK]\n");
  else printf("Desistindo da fila retornou false (21).\n");
  exibirLog(f);
  res = desistirDaFila(f, 9);
  if(res) printf("Desistindo da fila retornou true (22)Saindo 9 [0k].\n");
  else printf("Desistindo da fila retornou false (22).\n");
  exibirLog(f);
  res = desistirDaFila(f, 10);
  if(res) printf("Desistindo da fila retornou true (23).\n");
  else printf("Desistindo da fila retornou false (23). Não da para tirar o 10 [OK]\n");
  exibirLog(f);
  res = desistirDaFila(f, 8);
  if(res) printf("Desistindo da fila retornou true (23). Saindo 8 [OK]\n");
  else printf("Desistindo da fila retornou false (23).\n");
  exibirLog(f);
  
  printf("################# INSERINDO PARTE 3 ###############\n");

  exibirLog(f);
  res = inserirPessoaNaFila(f, 10, false);
  if(res) printf("Insercao retornou true (24). Inseriu o 10 [OK]\n");
  else printf("Insercao retornou false (14).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 8, true);
  if(res) printf("Insercao retornou true (25). Inseriu o 8 [OK]\n");
  else printf("Insercao retornou false (15).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 9, false);
  if(res) printf("Insercao retornou true (26). Inseriu o 9 [OK]\n");
  else printf("Insercao retornou false (26).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 10, true);
  if(res) printf("Insercao retornou true (27).\n");
  else printf("Insercao retornou false (27)[ok] Não inseriu o 10.\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 3, true);
  if(res) printf("Insercao retornou true (28). Inseriu o 3 [OK]\n");
  else printf("Insercao retornou false (28).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 5, false);
  if(res) printf("Insercao retornou true (29). Inseriu o 5 [OK]\n");
  else printf("Insercao retornou false (29).\n");
  exibirLog(f);
  res = inserirPessoaNaFila(f, 5, true);
  if(res) printf("Insercao retornou true (30).\n");
  else printf("Insercao retornou false (30). Não inseriu o 5 [OK]\n");
  exibirLog(f);
  
  printf("################# ATENDENDO PARTE 2 #######################\n");
  exibirLog(f);
  res = atenderPrimeiraDaFilaPreferencial(f, &id);
  if(res) printf("Atendimento retornou true (31), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (31).\n");

  exibirLog(f);
  res = atenderPrimeiraDaFilaPreferencial(f, &id);
  if(res) printf("Atendimento retornou true (32), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (32).\n");
  
  exibirLog(f);
  res = atenderPrimeiraDaFilaGeral(f, &id);
  if(res) printf("Atendimento retornou true (33), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (33).\n");

  

  exibirLog(f);
  res = atenderPrimeiraDaFilaGeral(f, &id);
  if(res) printf("Atendimento retornou true (34), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (34).\n");

  exibirLog(f);
  res = atenderPrimeiraDaFilaPreferencial(f, &id);
  if(res) printf("Atendimento retornou true (35), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (35).\n");
  exibirLog(f);
  res = atenderPrimeiraDaFilaGeral(f, &id);
  if(res) printf("Atendimento retornou true (36), id=%i. [OK]\n",id);
  else printf("Atendimento retornou false (36).\n");
  

  exibirLog(f);
  res = atenderPrimeiraDaFilaPreferencial(f, &id);
  if(res) printf("Atendimento retornou true (37), id=%i.\n",id);
  else printf("Atendimento retornou false (37)[OK].\n");

  exibirLog(f);
  res = atenderPrimeiraDaFilaGeral(f, &id);
  if(res) printf("Atendimento retornou true (38), id=%i.\n",id);
  else printf("Atendimento retornou false (38). [OK] \n");
  
  printf("################# INSERINDO #######################\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, -1, false);
	if(res) printf("Insercao retornou true (0).\n");
	else printf("Insercao retornou false (0). [OK]\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 1, false);
	if(res) printf("Insercao retornou true (1). [OK]\n");
	else printf("Insercao retornou false (1).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 2, true);
	if(res) printf("Insercao retornou true (2). [OK]\n");
	else printf("Insercao retornou false (2).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 3, false);
	if(res) printf("Insercao retornou true (3). [OK]\n");
	else printf("Insercao retornou false (3).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 4, true);
	if(res) printf("Insercao retornou true (4). [OK]\n");
	else printf("Insercao retornou false (4).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 5, true);
	if(res) printf("Insercao retornou true (5). [OK]\n");
	else printf("Insercao retornou false (5).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 6, false);
	if(res) printf("Insercao retornou true (6). [OK]\n");
	else printf("Insercao retornou false (6).\n");
	exibirLog(f);


	printf("################# ATENDENDO #######################\n");
	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (7), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (7).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaGeral(f, &id);
	if(res) printf("Atendimento retornou true (8), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (8).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (9), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (9).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaGeral(f, &id);
	if(res) printf("Atendimento retornou true (10), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (10).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (11), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (11).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaGeral(f, &id);
	if(res) printf("Atendimento retornou true (12), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (12).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (13), id=%i.\n",id);
	else printf("Atendimento retornou false (13). [OK]\n");
	exibirLog(f);



	printf("################# INSERINDO PARTE 2 ###############\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, 7, false);
	if(res) printf("Insercao retornou true (14). [OK]\n");
	else printf("Insercao retornou false (14).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 8, true);
	if(res) printf("Insercao retornou true (15). [OK]\n");
	else printf("Insercao retornou false (15).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 9, false);
	if(res) printf("Insercao retornou true (16). [OK]\n");
	else printf("Insercao retornou false (16).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 10, true);
	if(res) printf("Insercao retornou true (17). [OK]\n");
	else printf("Insercao retornou false (17).\n");
	exibirLog(f);


	printf("################# SAINDO DA FILA ##################\n");

	exibirLog(f);
	res = desistirDaFila(f, 6);
	if(res) printf("Desistindo da fila retornou true (18).\n");
	else printf("Desistindo da fila retornou false (18). [OK]\n");
	exibirLog(f);
	res = desistirDaFila(f, 7);
	if(res) printf("Desistindo da fila retornou true (19). [OK]\n");
	else printf("Desistindo da fila retornou false (19).\n");
	exibirLog(f);
	res = desistirDaFila(f, 8);
	if(res) printf("Desistindo da fila retornou true (20). [OK]\n");
	else printf("Desistindo da fila retornou false (20).\n");
	exibirLog(f);
	res = desistirDaFila(f, 9);
	if(res) printf("Desistindo da fila retornou true (21). [OK]\n");
	else printf("Desistindo da fila retornou false (21).\n");
	exibirLog(f);
	res = desistirDaFila(f, 10);
	if(res) printf("Desistindo da fila retornou true (22). [OK]\n");
	else printf("Desistindo da fila retornou false (22).\n");
	exibirLog(f);

  printf("################# INSERINDO AGAIN #######################\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, -1, false);
	if(res) printf("Insercao retornou true (0).\n");
	else printf("Insercao retornou false (0). [OK]\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 1, true);
	if(res) printf("Insercao retornou true (1). [OK]\n");
	else printf("Insercao retornou false (1).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 2, true);
	if(res) printf("Insercao retornou true (2). [OK]\n");
	else printf("Insercao retornou false (2).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 3, false);
	if(res) printf("Insercao retornou true (3). [OK]\n");
	else printf("Insercao retornou false (3).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 4, false);
	if(res) printf("Insercao retornou true (4). [OK]\n");
	else printf("Insercao retornou false (4).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 5, true);
	if(res) printf("Insercao retornou true (5). [OK]\n");
	else printf("Insercao retornou false (5).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 6, false);
	if(res) printf("Insercao retornou true (6). [OK]\n");
	else printf("Insercao retornou false (6).\n");
	exibirLog(f);


	printf("################# ATENDENDO #######################\n");
	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (7), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (7).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaGeral(f, &id);
	if(res) printf("Atendimento retornou true (8), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (8).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (9), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (9).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaGeral(f, &id);
	if(res) printf("Atendimento retornou true (10), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (10).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (11), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (11).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaGeral(f, &id);
	if(res) printf("Atendimento retornou true (12), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (12).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFilaPreferencial(f, &id);
	if(res) printf("Atendimento retornou true (13), id=%i.\n",id);
	else printf("Atendimento retornou false (13). [OK]\n");
	exibirLog(f);


  
        return 0;