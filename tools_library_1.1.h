//declara��o da fun��o recebe_data
//=============================================================================================================================================================

//fun��o para ler a data do cadastro
void recebe_data(char recebe[11],char titulo[500]){
	
	//vari�vel inicial
	char data[11];
	
	//recebe o dia
	printf("Data: ");
	fflush(stdin);
	fgets(data,11,stdin);

	//verifica se a primeira tecla pressionada foi enter
	if(data[0] != '\n'){
		
		//recebe a data
		strcpy(recebe,data);
		//finaliza a string da data
		recebe[10] = '\0';
		
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
void alterar(char categoria[8][14],lista_cadastro *ficha,char titulo[500],char data_sistema[11]){
	
	//variaveis locais
	lista_cadastro *temp = ficha->prox;
	char busca_data[11],busca_categoria[15];	
	int i = 0;
	float valor = 0;
	
	//inicializa��o de vari�veis
	strcpy(busca_data,"__/__/____");
	strcpy(busca_categoria,"-------------");
	
	//verifica se a lista de structs est� ou n�o vazia
	if(ficha->prox == NULL){
			
			//altera a cor do texto para vermelho
			system("COLOR 0C");
			
			//limpa a tela e exibe uma menssagem informativa
			system("cls");
			printf("\n\n\n\t\t\t\tN�o existem cadastros na lista!!!");
			sleep (2);
		
	}else{

//recebe a data para busca
		
		//limpa a tela e exibe o t�tulo
		system("cls");
		printf("%s",titulo);
			
		//exibe a variavel busca_data
		printf("Informe a data do cadastro \n");
		
		//recebe a data	
		recebe_data(busca_data,titulo);

//recebe a categoria para busca
		
		printf("\n\nInforme a categoria do cadastro \nCategoria: ");
							
		//inicializa os �ndices da matriz de categorias
		i = 0;
		int j = 0;
		char sel;		
		//la�o de sele��o da categoria
		while(1){
					
			//vari�vel de controle
			fflush(stdin);
			sel = getch()-48;
				
			//interrompre o loop para receber a categoria se a primeira tecla digitada for enter
			if(j == 0  and sel == -35){
				
				printf("\nCategoria: %s\n\n",busca_categoria);
				break;
						
			}else if(sel == -35 and j !=0){
						
				//recebe o valor selecionado pelo usu�rio
				strcpy(busca_categoria,categoria[i]);
				busca_categoria[12] = ' ';
				system("cls");
				printf("%s",titulo);
				printf("Informe a data do cadastro \nData: %s\n\nInforme a categoria do cadastro \nCategoria: %s\n\n",busca_data,busca_categoria);
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
			printf("Informe a data do cadastro \nData: %s\n\n\nInforme a categoria do cadastro \nCategoria: %s",busca_data,categoria[i]);
			j++;
		}
		
//recebe o valor para busca
		
		//limpa a tela e exibe o t�tulo
		system("cls");
		printf("%s",titulo);
		printf("Informe a data do cadastro \nData: %s\n\n\nInforme a categoria do cadastro \nCategoria: %s\n\n\nInforme o valor do cadastro \nValor: ",busca_data,busca_categoria);
		
		//recebe o valor para busca
		scanf("%f",&valor);

//efetua a busca e sele��o do cadastro indicado para edi��o
//=============================================================================================================================================================

		//string vazia
		char cabecalho[500];
		strcpy(cabecalho,titulo);
		strcat(cabecalho,"Aperte enter para manter os dados que aparecem nos campos ou digite novos dados: \n\n\n");
	
		//loop para busca e compara��o 
		while(temp->prox != NULL){
			
			if((strcmp(busca_data,temp->data)) == 0 and (strcmp(busca_categoria,temp->categoria)) == 0 and (valor == temp->valor)){
				
				//recebe a nova data
				system("cls");
				printf("%s",titulo);
				recebe_data(temp->data,cabecalho);
				
				//recebe os novos valores da struct selecionada na lista
				system("cls");
				preencher(categoria,temp,cabecalho,temp->data);
				break;
			}
			temp = temp->prox;
		}

		//verifica se o cadastro procurado se encontra na �ltima posi��o da lista
		if((temp->prox == NULL) and (strcmp(busca_data,temp->data)) == 0 and (strcmp(busca_categoria,temp->categoria)) == 0 and (valor == temp->valor)){
				
				//recebe a nova data
				system("cls");
				printf("%s",titulo);
				recebe_data(temp->data,cabecalho);
				
				//recebe os novos valores da struct selecionada na lista
				system("cls");
				preencher(categoria,temp,cabecalho,temp->data);
				
		//se n�o for encontrado nenhum cadastro com os dados informados	
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
