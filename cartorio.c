#include <stdio.h> // bilioteca de comunicação com usuário
#include <stdlib.h> // alocação de memória
#include <locale.h> // texto por região
#include <string.h> // cuidar das strings

int registrar() // função de registrar cpfs
{
	// início de criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das variáveis
	
	system("cls");
	
	printf("Digite o CPF a ser cadastrado: "); //coleta de informação do usuário
	scanf("%s",cpf); // %s refere-se à string
	
	strcpy(arquivo, cpf); // dar o nome do arquivo como cpf
	
	FILE *file; // cria arquivo
	file = fopen(arquivo,"w"); // cria arquivo sendo w (write) para escrever novo
	fprintf(file,cpf); // salva o valor da variável
	fprintf(file,","); // adiciona vírgula para separação
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coleta o nome do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo,"a"); // abre o arquivo na função "a", para atualizar dados
	fprintf(file,nome);// salva o valor da variável nome no arquivo
	fprintf(file,",");// adiciona vírgula
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
	//início das variáveis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) // condição respondendo se a busca for negativa
	{
		printf("Usuário não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // função acessando a variável conteúdo que é diferente de NULL
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file; //função chamando o arquivo .FILE
	file = fopen(cpf,"r"); //acessa o arquivo em modo "r"read
	
	if(file == NULL) // Não havendo match de CPF, executa esta função
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");	
	}
	else
	{ 
		fclose(file);
		remove(cpf);
		printf("O usuário foi deletado com sucesso!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; // Definindo variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	int voltar=1;
	// fim das variáveis
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	while(voltar == 1)
	{
		system ("cls");
		printf("### Cartório da EBAC ###\n\n");
		printf("Login de administrador.\nDigite a senha: ");
		scanf("%s",senhadigitada);
		
		comparacao = strcmp(senhadigitada, "admin"); // essa função salva o valor 0 caso o digitado dentro de senhadigitada for admin
		// strcmp é comparacao de string. sendo igual, retorna valor 0, sendo diferente, valor 1
	
		if(comparacao == 0)
		{
			while(laco == 1) // estrutura de repetição
			{
				system("cls");
				printf("### Cartório da EBAC ###\n\n"); // início do menu
				printf("Escolha no menu qual função deseja utilizar:\n\n");
				printf("\t 1 - Registrar nomes\n");
				printf("\t 2 - Consultar nomes\n");
				printf("\t 3 - Deletar nomes\n");
				printf("\t 4 - Sair do sistema\n\n");
				printf("Opção:"); // fim do menu
			
				scanf("%d", &opcao); // armazenando escolha do usuário
			
				system("cls"); // limpar o terminal
				
				switch(opcao) // início da seleção do menu
				{
					case 1:
					registrar(); // chama de funções
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
					printf("Essa opção não está disponível!\n");
					system("pause");
				}// Fim da seleção
			}//fim função for
		}//fim função if
		else
			printf("Senha incorreta!\n");
		
		system("pause");
		system("cls");
	}
}
	
