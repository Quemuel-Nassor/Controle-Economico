//declara��o de bibliotecas nativas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<locale.h>
#include<unistd.h>

//===================================================================
//ponteiro para arquivos de texto
FILE *base_dados,*locais;

//===================================================================
//estrutura de cadastro dos dados para listas
typedef struct lista_dados{
	
	struct lista_dados *ant; //ponteiro para posi��o anterior
	struct lista_dados *prox; //ponteiro para posi��o seguinte
	char data[11];		//ex: 05/11/2002...
	char descricao[100];//ex: arroz, carne....
	char categoria[14];	//ex: aliment�cio, inform�tica, material escolar....
	float valor;		//ex: 4.67 R$...
	char detalhes[500]; //ex: teclado para computador .....
	
}lista_cadastro;

//===================================================================
//declara��o de bibliotecas exclusivas
#include"cad_library.h"
#include"load_library.h"
#include"tools_library.h"
#include"buble-sort_library.h"


//vari�veis globais
char data_sistema[11],mes[11],ano[7];
char pasta[25],verifica[14];

//declara��o da fun��o principal
//=============================================================================================================================================================
int main(){

//Configura o nome da janela e acentua��o
//===================================================================
	
	//habilita a acentua��o com base na localidade padr�o do sistema
	setlocale(LC_ALL,"");
	
	//renomeia a janela do terminal
	system ("title Controle Econ�mico");


//Recebe a data do sistema
//===================================================================	
	//estrutura para obter a data do sistema
	struct tm * tm;
	time_t t;
	time(&t);
	tm = localtime(&t);
	
	//recebe a data no formato dd-mm-aa
	strftime(data_sistema, 11, "%d-%m-%Y", tm);
	
	//formata��o da data
	data_sistema[2] = data_sistema[5] = '/';
	
	//recebe o m�s que ser� utilizado para nomear a base de dados
	strftime(mes, 11, "%B", tm);
	
	//recebe caminho que ser� utilizado para nomear o diret�rio de armazenamento da base de dados
	strftime(ano, 5, "%Y", tm);
	
//Concatena comandos e nomes para diret�rios e arquivos da base de dados
//===================================================================	

	//copia o comando para criar o diret�rio principal de armazenamento da base de dados
	strcpy(pasta,"mkdir Database\\");
		
	//recebe o nome do diret�rio de armazenamento da base de dados
	strcat(pasta,ano);
		
	//concatena barras para posterior acesso ao diret�rio de armazenamento da base de dados ex: '2014\\outubro.txt'
	strcat(ano,"\\");
	
	//adiciona o caminho, a extens�o e o nome do arquivo de verifica��o
	strcpy(verifica,"Database\\");
	strcat(verifica,ano);
	strcat(verifica,"directory_scan");
	strcat(verifica,".mdf");
	
//Verifica��o da exist�ncia do diret�rio da base de dados
//===================================================================
	
	//verifica se o diret�rio j� existe
	if((base_dados = fopen(verifica,"rb")) == NULL){
		
		//cria uma pasta para armazenar a base de dados 
		system(pasta);
		
		//cria o arquivo de verifica��o
		base_dados = fopen(verifica,"wb");
		
		//adiciona o novo ano ao arquivo lista_anos
		locais = fopen("Database\\lista_anos.txt","a");
		
		//grava o novo ano no arquivo
		fprintf(locais,"%s",ano);
		fprintf(locais,"%c",'\n');
		
		//fecha o arquivo de lista_anos
		fclose(locais);
		
		//fecha o arquivo de verifica��o
		fclose(base_dados);
		
	}
	
//Estrutura do menu
//===================================================================
	
	//declara��o de vari�veis locais
	int sel = -1;
	char titulo[366];
	char sel_mes[11];
	char sel_ano[7];
	
	//cria um cabe�alho para o programa
	strcpy(titulo,"***********************************************************************************************************************\n\n*****************************************| Controle Econ�mico |********************************************************\n\n***********************************************************************************************************************\n\n\n\n");
	
	//declara��o da ficha de cadastro(refer�ncia do in�cio da lista)
	lista_cadastro *lista_cad = (lista_cadastro *)malloc(sizeof(lista_cadastro));
	lista_cad->prox = NULL;
	lista_cad->ant = NULL;
	
	//recebe o m�s e ano atual
	strcpy(sel_mes,mes);
	strcpy(sel_ano,ano);
	
	//loop do menu	
	while(1){
		
		//mant�m a cor do texto verde
		system("COLOR 0A");
		
		//carrega dados dos arquivos para a lista
		carregar(lista_cad,base_dados,sel_mes,sel_ano);
		
		//exibe o menu de op��es para sele��o
		system("cls");
		printf("%s",titulo);
		printf("Selecione uma op��o:\n\n1 - Novo cadastro \n2 - Exibir cadastros \n3 - Alterar cadastro\n4 - Alternar base de dados\n5 - Sobre\n6 - Sair");
		
		fflush(stdin);
		sel = getch()-48;
			
		//estrutura para direcionamento da op��o selecionada	
		switch(sel){
			
			case 1:{
				
				system("cls");
				//realiza um novo cadastro
				adicionar(lista_cad,titulo,data_sistema);
				//grava a lista em arquivos
				descarregar(lista_cad,base_dados,sel_mes,sel_ano);	
				break;
			}
			
			case 2:{
				
				//verifica se a lista est� vazia ou n�o 
				if(lista_cad->prox == NULL){
					
					//altera a cor do texto para vermelho
					system("COLOR 0C");
			
					//feedback de lista vazia
					system("cls");
					printf("\n\n\n\t\t\t\tN�o existem cadastros na lista!!!");
					sleep (2);
					
				}else{
				
					//reinicializa a vari�vel de sele��o
					sel = 1;
					
					//vari�vel de eibi��o do submenu
					char submenu[220];
					
					//inicializa o submenu
					strcpy(submenu,"\n\n  ================================\n |   1 - Ordenar por data         |\n |   2 - Ordenar por valor        |\n |   3 - Ordenar por categoria    |\n |   ESC - Retornar ao menu       |\n  ================================\n");
					
					while(1){
							
						//mant�m a cor do texto verde
						system("COLOR 0A");
						
						if(sel == 1){
							
							//ordena a lista por data
							ord_data(lista_cad);
							//exibe a lista de cadastros ordenados por data
							system("cls");
							printf("%s",titulo);
							listar(lista_cad);
							printf("%s",submenu);
							
						}else if(sel == 2){
						
							//ordena a lista por valor
							ord_valor(lista_cad);
							//exibe a lista de cadastros ordenados por valor
							system("cls");
							printf("%s",titulo);
							listar(lista_cad);
							printf("%s",submenu);
							
						}else if(sel == 3){
							
							//ordena por categoria
							ord_categoria(lista_cad);
							//exibe a lista de cadastros ordenados por categoria
							system("cls");
							printf("%s",titulo);
							listar(lista_cad);
							printf("%s",submenu);
						}
						
						//recebe as op��es do menu de exibi��o
						fflush(stdin);
						sel = getch()-48;
						
						if(sel == -21){
							//sai do menu de exibi��o da lista
							break;
							
						}
						
						if(sel != 1 and sel != 2 and sel != -21 and sel !=3){
							
							//altera a cor do texto para vermelho
							system("COLOR 0C");
							
							//feedback default
							system("cls");
							printf("\n\n\n\t\t\t\tOp��o inv�lida!");
							sleep (1);
							sel = 1;
							
							
						}
					}
				}
				break;
			}
			
			case 3:{
				system("cls");
				printf("%s",titulo);
				//altera um cadastro
				alterar(lista_cad,titulo,data_sistema);
				//grava a lista em arquivos
				descarregar(lista_cad,base_dados,sel_mes,sel_ano);		
				break;
			}
			
			case 4:{
				
				//permite o acesso a dados de outros per�odos
				system("cls");
				printf("%s",titulo);	
							
				//alterna a base de dados que o usu�rio deseja utilizar
				alt_base_dados(sel_mes,sel_ano,titulo,locais);
								
				break;
			}
				
			case 5:{
				//adicionais
				system("cls");
				printf("%s",titulo);
				printf("Este software � destinado para uso pessoal.\nN�o � recomendado o uso ambientes empresariais !!!\n\n");
				printf("Desenvolvedor: Quemuel Alves Nassor\n\nContato ou suporte: quemuelalp@hotmail.com\n\nVers�o: 1.0.1");
				fflush(stdin);
				getch();
				
				break;
			}
			
			case 6:{
				
				//sair do programa
				system("cls");
				exit(0);
				break;
			}
				
			default:
				
				//muda a cor do texto para vermelho
				system("COLOR 0C");
				
				//feedback default
				system("cls");
				printf("\n\n\n\t\t\t\tOp��o inv�lida!");
				sleep(1);
				
		}
		//libera��o da mem�ria alocada na lista
		desaloca(lista_cad);
					
	}
	
	return(0);
}
