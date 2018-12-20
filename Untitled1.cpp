#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>
#include <string.h>

#define tam 10

void le();
void verifica();
void cadastrar();
void excluir();
void listar();
void locar();
void devolver();
void listar_ativos();
bool r[tam];
char s_aux[100];
char conv_esp_und(char s[]);
char conv_und_esp(char s[]);

struct Cliente{
	int codigo;				//Código do cliente.
	char nome[100];			//Nome do cliente.
	char sexo[20];			//Sexo do cliente.
	char nascimento[20];	//Data de nascimento do cliente.
	char rg[20];			//Número RG do cliente.
	char cpf[25];			//Número CPF do cliente.
	char endereco[100];		//Endereço do cliente.
	char cidade[100];		//Cidade em que mora o cliente.
	char estado[100];		//Estado em que mora o cliente.
	int locacoes;			//Número total de locações do cliente.
	int dvd;				//Número de DVDs locados atualmente pelo cliente.
	bool i;
}cliente[tam],*pc[tam];


FILE *C[tam];

FILE *BD = fopen("Banco de Dados.txt","r");
	

int main(void)
{
	if(BD == NULL)
	{
		BD = fopen("Bando de Dados.txt","w");
	}
	le();
	int op;
	setlocale(LC_ALL,"portuguese");
	op=0;
	printf("=================   LocaMais   =================\n");
	printf("=                                              =\n");
	printf("=  ================   Menu   ================  =\n");
	printf("=                                              =\n");
	printf("=  1 - Cadastrar Clientes                      =\n");
	printf("=  2 - Listar Clientes                         =\n");
	printf("=  3 - Excluir Clientes                        =\n");
	printf("=  4 - Efetuar Locação                         =\n");
	printf("=  5 - Efetuar Devolução                       =\n");
	printf("=  6 - Listar Clientes Ativos                  =\n");
	printf("=  7 - Sair                                    =\n");
	printf("=                                              =\n");
	printf("================================================\n");
	printf("\n");
	printf("=  ");
	scanf("%i", &op);
	
	while(op > 7 || op < 1)
	{
		printf("\n= Entrada inválida! tente novamente: ");
		scanf("%i",&op);
	}
	
	switch (op)
	{
		case 1:
			cadastrar();
			break;
		case 2:
			listar();
			break;
		case 3:
			excluir();
			break;
		case 4:
			locar();
			break;
		case 5:
			devolver();
			break;
		case 6:
			listar_ativos();
			break;
		case 7:
			exit(0);
			break;
	}
	return 0;
	
	
}


void le()
{
	C[0] = fopen("Cliente - 01.txt","r");
	if(C[0] != NULL)
	{
		fscanf(C[0],"%i %s %s %s %s %s %s %s %s %i %i",
		&cliente[0].codigo, &cliente[0].nome, &cliente[0].sexo,
		&cliente[0].nascimento, &cliente[0].rg, &cliente[0].cpf,
		&cliente[0].endereco, &cliente[0].cidade, &cliente[0].estado,
		&cliente[0].locacoes, &cliente[0].dvd);
		fclose(C[0]);
		conv_und_esp(cliente[0].nome);
		conv_und_esp(cliente[0].endereco);
		conv_und_esp(cliente[0].cidade);
		conv_und_esp(cliente[0].estado);
		if(cliente[0].i == 1)
		remove("Cliente - 01.txt");
	}
	
	C[1] = fopen("Cliente - 02.txt","r");
	if(C[1] != NULL)
	{
		fscanf(C[1],"%i %s %s %s %s %s %s %s %s %i %i",
		&cliente[1].codigo, &cliente[1].nome, &cliente[1].sexo,
		&cliente[1].nascimento, &cliente[1].rg, &cliente[1].cpf,
		&cliente[1].endereco, &cliente[1].cidade, &cliente[1].estado,
		&cliente[1].locacoes, &cliente[1].dvd);
		fclose(C[1]);
		conv_und_esp(cliente[1].nome);
		conv_und_esp(cliente[1].endereco);
		conv_und_esp(cliente[1].cidade);
		conv_und_esp(cliente[1].estado);
		if(cliente[1].i == 1)
		remove("Cliente - 02.txt");
	}
	
	C[2] = fopen("Cliente - 03.txt","r");
	if(C[2] != NULL)
	{
		fscanf(C[2],"%i %s %s %s %s %s %s %s %s %i %i",
		&cliente[2].codigo, &cliente[2].nome, &cliente[2].sexo,
		&cliente[2].nascimento, &cliente[2].rg, &cliente[2].cpf,
		&cliente[2].endereco, &cliente[2].cidade, &cliente[2].estado,
		&cliente[2].locacoes, &cliente[2].dvd);
		fclose(C[2]);
		conv_und_esp(cliente[2].nome);
		conv_und_esp(cliente[2].endereco);
		conv_und_esp(cliente[2].cidade);
		conv_und_esp(cliente[2].estado);
		if(cliente[2].i == 1)
		remove("Cliente - 03.txt");
	}
	
	C[3] = fopen("Cliente - 04.txt","r");
	if(C[3] != NULL)
	{
		fscanf(C[3],"%i %s %s %s %s %s %s %s %s %i %i",
		&cliente[3].codigo, &cliente[3].nome, &cliente[3].sexo,
		&cliente[3].nascimento, &cliente[3].rg, &cliente[3].cpf,
		&cliente[3].endereco, &cliente[3].cidade, &cliente[3].estado,
		&cliente[3].locacoes, &cliente[3].dvd);
		fclose(C[3]);
		conv_und_esp(cliente[3].nome);
		conv_und_esp(cliente[3].endereco);
		conv_und_esp(cliente[3].cidade);
		conv_und_esp(cliente[3].estado);
		if(cliente[3].i == 1)
		remove("Cliente - 04.txt");
	}
	
	C[4] = fopen("Cliente - 05.txt","r");
	if(C[4] != NULL)
	{
		fscanf(C[4],"%i %s %s %s %s %s %s %s %s %i %i",
		&cliente[4].codigo, &cliente[4].nome, &cliente[4].sexo,
		&cliente[4].nascimento, &cliente[4].rg, &cliente[4].cpf,
		&cliente[4].endereco, &cliente[4].cidade, &cliente[4].estado,
		&cliente[4].locacoes, &cliente[4].dvd);
		fclose(C[4]);
		conv_und_esp(cliente[4].nome);
		conv_und_esp(cliente[4].endereco);
		conv_und_esp(cliente[4].cidade);
		conv_und_esp(cliente[4].estado);
		if(cliente[4].i == 1)
		remove("Cliente - 05.txt");
	}
	
	C[5] = fopen("Cliente - 06.txt","r");
	if(C[5] != NULL)
	{
		fscanf(C[5],"%i %s %s %s %s %s %s %s %s %i %i",
		&cliente[5].codigo, &cliente[5].nome, &cliente[5].sexo,
		&cliente[5].nascimento, &cliente[5].rg, &cliente[5].cpf,
		&cliente[5].endereco, &cliente[5].cidade, &cliente[5].estado,
		&cliente[5].locacoes, &cliente[5].dvd);
		fclose(C[5]);
		conv_und_esp(cliente[5].nome);
		conv_und_esp(cliente[5].endereco);
		conv_und_esp(cliente[5].cidade);
		conv_und_esp(cliente[5].estado);
		if(cliente[5].i == 1)
		remove("Cliente - 06.txt");
	}
	
	C[6] = fopen("Cliente - 07.txt","r");
	if(C[6] != NULL)
	{
		fscanf(C[6],"%i %s %s %s %s %s %s %s %s %i %i",
		&cliente[6].codigo, &cliente[6].nome, &cliente[6].sexo,
		&cliente[6].nascimento, &cliente[6].rg, &cliente[6].cpf,
		&cliente[6].endereco, &cliente[6].cidade, &cliente[6].estado,
		&cliente[6].locacoes, &cliente[6].dvd);
		fclose(C[6]);
		conv_und_esp(cliente[6].nome);
		conv_und_esp(cliente[6].endereco);
		conv_und_esp(cliente[6].cidade);
		conv_und_esp(cliente[6].estado);
		if(cliente[6].i == 1)
		remove("Cliente - 07.txt");
	}
	
	C[7] = fopen("Cliente - 08.txt","r");
	if(C[7] != NULL)
	{
		fscanf(C[7],"%i %s %s %s %s %s %s %s %s %i %i",
		&cliente[7].codigo, &cliente[7].nome, &cliente[7].sexo,
		&cliente[7].nascimento, &cliente[7].rg, &cliente[7].cpf,
		&cliente[7].endereco, &cliente[7].cidade, &cliente[7].estado,
		&cliente[7].locacoes, &cliente[7].dvd);
		fclose(C[7]);
		conv_und_esp(cliente[7].nome);
		conv_und_esp(cliente[7].endereco);
		conv_und_esp(cliente[7].cidade);
		conv_und_esp(cliente[7].estado);
		if(cliente[7].i == 1)
		remove("Cliente - 08.txt");
	}
	
	C[8] = fopen("Cliente - 09.txt","r");
	if(C[8] != NULL)
	{
		fscanf(C[8],"%i %s %s %s %s %s %s %s %s %i %i",
		&cliente[8].codigo, &cliente[8].nome, &cliente[8].sexo,
		&cliente[8].nascimento, &cliente[8].rg, &cliente[8].cpf,
		&cliente[8].endereco, &cliente[8].cidade, &cliente[8].estado,
		&cliente[8].locacoes, &cliente[8].dvd);
		fclose(C[8]);
		conv_und_esp(cliente[8].nome);
		conv_und_esp(cliente[8].endereco);
		conv_und_esp(cliente[8].cidade);
		conv_und_esp(cliente[8].estado);
		if(cliente[8].i == 1)
		remove("Cliente - 09.txt");
	}
	
	C[9] = fopen("Cliente - 10.txt","r");
	if(C[9] != NULL)
	{
		fscanf(C[9],"%i %s %s %s %s %s %s %s %s %i %i",
		&cliente[9].codigo, &cliente[9].nome, &cliente[9].sexo,
		&cliente[9].nascimento, &cliente[9].rg, &cliente[9].cpf,
		&cliente[9].endereco, &cliente[9].cidade, &cliente[9].estado,
		&cliente[9].locacoes, &cliente[9].dvd);
		fclose(C[9]);
		conv_und_esp(cliente[9].nome);
		conv_und_esp(cliente[9].endereco);
		conv_und_esp(cliente[9].cidade);
		conv_und_esp(cliente[9].estado);
		if(cliente[9].i == 1)
		remove("Cliente - 10.txt");
	}
}

void verifica()
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(C[i] == NULL)
		{
			r[i] = 1;
		}
		else
		{
			r[i] = 0;
		}
	}
}

void cadastrar()
{
	int i=0,j=0;
	verifica();
	while(r[i] != 1 )
	{
		i++;
	}
	system("cls");
	switch (i)
	{
		case 0:
			C[0] = fopen("Cliente - 01.txt","w");
			break;
		case 1:
			C[1] = fopen("Cliente - 02.txt","w");
			break;
		case 2:
			C[2] = fopen("Cliente - 03.txt","w");
			break;
		case 3:
			C[3] = fopen("Cliente - 04.txt","w");
			break;
		case 4:
			C[4] = fopen("Cliente - 05.txt","w");
			break;
		case 5:
			C[5] = fopen("Cliente - 06.txt","w");
			break;
		case 6:
			C[6] = fopen("Cliente - 07.txt","w");
			break;
		case 7:
			C[7] = fopen("Cliente - 08.txt","w");
			break;
		case 8:
			C[8] = fopen("Cliente - 09.txt","w");
			break;
		case 9:
			C[9] = fopen("Cliente - 10.txt","w");
			break;
	}
	for(i=0;i<tam;i++)
	{
		if(r[i]==1);
		{
			j+=1;
		}
	}
	if(j == 10)
	{
		printf("=================   LocaMais   =================\n");
		printf("=                                              \n");
		printf("=  =========   Cadastrar Clientes   =========  \n");
		printf("=                                              \n");
		printf("= Limite máximo de clientes cadastrados!\n\n");
		le();
		printf("Pressione ENTER para voltar ao Menu!");
		getch();
		system("cls");
		main();
	}
	printf("=================   LocaMais   =================\n");
	printf("=                                              \n");
	printf("=  =========   Cadastrar Clientes   =========  \n");
	printf("=                                              \n");
	printf("= Insira os dados do cliente: \n");
	cliente[i].codigo = i+1;
	printf("\n= Código: %i\n",cliente[i].codigo);
	fprintf(C[i],"%d\n",cliente[i].codigo);
	printf("\n= Nome: ");
	fflush(stdin);
	fgets(cliente[i].nome, 100, stdin);
	conv_esp_und(cliente[i].nome);
	fprintf(C[i],"%s\n",cliente[i].nome);
	printf("\n= Sexo: ");
	fflush(stdin);
	fgets(cliente[i].sexo, 20, stdin);
	fprintf(C[i],"%s\n",cliente[i].sexo);
	printf("\n= Data de nascimento: ");
	fflush(stdin);
	fgets(cliente[i].nascimento,20,stdin);
	fprintf(C[i],"%s\n",cliente[i].nascimento);
	printf("\n= RG: ");
	scanf("%s",cliente[i].rg);
	fprintf(C[i],"%s\n",cliente[i].rg);
	printf("\n= CPF: ");
	scanf("%s",cliente[i].cpf);
	fprintf(C[i],"%s\n",cliente[i].cpf);
	printf("\n= Endereço: ");
	*cliente[i].endereco = NULL;
	fflush(stdin);
	fgets(cliente[i].endereco,100,stdin);
	conv_esp_und(cliente[i].endereco);
	fprintf(C[i],"%s\n",cliente[i].endereco);
	printf("\n= Cidade: ");
	fflush(stdin);
	fgets(cliente[i].cidade,100,stdin);
	conv_esp_und(cliente[i].cidade);
	fprintf(C[i],"%s\n",cliente[i].cidade);
	printf("\n= Estado: ");
	fflush(stdin);
	fgets(cliente[i].estado,100,stdin);
	conv_esp_und(cliente[i].estado);
	fprintf(C[i],"%s\n",cliente[i].estado);
	cliente[i].locacoes = 0;
	fprintf(C[i],"%i\n",cliente[i].locacoes);
	cliente[i].dvd = 0;
	fprintf(C[i],"%i\n",cliente[i].dvd);
	fclose(C[i]);
	
	le();
	printf("Pressione ENTER para voltar ao Menu!");
	getch();
	system("cls");
	main();
	
}

void excluir()
{
	system("cls");
	le();
	verifica();
	int i,j=0,cod;
	printf("=================   LocaMais   =================\n");
	printf("=                                              \n");
	printf("=  ==========   Excluir Clientes   ==========  \n");
	printf("=                                              \n");
	printf("= Clientes sem locações ativas: \n");
	printf("\n================================================\n");
	for(i=0;i<tam;i++)
	{
		if(r[i]==0 && cliente[i].dvd == 0)
		{
			printf("\n= Código: %i\n",cliente[i].codigo);
			printf("= Nome: ");puts(cliente[i].nome);
			printf("= Locações realizadas: %i\n",cliente[i].locacoes);
			printf("= Locações ativas: %i\n",cliente[i].dvd);
			printf("\n================================================\n");
			j += 1;
		}		
	}
	
	if(j==0)
	{
		printf("\n= Nenhum cliente está sem locações ativas!\n");
	}
	else
	{
		printf("\n= Digite o código do cliente que deseja excluir: ");
		scanf("%i",&cod);
		for(i=0;i<tam;i++)
		{
			if(cod == cliente[i].codigo)
			{
				cliente[i].i = 1;
				le();
				cliente[i].i = 0;
			}
		}
		printf("\n= O cliente foi exclído com sucesso!");
	}
	
	le();
	printf("\nPressione ENTER para voltar ao Menu!");
	getch();
	system("cls");
	main();
	
}

void listar()
{
	system("cls");
	le();
	verifica();
	printf("=================   LocaMais   =================\n");
	printf("=                                              =\n");
	printf("=  ===========   Listar Clientes   ==========  =\n");
	int i,j=0;
	for(i=0;i<tam;i++)
	{
		if(r[i]==0)
		{
			printf("\n= ================ Cliente 0%i ================ =\n\n",i+1);
			printf("\n= Código: %i\n",cliente[i].codigo);
			printf("= Nome: ");puts(cliente[i].nome);
			printf("= Sexo: ");puts(cliente[i].sexo);
			printf("= Data de Nascimento: ");puts(cliente[i].nascimento);
			printf("= RG: ");puts(cliente[i].rg);
			printf("= CPF: ");puts(cliente[i].cpf);
			printf("= Endereço: ");puts(cliente[i].endereco);
			printf("= Cidade: ");puts(cliente[i].cidade);
			printf("= Estado: ");puts(cliente[i].estado);
			printf("= Locações realizadas: %i\n",cliente[i].locacoes);
			printf("= Locações ativas: %i\n",cliente[i].dvd);
			printf("\n\n================================================\n\n");
			printf("\n          ============================          \n\n");
			j+=1;
		}
	}
	if(j == 0)
	{
		printf("=\n");
		printf("= Nenhum cliente cadastrado!\n\n");
	}
	
	le();
	printf("Pressione ENTER para voltar ao Menu!");
	getch();
	system("cls");
	main();
}

void locar()
{
	system("cls");
	int i,j,cod,qtd_dvd;
	printf("=================   LocaMais   =================\n");
	printf("=                                              =\n");
	printf("=  ===========   Efetuar Locação   ==========  =\n");
	printf("=                                              =\n");
	printf("= Clientes aptos para fazer locações: \n\n");
	printf("\n================================================\n");
	for(i=0;i<tam;i++)
	{
		if(r[i]==0 && cliente[i].dvd == 0)
		{
			printf("\n= Código: %i\n",cliente[i].codigo);
			printf("= Nome: ");puts(cliente[i].nome);
			printf("= Locações realizadas: %i\n",cliente[i].locacoes);
			printf("= Locações ativas: %i\n",cliente[i].dvd);
			printf("\n================================================\n");
			j += 1;
		}		
	}
	printf("\n= Digite o código do cliente que irá efetuar a locação: ");
	scanf("%i",&cod);
	
	while(cod < 1 || cod > 10 || cliente[cod-1].dvd != 0)
	{
		printf("\n= Entrada inválida, tente novamente: ");
		scanf("%i",&cod);
	}
	
	system("cls");
	printf("=================   LocaMais   =================\n");
	printf("=                                              =\n");
	printf("=  ===========   Efetuar Locação   ==========  =\n");
	printf("=                                              =\n");
	printf("= Digite a quantidade de DVDs que serão locados: ");
	scanf("%i",&qtd_dvd);
	
	for(i=0;i<qtd_dvd;i++)
	{
		int dvd_c;
		printf("Digite o código do %iª dvd: ",i+1);
		scanf("%i",&dvd_c);
		fprintf(BD,"%i %i\n",cod,dvd_c);
	
	}
	le();
	printf("\nPressione ENTER para voltar ao Menu!");
	getch();
	system("cls");
	main();
}

void devolver()
{
	system("cls");
	int i,cod,qtd_dvd;
	printf("=================   LocaMais   =================\n");
	printf("=                                              =\n");
	printf("=  ==========   Efetuar Devolução   =========  =\n");
	printf("=                                              =\n");
	printf("= Digite o código do cliente: \n\n");
	for(i=0;i<tam;i++);
	{
		if(cliente[i].dvd == 0)
		{
			printf("= Cliente 0%i\n",i+1);
			printf("\nCódigo: %i\n",cliente[i].codigo);
			printf("Nome: \n");puts(cliente[i].nome);
		}
	}
	for(i=0;i<tam;i++)
	{
		if(cliente[i].codigo == cod)
		{
			cliente[i].dvd -= qtd_dvd;
		}
	}
	le();
	printf("Pressione ENTER para voltar ao Menu!");
	getch();
	system("cls");
	main();
}

void listar_ativos()
{
	system("cls");
	le();
	verifica();
	printf("=================   LocaMais   =================\n");
	printf("=                                              =\n");
	printf("=  ========  Listar Clientes Ativos  ========  =\n");
	int i,j=0;
	for(i=0;i<tam;i++)
	{
		if(r[i] == 0 && cliente[i].dvd > 0)
		{
			printf("\n= ================ Cliente 0%i ================ =\n\n",i+1);
			printf("\nCódigo: %i\n",cliente[i].codigo);
			printf("Nome: ");puts(cliente[i].nome);
			printf("Sexo: ");puts(cliente[i].sexo);
			printf("Data de Nascimento: ");puts(cliente[i].nascimento);
			printf("RG: ");puts(cliente[i].rg);
			printf("CPF: ");puts(cliente[i].cpf);
			printf("Endereço: ");puts(cliente[i].endereco);
			printf("Cidade: ");puts(cliente[i].cidade);
			printf("Estado: ");puts(cliente[i].estado);
			printf("Locações realizadas: %i\n",cliente[i].locacoes);
			printf("Locações ativas: %i\n",cliente[i].dvd);
			printf("\n\n================================================\n\n");
			printf("\n          ============================          \n\n");
			j+=1;
		}
	}
	
	if(j == 0)
	{
		printf("=\n");
		printf("= Nenhum cliente possui locações!\n\n");
	}
	
	le();
	printf("Pressione ENTER para voltar ao Menu!");
	getch();
	system("cls");
	main();
}

char conv_esp_und(char s[])
{
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i] == ' ')
		{
			s[i] = '_';
		}
	}
	
}


char conv_und_esp(char s[])
{
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i] == '_')
		{
			s[i] = ' ';
		}
	}
}

