//declara��o da matriz da categoria
char categoria[8][14];

//declara��o da fun��o preencher
//=============================================================================================================================================================
	
//fun��o de adi��o de dados do cadastro
void preencher(lista_cadastro *ficha,char titulo[500],char data_sistema[11]){
	
	//vari�veis locais
	int i;
	char sel,vlr[10];
	
	//incializa��o da matriz de categoria
	strcpy(categoria[0],"Informatica <");
	strcpy(categoria[1],"Contas      <");
	strcpy(categoria[2],"Vestimenta  <");
	strcpy(categoria[3],"Escolar     <");
	strcpy(categoria[4],"Alimenticio <");
	strcpy(categoria[5],"Medicamentos<");
	strcpy(categoria[6],"Documentos  <");
	strcpy(categoria[7],"Compras     <");
	
	
//Recebe os dados da data do cadastro
//===================================================================
	
	//copia a data do sistema para o cadastro
	strcpy(ficha->data,data_sistema);
	
	//exibe a ficha de cadastro
	printf("%s",titulo);
	printf("Data: %s\t\t\tDescri��o: %s<\n\n\n\nCategoria: %s\t\tValor: %.2f\n\n\n\nDetalhes(opcional): %s",ficha->data,ficha->descricao,ficha->categoria,ficha->valor,ficha->detalhes);
	
//Recebe os dados da descri��o do cadastro
//===================================================================

	//inicializa o contador
	i = 0;
	
	//loop de inser��o da descri��o
	while(1){
		
		//vari�vel de fluxo de dados
		fflush(stdin);
		sel = getch();
		
		//interrompre o loop para receber a descri��o se a primeira tecla pessionada for enter
		if(i == 0 and sel == 13){
			
			break;
			
		}else if(sel != 13 and i == 0){
			
			//inicializa a descri��o 
			strcpy(ficha->descricao,"                ");
			//recebe cada caractere da descri��o
			ficha->descricao[i] = sel;
			
		}else if(sel != 13 and i != 0){
			
			//recebe cada caractere da descri��o
			ficha->descricao[i] = sel;	
			
		}else if(sel == 13){
			
			//substitui o caractere \n por \0 e para o loop
			ficha->descricao[i] = '\0';
			break;
			
		}
		
		//limpa a tela e exibe a ficha de cadastro
		system("cls");
		printf("%s",titulo);
		printf("Data: %s\t\t\tDescri��o: %s<\n\n\n\nCategoria: %s\t\tValor: %.2f\n\n\n\nDetalhes(opcional): %s",ficha->data,ficha->descricao,ficha->categoria,ficha->valor,ficha->detalhes);
		i++;
		
		//finaliza a string e interrompe o loop se o contador chegar ao �ndice m�ximo
		if(i == 98 ){
			ficha->descricao[99] = '\0';
			break;
		}
	}
	

//Recebe os dados da categoria do cadastro
//===================================================================

	//reinicializa o contador i
	i = 0;
	int j = 0;
	
	//limpa a tela e exibe a ficha de cadastro
	system("cls");
	printf("%s",titulo);
	printf("Data: %s\t\t\tDescri��o: %s\n\n\n\nCategoria: %s<\t\tValor: %.2f\n\n\n\nDetalhes(opcional): %s",ficha->data,ficha->descricao,ficha->categoria,ficha->valor,ficha->detalhes);
	
	
	//la�o de sele��o da categoria
	while(1){
		
		//vari�vel de controle
		sel = getch()-48;
		
		//interrompre o loop para receber a categoria se a primeira tecla digitada for enter
		if(j == 0  and sel == -35){
			
			break;
			
		}else if(sel == -35 and j !=0){
			
			//recebe o valor selecionado pelo usu�rio
			strcpy(ficha->categoria,categoria[i]);
			ficha->categoria[12] = ' ';
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
		
		//limpa a tela e exibe a ficha de cadastro
		system("cls");
		printf("%s",titulo);
		printf("Data: %s\t\t\tDescri��o: %s\n\n\n\nCategoria: %s\t\tValor: %.2f\n\n\n\nDetalhes(opcional): %s",ficha->data,ficha->descricao,categoria[i],ficha->valor,ficha->detalhes);
		j++;
	}
	
	
//Recebe os dados do valor do cadastro
//===================================================================	
	
	//reinicializa o contador i e o valor
	i = 0;
	strcpy(vlr,"            ");
	
	//limpa a tela e exibe a ficha de cadastro 
	system("cls");
	printf("%s",titulo);
	printf("Data: %s\t\t\tDescri��o: %s\n\n\n\nCategoria: %s\t\tValor: %.2f        <\n\n\n\nDetalhes(opcional): %s",ficha->data,ficha->descricao,ficha->categoria,ficha->detalhes);
	
		
	//loop para inser��o do valor
	while(1){
				
		//inser��o do valor
		fflush(stdin);
		vlr[i] = getch();
		
		//interrompe o loop de entrada do valor se a primeira tecla pessionada n�o for enter 
		if(vlr[0] == 13){
			
			break;
		}
		
		//verifica se a tecla enter foi pressionada
		if(vlr[i] == 13){
			
			//substitui o caractere \n por \0
			vlr[i] = '\0';
			
			//converte e tranfere o valor para o cadastro
			ficha->valor = atof(vlr);
			break;
		
		//verifica se o contador chegou ao valor m�ximo
		}else if(i == 9){
			
			//finaliza a string
			vlr[i] = '\0';
			break;
			
		//finaliza a string se a v�rgula estiver 2 casas antes
		}else if(vlr[i-3] == ','){
			
			//finaliza a string
			vlr[i] = '\0';
			//converte e tranfere o valor para o cadastro
			ficha->valor = atof(vlr);
			break;
		
		}
		
		
		//limpa a tela e exibe a ficha de cadastro 
		system("cls");
		printf("%s",titulo);
		printf("Data: %s\t\t\tDescri��o: %s\n\n\n\nCategoria: %s\t\tValor: %s<\n\n\n\nDetalhes(opcional): %s",ficha->data,ficha->descricao,ficha->categoria,vlr,ficha->detalhes);
		i++;
	
	}
	
		
//Recebe detalhes do cadastro
//===================================================================
	
	//reinicializa��o do contador e da vari�vel de sele��o
	i = 0;
	sel = 0;
	
	//limpa a tela e exibe a ficha de cadastro
	system("cls");
	printf("%s",titulo);
	printf("Data: %s\t\t\tDescri��o: %s\n\n\n\nCategoria: %s\t\tValor: %.2f\n\n\n\nDetalhes(opcional): %s<",ficha->data,ficha->descricao,ficha->categoria,ficha->valor,ficha->detalhes);
	
	
	//declara��o e incializa��o da vari�vel local
	char detalhes[500];
	for(int i = 0;i <500;i++)
		detalhes[i] = ' ';
	
	//loop para inser��o dos destalhes
	while(sel != 13){
		
		//entrada de dados
		fflush(stdin);
		sel = getch();
	
		
		//verifica se o primeiro caractere inserido foi o enter
		if(sel != 13 and i == 0){
						
			//inicializa a vari�vel detalhes
			strcpy(ficha->detalhes,"                     ");
										
		}
		
		//limpa a tela e exibe a ficha de cadastro
		system("cls");
		printf("%s",titulo);
		printf("Data: %s\t\t\tDescri��o: %s\n\n\n\nCategoria: %s\t\tValor: %.2f\n\n\n\nDetalhes(opcional): %s<",ficha->data,ficha->descricao,ficha->categoria,ficha->valor,ficha->detalhes);
		
		//verifica se a tecla digitada foi enter
		if(sel != 13){
		
			//recebe o os detalhes caratere por caractere
			ficha->detalhes[i] = sel;
			
		}else if(sel == 13 or i == 499){
			
			//finaliza a string dos detalhes
			ficha->detalhes[i] = '\0';
		}
		
		i++;
	}	
	
	//verifica se o valor da descri��o possui os valores padr�o
	if((strcmp(ficha->detalhes,"Ex: toalha da mesa..."))==0){
			
		//inicializa a vari�vel detalhes
		for(int j=0;j<500;j++)
			ficha->detalhes[j] = 0;
		
	}
}


//declara��o da fun��o adicionar
//=============================================================================================================================================================

//fun��o para adicionar cadastro na lista
void adicionar(lista_cadastro *list,char titulo[500],char data_sistema[11]){
	
	//aloca��o de mem�ria para o novo cadastro
	lista_cadastro *novo = (lista_cadastro *)malloc(sizeof(lista_cadastro));
	novo->prox = NULL;
	novo->ant = NULL;
	
	//inicializa��o do novo cadastro
	strcpy(novo->descricao,"Ex: arroz,etc...");
	strcpy(novo->categoria,"-------------");
	strcpy(novo->detalhes,"Ex: toalha da mesa...");
	novo->valor = 0;
	
	//chamada da fun��o preencher para receber os valores da nova aloca��o
	preencher(novo,titulo,data_sistema);
	
	//verifica se o cadastro n�o est� vazio ou n�o para adicion�-lo na lista
	if((strcmp(novo->descricao,"Ex: arroz,etc...") != 0) and (strcmp(novo->categoria,"-------------") != 0) and novo->valor != 0){
	
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
