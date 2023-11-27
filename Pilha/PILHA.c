#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criacao da Struct e ja definindo o nome como produto
typedef struct produtos
{
	/* data */
	int idCliente;
	char nomeProduto[20];
	int quantProduto;
	float valorunitarioProduto;
	float valortotalProduto;
	// O ELO que ira armazenar o endereco da proxima struct transformando em lista encadeada
	struct produtos *elo;
} produtos;

// Chama o menu
int menu();

// Empilha
int empilhar(produtos **ponteiroLista, int idCliente, char nomeProduto[20], float valorunitarioProduto, int quant, float valortotalProduto);

// Desempilhar
int desempilhar(produtos **ponteiroLista);

// Mostrar quantidade de elementos
int quantidadeElementos(produtos *ponteiroLista);

// Mostrar topo da lista
int topo(produtos *ponteiroLista);

// Mostra a pilha
void pilha(produtos *ponteiroLista);

int main()
{
	produtos *ponteiroLista;
	int opcoes, quant, sucesso, idCliente;
	char nomeProduto[20];
	float valorunitarioProduto, valortotalProduto;
	ponteiroLista = NULL;

	do
	{

		opcoes = menu();

		switch (opcoes)
		{
		case 0:
			printf("::::::::: Saindo :::::::::\n");
			break;
		case 1:
			printf("::::: Empilhar ::::: \n");
			printf("ID do cliente \n");
			scanf("%d", &idCliente);
			printf("Nome do produto \n");
			scanf("%s", nomeProduto);
			printf("Digite o valor unitario do produto \n");
			scanf("%f", &valorunitarioProduto);
			printf("Digite a quantidade de produto \n");
			scanf("%d", &quant);

			valortotalProduto = valorunitarioProduto * quant;

			printf("O valor total do produto e %.2f \n", valortotalProduto);

			if (!empilhar(&ponteiroLista, idCliente, nomeProduto, valorunitarioProduto, quant, valortotalProduto))
			{
				/* Sucesso */
				printf("Empilhado com sucesso inserido no comeco da lista com sucesso\n\n");
			}
			else
			{
				printf("Houve um erro de lista !!!\n\n");
			}

			break;
		case 2:
			printf("::::::::: Desempilhar ::::::::: \n");
			int t = desempilhar(&ponteiroLista);

			t == 1 ? printf("A lista nao possui nenhum elemento para ser removido \n\n") : printf("Desempilhado com sucesso \n\n");

			break;
		case 3:
			printf("::::::::: Quantidade de elementos ::::::::: \n");
			int q = quantidadeElementos(ponteiroLista);

			printf("Possui %d de elementos na lista \n", q);
			break;
		case 4:
			printf("::::::::: Mostrar quem e o topo ::::::::: \n");
	 topo(ponteiroLista);

			break;
		case 5:
			printf("::::::::: Mostrar pilha :::::::::\n");
			pilha(ponteiroLista);
			break;
		}

	} while (opcoes != 0);

	return 0;
}

int menu()
{
	int opcoes;
	printf("::::::::: Bem Vindo :::::::::\n");
	printf("[0] Sair \n");
	printf("[1] Empilhar no inicio da lista \n");
	printf("[2] Desempilhar no comeco da lista \n");
	printf("[3] Quantidade de elementos \n");
	printf("[4] Mostrar o topo \n");
	printf("[5] Mostrar pilha \n");
	scanf("%d", &opcoes);

	return opcoes;
}

int empilhar(produtos **ponteiroLista, int idCliente, char nomeProduto[20], float valorunitarioProduto, int quant, float valortotalProduto)
{
	produtos *ponteiroNovo = (produtos *)malloc(sizeof(produtos));
	if (ponteiroNovo == NULL)
		return 1;
	else

	{
		ponteiroNovo->idCliente = idCliente;
		strcpy(ponteiroNovo->nomeProduto, nomeProduto); // Utiliza strcpy para copiar a string e coloca na variavel struct
		ponteiroNovo->valorunitarioProduto = valorunitarioProduto;
		ponteiroNovo->quantProduto = quant;
		ponteiroNovo->valortotalProduto = valortotalProduto;
		ponteiroNovo->elo = *ponteiroLista;
		*ponteiroLista = ponteiroNovo;
		return 0;
	}
}

int desempilhar(produtos **ponteiroLista)
{
	if (*ponteiroLista == NULL)
	{
		/* Nenhum elemento da lista */
		return 1;
	}

	else
	{
		// Garantia de nao perder o dados
		produtos *aux = *ponteiroLista;
		*ponteiroLista = (*ponteiroLista)->elo; // Atualiza o ponteiro para o início da lista
		return 0;
	}
}

int quantidadeElementos(produtos *ponteiroLista)
{
	int i = 0;
	produtos *aux;

	for (aux = ponteiroLista; aux != NULL; aux = aux->elo)
	{
		i++;
	}

	return i;
}

int topo(produtos *ponteiroLista)
{

	if (ponteiroLista != NULL)
	{
		printf("Id cliente %d\t", ponteiroLista->idCliente);
		printf("Nome Produto %s\t", ponteiroLista->nomeProduto);
		printf("Valor unitario %g\t", ponteiroLista->valorunitarioProduto);
		printf("Quantidade %d\t", ponteiroLista->quantProduto);
		printf("Valor total %.2f\n\n", ponteiroLista->valortotalProduto);
		return 0;
	}
	else{
		printf("A lista nao possui nenhum elemento entao nao ha topo \n\n");
		return 1;
	}

	
}

void pilha(produtos *ponteiroLista)
{
	produtos *i;
	for (i = ponteiroLista; i != NULL; i = i->elo)
	{
		printf("Id cliente %d\t", i->idCliente);
		printf("Nome Produto %s\t", i->nomeProduto);
		printf("Valor unitario %g\t", i->valorunitarioProduto);
		printf("Quantidade %d\t", i->quantProduto);
		printf("Valor total %.2f\n\n", i->valortotalProduto);
	}
}
