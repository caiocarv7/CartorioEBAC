#include <stdio.h> // bilioteca de comunica��o com usu�rio
#include <stdlib.h> // aloca��o de mem�ria
#include <locale.h> // texto por regi�o
#include <string.h> // cuidar das strings

int registrar() // fun��o de registrar cpfs
{
	// in�cio de cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das vari�veis
	
	system("cls");
	
	printf("Digite o CPF a ser cadastrado: "); //coleta de informa��o do usu�rio
	scanf("%s",cpf); // %s refere-se � string
	
	strcpy(arquivo, cpf); // dar o nome do arquivo como cpf
	
	FILE *file; // cria arquivo
	file = fopen(arquivo,"w"); // cria arquivo sendo w (write) para escrever novo
	fprintf(file,cpf); // salva o valor da vari�vel
	fprintf(file,","); // adiciona v�rgula para separa��o
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coleta o nome do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo,"a"); // abre o arquivo na fun��o "a", para atualizar dados
	fprintf(file,nome);// salva o valor da vari�vel nome no arquivo
	fprintf(file,",");// adiciona v�rgula
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	//in�cio das vari�veis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) // condi��o respondendo se a busca for negativa
	{
		printf("Usu�rio n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // fun��o acessando a vari�vel conte�do que � diferente de NULL
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file; //fun��o chamando o arquivo .FILE
	file = fopen(cpf,"r"); //acessa o arquivo em modo "r"read
	
	if(file == NULL) // N�o havendo match de CPF, executa esta fun��o
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");	
	}
	else
	{ 
		fclose(file);
		remove(cpf);
		printf("O usu�rio foi deletado com sucesso!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; // Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	int voltar=1;
	// fim das vari�veis
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	while(voltar == 1)
	{
		system ("cls");
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Login de administrador.\nDigite a senha: ");
		scanf("%s",senhadigitada);
		
		comparacao = strcmp(senhadigitada, "admin"); // essa fun��o salva o valor 0 caso o digitado dentro de senhadigitada for admin
		// strcmp � comparacao de string. sendo igual, retorna valor 0, sendo diferente, valor 1
	
		if(comparacao == 0)
		{
			while(laco == 1) // estrutura de repeti��o
			{
				system("cls");
				printf("### Cart�rio da EBAC ###\n\n"); // in�cio do menu
				printf("Escolha no menu qual fun��o deseja utilizar:\n\n");
				printf("\t 1 - Registrar nomes\n");
				printf("\t 2 - Consultar nomes\n");
				printf("\t 3 - Deletar nomes\n");
				printf("\t 4 - Sair do sistema\n\n");
				printf("Op��o:"); // fim do menu
			
				scanf("%d", &opcao); // armazenando escolha do usu�rio
			
				system("cls"); // limpar o terminal
				
				switch(opcao) // in�cio da sele��o do menu
				{
					case 1:
					registrar(); // chama de fun��es
					break;
					
					case 2:
					consultar();
					break;
					
					case 3:
					deletar();
					break;
					
					case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
					
					default:
					printf("Essa op��o n�o est� dispon�vel!\n");
					system("pause");
				}// Fim da sele��o
			}//fim fun��o for
		}//fim fun��o if
		else
			printf("Senha incorreta!\n");
		
		system("pause");
		system("cls");
	}
}
	
