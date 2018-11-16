//declara��o da fun��o preencher
//=============================================================================================================================================================
	
//fun��o de adi��o de dados do cadastro
void preencher(char categoria[8][14],lista_cadastro *ficha,char titulo[500],char data_sistema[11]){
	
	//vari�veis locais
	int i;
	char sel,vlr[10];
	
	//vari�vel para receber o valor
	char valor[1000000];
	
	//vari�vel sinalizadora de mudan�a de vari�vel
	int n = 0;
	
	//vari�vel de inicializa��o padr�o
	char reseta[100];
	
//Recebe os dados da data do cadastro
//===================================================================
	
	//copia a data do sistema para o cadastro
	strcpy(ficha->data,data_sistema);
	
	//atualiza a tela com os dados recebidos
	system("cls");
	printf("%s",titulo);
	printf("Data: %s\n",ficha->data);
	
//Recebe os dados da descri��o do cadastro
//===================================================================

	//recebe o valor padr�o
	strcpy(reseta,"");
	strcpy(reseta,ficha->descricao);
	
	//inicializa a descri��o 
	strcpy(ficha->descricao," ");
	printf("Descri��o: ");
	
	//recebe a descri��o	
	fgets(ficha->descricao,100,stdin);
	
	//verifica se a primeira tecla pressionada foi enter
	if(ficha->descricao[0] == '\n'){
			
		//inicializa de forma padr�o a descri��o
		strcpy(ficha->descricao,reseta);
		system("cls");
		printf("%s",titulo);
		printf("Data: %s\nDescri��o: %s\nCategoria: %s",ficha->data,ficha->descricao,ficha->categoria);
			
	}else{
			
		//susbstitui o \n por \0
		ficha->descricao[strlen(ficha->descricao)-1] = '\0';
		printf("Categoria: %s",ficha->categoria);
		
	}
		
//Recebe os dados da categoria do cadastro
//===================================================================
	
	//inicializa os �ndices da matriz de categorias
	i = 0;
	int j = 0;
	
	//la�o de sele��o da categoria
	while(1){
				
		//vari�vel de controle
		sel = getch()-48;
			
		//interrompre o loop para receber a categoria se a primeira tecla digitada for enter
		if(j == 0  and sel == -35){
			
			printf("\nValor: ");
			break;
					
		}else if(sel == -35 and j !=0){
					
			//recebe o valor selecionado pelo usu�rio
			strcpy(ficha->categoria,categoria[i]);
			ficha->categoria[12] = ' ';
			system("cls");
			printf("%s",titulo);
			printf("Data: %s\nDescri��o: %s\nCategoria: %s\nValor: ",ficha->data,ficha->descricao,ficha->categoria);
			break;
					
		}else if(sel == 24){
					
			//decrementa i e exibe categorias acima
			i--;
				
		}else if(sel == 32){
					
			//incrementa i e exibe categorias abaixo
			i++;
		}
				
		if(i == 8 ){
					
			//volta no primeiro item 
			i = 0;
					
		}else if(i<0){
					
			//volta no �ltimo item 
			i = 7;
		}
		
		system("cls");
		printf("%s",titulo);
		printf("Data: %s\nDescri��o: %s\nCategoria: %s",ficha->data,ficha->descricao,categoria[i]);
		j++;
	}
					
//Recebe os dados do valor do cadastro
//===================================================================		
	
	//converte para string recebe o valor padr�o 
	strcpy(reseta,"");
	sprintf(reseta,"%f",ficha->valor);
	
	//recebe a vari�vel de verifica��o
	strcpy(valor," ");
	fgets(valor,1000000,stdin);		
			
	//verifica se a primeira tecla pressionada foi o enter		
	if(valor[0] != '\n'){
			
		//susbstitui o \n por \0, converte e recebe os detalhes
		valor[strlen(valor)-1] = '\0';
		ficha->valor = atof(valor);
			
	}else{
		
		//retorna o valor padr�o
		ficha->valor = atof(reseta);
		system("cls");
		printf("%s",titulo);
		printf("Data: %s\nDescri��o: %s\nCategoria: %s\nValor: %.2f\nDescri��o",ficha->data,ficha->descricao,ficha->categoria,ficha->valor);
		
	}
	
//Recebe detalhes do cadastro
//===================================================================
	
	//reinicializa com os valores padr�o
	strcpy(reseta,"");
	strcpy(reseta,ficha->detalhes);
	
	//reseta e recebe os detalhes
	strcpy(ficha->detalhes," ");
	fgets(ficha->detalhes,100,stdin);
	
	if(ficha->detalhes[0] == '\n'){
		
		//inicializa de forma padr�o os detalhes	
		strcpy(ficha->detalhes,reseta);
	
	}else{
		
		//susbstitui o \n por \0 
		ficha->detalhes[strlen(ficha->detalhes)-1] = '\0';	
			
	}
}	


//declara��o da fun��o adicionar
//=============================================================================================================================================================

//fun��o para adicionar cadastro na lista
void adicionar(char categoria[8][14],lista_cadastro *list,char titulo[500],char data_sistema[11]){
	
	//aloca��o de mem�ria para o novo cadastro
	lista_cadastro *novo = (lista_cadastro *)malloc(sizeof(lista_cadastro));
	novo->prox = NULL;
	novo->ant = NULL;
	
	//inicializa��o do novo cadastro
	strcpy(novo->descricao,"(Null)");
	strcpy(novo->categoria,"-------------");
	strcpy(novo->detalhes,"(Null)");
	novo->valor = 0;
	
	//chamada da fun��o preencher para receber os valores da nova aloca��o
	preencher(categoria,novo,titulo,data_sistema); 
	
	//verifica se o cadastro n�o est� vazio ou n�o para adicion�-lo na lista
	if((strcmp(novo->descricao,"(Null)") != 0) and (strcmp(novo->categoria,"-------------") != 0) and novo->valor != 0){
			
		//verifica se a lista est� vazia
		if(list->prox == NULL){
			
			//organiza��o da nova aloca��o na lista de structs
			novo->prox = list->prox;
			list->prox = novo;
			novo->ant = list;
			
		//verifica se a lista j� possui termos	
		}else if(list->prox != NULL){
			
			//organiza��o da nova aloca��o na lista de structs
			novo->prox = list->prox;
			list->prox = novo;
			novo->ant = list;
			novo->prox->ant = novo;
				
		}
	}
}
