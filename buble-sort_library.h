//declara��o da fun��o ord_date
//=============================================================================================================================================================

//fun��o de ordena��o por date
void ord_date(list_cad *ordena){
	
	//vari�veis locais
	list_cad *teste = ordena->prox;
	
	//indicador de passagem do loop
	int marcador = -5;
	
	//verifica se a lista de structs est� vazia
	if(teste->prox != NULL){
		
		//vari�veis tempor�rias para percorrer e ordenar a lista
		list_cad *temp1, *temp2;
		
		//loop secund�rio de verifica��o de ordena��o 
		while(marcador !=0){
			
			//atribui��o de valuees das vari�veis tempor�rias
			temp1 = ordena->prox;
			temp2 = temp1->prox;
			
			//contador para verificar se a lista possui termos desordenados
			marcador = 0;
			
			//loop prim�rio de ordena��o 
		 	while(temp2->prox != NULL){
				
				//verifica se o segundo item � menor que o primeiro	
				if(strcmp(temp2->date,temp1->date)<0){
			 		
					temp1->prox = temp2->prox;
					temp2->prox->ant = temp1;
					temp2->ant = temp1->ant;
					temp1->ant->prox = temp2;
					temp1->ant = temp2;
					temp2->prox = temp1;
					
					marcador++;
	
				}
				
				//reatribui��o de valuees das vari�veis tempor�rias
				temp1 = temp2;
				temp2 = temp2->prox;
			
			}
			
			//verifica��o de termos desordenados ao fim da lista
			if((temp2->prox == NULL ) && (strcmp(temp2->date,temp1->date)<0)){
				 
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

//declara��o da fun��o ord_value
//=============================================================================================================================================================

//fun��o de ordena��o por value
void ord_value(list_cad *ordena2){
	
	//vari�veis locais
	list_cad *teste = ordena2->prox;
	
	//indicador de passagem do loop
	int marcador = -5;
	
	//verifica se a lista de structs est� vazia
	if(teste->prox != NULL){
		
		//vari�veis tempor�rias para percorrer e ordenar a lista
		list_cad *temp1, *temp2;
		
		//loop secund�rio de verifica��o de ordena��o 
		while(marcador !=0){
			
			//atribui��o de valuees das vari�veis tempor�rias
			temp1 = ordena2->prox;
			temp2 = temp1->prox;
			
			//contador para verificar se a lista possui termos desordenados
			marcador = 0;
			
			//loop prim�rio de ordena��o 
		 	while(temp2->prox != NULL){
				
				//verifica se o segundo item � menor que o primeiro	
				if(temp2->value < temp1->value){
			 		
					temp1->prox = temp2->prox;
					temp2->prox->ant = temp1;
					temp2->ant = temp1->ant;
					temp1->ant->prox = temp2;
					temp1->ant = temp2;
					temp2->prox = temp1;
					
					marcador++;
				 	
				}
				
				//reatribui��o de valuees das vari�veis tempor�rias
				temp1 = temp2;
				temp2 = temp2->prox;
			
			}
			
			//verifica��o de termos desordenados ao fim da lista
			if((temp2->prox == NULL ) && (temp2->value < temp1->value)){
				 
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

//declara��o da fun��o ord_category
//=============================================================================================================================================================

//fun��o de ordena��o por date
void ord_category(list_cad *ordena){
	
	//vari�veis locais
	list_cad *teste = ordena->prox;
	
	//indicador de passagem do loop
	int marcador = -5;
	
	//verifica se a lista de structs est� vazia
	if(teste->prox != NULL){
		
		//vari�veis tempor�rias para percorrer e ordenar a lista
		list_cad *temp1, *temp2;
		
		//loop secund�rio de verifica��o de ordena��o 
		while(marcador !=0){
			
			//atribui��o de valuees das vari�veis tempor�rias
			temp1 = ordena->prox;
			temp2 = temp1->prox;
			
			//contador para verificar se a lista possui termos desordenados
			marcador = 0;
			
			//loop prim�rio de ordena��o 
		 	while(temp2->prox != NULL){
				
				//verifica se o segundo item � menor que o primeiro	
				if(strcmp(temp2->category,temp1->category)<0){
			 		
					temp1->prox = temp2->prox;
					temp2->prox->ant = temp1;
					temp2->ant = temp1->ant;
					temp1->ant->prox = temp2;
					temp1->ant = temp2;
					temp2->prox = temp1;
					
					marcador++;
	
				}
				
				//reatribui��o de valuees das vari�veis tempor�rias
				temp1 = temp2;
				temp2 = temp2->prox;
			
			}
			
			//verifica��o de termos desordenados ao fim da lista
			if((temp2->prox == NULL ) && (strcmp(temp2->category,temp1->category)<0)){
				 
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
