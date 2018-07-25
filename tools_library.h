//declara��o da fun��o recebe_data
//=============================================================================================================================================================

//fun��o para ler a data do cadastro
void recebe_data(lista_cadastro *ficha,char titulo[500]){
	
	//vari�vel local
	int i = 1;
	char tecla;
	
	//exibe o cabe�alho e o informativo
	printf("%s",titulo);
	printf("Data: %s<\t\t\tDescri��o: %s\n\n\n\nCategoria: %s\t\tValor: %.2f\n\n\n\nDetalhes(opcional): %s",ficha->data,ficha->descricao,ficha->categoria,ficha->valor,ficha->detalhes);
	
	fflush(stdin);
	tecla = getch();
	
	if(tecla != 13){
			
		//loop para receber a data 
		while(i<10){
			
			//recebe o primeiro d�gito
			ficha->data[0] = tecla;
			
			//insere as barras de separa��o, ex: dd/mm/aa
			if (i == 2 or i == 5){
				
				ficha->data[i] = '/';
			
			}else{
				//recebe cada caractere da data
				fflush(stdin);
				ficha->data[i] = getch();
			}
			
			//exibe a variavel busca_data
			system("cls");
			printf("%s",titulo);
			printf("Data: %s<\t\t\tDescri��o: %s\n\n\n\nCategoria: %s\t\tValor: %.2f\n\n\n\nDetalhes(opcional): %s",ficha->data,ficha->descricao,ficha->categoria,ficha->valor,ficha->detalhes);
			i++;
		}
		//finaliza a string da data
		ficha->data[10] = '\0';
		fflush(stdin);
		getch();
	}
}


//declara��o da fun��o listar
//=============================================================================================================================================================

//fun��o para exibir a lista de cadastros
void listar(lista_cadastro *ficha){
	
	//ponteiro tempor�rio para percorrer a lista
	lista_cadastro *temp = ficha->prox;
	
	//vari�vel para exibir a soma total
	float total = 0;
	
	//verifica se a lista de structs est� ou n�o vazia
	if(temp != NULL){
		
		printf("-----------------------------------------------------------------------------------------------------------\n");
		//loop para exibi��o da struct
		while(temp->prox!=NULL){
			
			//exibe os dados do cadastro
			printf("Data: %s      ",temp->data);
			printf("Categoria: %s      ",temp->categoria);
			printf("Descri��o: %s\n\n",temp->descricao);
			printf("Valor: %.2f      ",temp->valor);
			printf("Detalhes: %s\n",temp->detalhes);
			printf("-----------------------------------------------------------------------------------------------------------\n");
			
			total += temp->valor;
			
			temp = temp->prox;
		}
		
		
		//exibe os dados do cadastro da struct na �ltima posi��o da lista
		printf("Data: %s      ",temp->data);
		printf("Categoria: %s      ",temp->categoria);
		printf("Descri��o: %s\n\n",temp->descricao);
		printf("Valor: %.2f      ",temp->valor);
		printf("Detalhes: %s\n",temp->detalhes);
		printf("-----------------------------------------------------------------------------------------------------------\n");
		
		total += temp->valor;
		
		printf("\n   ===========================\n    Total: %.2f   \n   ===========================\n",total);
	}
	
	total = 0;
}

//declara��o da fun��o alterar
//=============================================================================================================================================================

//fun��o para alterar cadastro
void alterar(lista_cadastro *ficha,char titulo[500],char data_sistema[11]){
	
	//variaveis locais
	lista_cadastro *temp = ficha->prox;
	char busca_data[11],busca_categoria[15];	
	int i = 0;
	float valor;
	
	//inicializa��o de vari�veis
	strcpy(busca_data,"__/__/____");
	strcpy(busca_categoria,"---------------");
	
	//verifica se a lista de structs est� ou n�o vazia
	if(ficha->prox == NULL){
			
			//altera a cor do texto para vermelho
			system("COLOR 0C");
			
			//limpa a tela e exibe uma menssagem informativa
			system("cls");
			printf("\n\n\n\t\t\t\tN�o existem cadastros na lista!!!");
			sleep (2);
		
	}else{
		
		//limpa a tela e exibe o t�tulo
		system("cls");
		printf("%s",titulo);
			
		//exibe a variavel busca_data
		printf("Informe a data do cadastro: %s\n",busca_data);
			
		//loop para receber a data 
		while(i<10){
			
			//insere as barras de separa��o, ex: dd/mm/aa
			if (i == 2 or i == 5){
				busca_data[i] = '/';
			}else{
				//recebe cada caractere da data
				fflush(stdin);
				busca_data[i] = getch();
			}
			//limpa a tela e exibe o t�tulo
			system("cls");
			printf("%s",titulo);
		
			//exibe a variavel busca_data
			printf("Informe a data do cadastro: %s\n",busca_data);
			i++;
		}
		fflush(stdin);
		getch();
		
		//limpa a tela e exibe o t�tulo
		system("cls");
		printf("%s",titulo);
					
		//recebe a categoria para busca
		printf("\nInforme a categoria do cadastro: ");
		fgets(busca_categoria,15,stdin);
		
		//inicializa o contador na primeira posi��o em branco
		i = strlen(busca_categoria)-1;
		
		//loop para preencher o restante da string com espa�os em branco
		while(i<13){
			
			busca_categoria[i] = ' ';
			i++;
		}
		
		//finaliza a string 
		busca_categoria[13] = '\0';
		
		//limpa a tela e exibe o t�tulo
		system("cls");
		printf("%s",titulo);
		
		//recebe o valor para busca
		printf("Informe o valor do cadastro: ");
		scanf("%f",&valor);
		
		//string vazia
		char cabecalho[500];
		strcpy(cabecalho,titulo);
		strcat(cabecalho,"Aperte enter para manter os dados que aparecem nos campos ou digite novos dados!\n\n\n\n");
	
		//loop para busca e compara��o 
		while(temp->prox != NULL){
			
			if((strcmp(busca_data,temp->data)) == 0 and (strcmp(busca_categoria,temp->categoria)) == 0 and (valor == temp->valor)){
				
				//recebe a nova data
				system("cls");
				recebe_data(temp,cabecalho);
				
				//recebe os novos valores da struct selecionada na lista
				system("cls");
				preencher(temp,cabecalho,temp->data);
				break;
			}
			temp = temp->prox;
		}

		//verifica se o cadastro procurado se encontra na �ltima posi��o da lista
		if((temp->prox == NULL) and (strcmp(busca_data,temp->data)) == 0 and (strcmp(busca_categoria,temp->categoria)) == 0 and (valor == temp->valor)){
				
				//recebe a nova data
				system("cls");
				recebe_data(temp,cabecalho);
				
				//recebe os novos valores da struct selecionada na lista
				system("cls");
				preencher(temp,cabecalho,temp->data);
				
			
		}else if((temp->prox == NULL) and (strcmp(busca_data,temp->data)) != 0 and (strcmp(busca_categoria,temp->categoria)) != 0 and (valor != temp->valor)){
			
			//altera a cor do texto para vermelho
			system("COLOR 0C");
			
			//feedback de cadastro n�o encontrado	
			system("cls");
			printf("\n\n\n\t\t\t\tN�o encontramos nada, por favor verifique os dados da busca tente novamente!");
			sleep (2);			
		}
	}
}
