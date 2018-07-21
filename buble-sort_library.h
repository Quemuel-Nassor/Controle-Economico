//declara��o da fun��o ord_data
//=============================================================================================================================================================

//fun��o de ordena��o por data
void ord_data(lista_cadastro *ordena){
	
	//vari�veis locais
	lista_cadastro *teste = ordena->prox;
	
	//indicador de passagem do loop
	int marcador = -5;
	
	//verifica se a lista de structs est� vazia
	if(teste->prox != NULL){
		
		//vari�veis tempor�rias para percorrer e ordenar a lista
		lista_cadastro *temp1, *temp2;
		
		//loop secund�rio de verifica��o de ordena��o 
		while(marcador !=0){
			
			//atribui��o de valores das vari�veis tempor�rias
			temp1 = ordena->prox;
			temp2 = temp1->prox;
			
			//contador para verificar se a lista possui termos desordenados
			marcador = 0;
			
			//loop prim�rio de ordena��o 
		 	while(temp2->prox != NULL){
				
				//verifica se o segundo item � menor que o primeiro	
				if(strcmp(temp2->data,temp1->data)<0){
			 		
					temp1->prox = temp2->prox;
					temp2->prox->ant = temp1;
					temp2->ant = temp1->ant;
					temp1->ant->prox = temp2;
					temp1->ant = temp2;
					temp2->prox = temp1;
					
					marcador++;
	
				}
				
				//reatribui��o de valores das vari�veis tempor�rias
				temp1 = temp2;
				temp2 = temp2->prox;
			
			}
			
			//verifica��o de termos desordenados ao fim da lista
			if((temp2->prox == NULL ) and (strcmp(temp2->data,temp1->data)<0)){
				 
				 	temp1->prox = temp2->prox;
				 	temp2->prox = temp1;
				 	temp2->ant = temp1->ant;
				 	temp1->ant = temp2;
				 	temp2->ant->prox = temp2;
				 	marcador++;
				
			}
		}
	}
}

//declara��o da fun��o ord_valor
//=============================================================================================================================================================

//fun��o de ordena��o por valor
void ord_valor(lista_cadastro *ordena2){
	
	//vari�veis locais
	lista_cadastro *teste = ordena2->prox;
	
	//indicador de passagem do loop
	int marcador = -5;
	
	//verifica se a lista de structs est� vazia
	if(teste->prox != NULL){
		
		//vari�veis tempor�rias para percorrer e ordenar a lista
		lista_cadastro *temp1, *temp2;
		
		//loop secund�rio de verifica��o de ordena��o 
		while(marcador !=0){
			
			//atribui��o de valores das vari�veis tempor�rias
			temp1 = ordena2->prox;
			temp2 = temp1->prox;
			
			//contador para verificar se a lista possui termos desordenados
			marcador = 0;
			
			//loop prim�rio de ordena��o 
		 	while(temp2->prox != NULL){
				
				//verifica se o segundo item � menor que o primeiro	
				if(temp2->valor < temp1->valor){
			 		
					temp1->prox = temp2->prox;
					temp2->prox->ant = temp1;
					temp2->ant = temp1->ant;
					temp1->ant->prox = temp2;
					temp1->ant = temp2;
					temp2->prox = temp1;
					
					marcador++;
				 	
				}
				
				//reatribui��o de valores das vari�veis tempor�rias
				temp1 = temp2;
				temp2 = temp2->prox;
			
			}
			
			//verifica��o de termos desordenados ao fim da lista
			if((temp2->prox == NULL ) and (temp2->valor < temp1->valor)){
				 
				 	temp1->prox = temp2->prox;
				 	temp2->prox = temp1;
				 	temp2->ant = temp1->ant;
				 	temp1->ant = temp2;
				 	temp2->ant->prox = temp2;
				 	marcador++;
				 
			}
		}
	}
}

//declara��o da fun��o ord_categoria
//=============================================================================================================================================================

//fun��o de ordena��o por data
void ord_categoria(lista_cadastro *ordena){
	
	//vari�veis locais
	lista_cadastro *teste = ordena->prox;
	
	//indicador de passagem do loop
	int marcador = -5;
	
	//verifica se a lista de structs est� vazia
	if(teste->prox != NULL){
		
		//vari�veis tempor�rias para percorrer e ordenar a lista
		lista_cadastro *temp1, *temp2;
		
		//loop secund�rio de verifica��o de ordena��o 
		while(marcador !=0){
			
			//atribui��o de valores das vari�veis tempor�rias
			temp1 = ordena->prox;
			temp2 = temp1->prox;
			
			//contador para verificar se a lista possui termos desordenados
			marcador = 0;
			
			//loop prim�rio de ordena��o 
		 	while(temp2->prox != NULL){
				
				//verifica se o segundo item � menor que o primeiro	
				if(strcmp(temp2->categoria,temp1->categoria)<0){
			 		
					temp1->prox = temp2->prox;
					temp2->prox->ant = temp1;
					temp2->ant = temp1->ant;
					temp1->ant->prox = temp2;
					temp1->ant = temp2;
					temp2->prox = temp1;
					
					marcador++;
	
				}
				
				//reatribui��o de valores das vari�veis tempor�rias
				temp1 = temp2;
				temp2 = temp2->prox;
			
			}
			
			//verifica��o de termos desordenados ao fim da lista
			if((temp2->prox == NULL ) and (strcmp(temp2->categoria,temp1->categoria)<0)){
				 
				 	temp1->prox = temp2->prox;
				 	temp2->prox = temp1;
				 	temp2->ant = temp1->ant;
				 	temp1->ant = temp2;
				 	temp2->ant->prox = temp2;
				 	marcador++;
				
			}
		}
	}
}
