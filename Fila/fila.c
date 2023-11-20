#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef struct aluno
{
    /* data */
    int ra;
    char nome[20];
    float notafinal;
    char status[20];
} aluno;

// Menu
int menu();


// Inserir dados ao fim da fila
int inserir(aluno Lista[], int inicioArranjo, int fimArranjo, int *inicioLista, int *finalLista, aluno infoAluno);

// Remover o ultimo dado que entrou (Primeiro da fila)
int remover(aluno lista[], int inicioArranjo, int finalArranjo, int *inicioLista, int *finalLista);

// Mostrar a quantidade de elementos da fila
int quant(int inicioLista, int finalLista, aluno lista[]);

// Mostrar primeiro da fila
int primeiro(aluno lista[], int inicioLista);

// Mostrar ultimo da fila
int ultimo(aluno lista[], int fimLista);

// Mostrar Fila
int fila(aluno lista[], int inicioArranjo, int finalArranjo, int inicioLista, int finalLista);

int main()
{

    aluno lista[N], infoaluno;
    // Inicializar as variaveis (Ficar mais bonitinho) e adicionar regra do RA
    for (int i = 0; i < N; i++)
    {
        lista[i].ra = 0;
        strcpy(lista[i].nome, "Insira os dados");
        lista[i].notafinal = 0;
        strcpy(lista[i].status, "Insira os dados");
    }

    int inicioArranjo = 0, fimArranjo = N - 1, inicioLista = -1, finalLista = N - 1, opcoes;

    do
    {
        /* MOSTRAR O MENU */
        opcoes = menu();

        switch (opcoes)
        {
        case 0:
            printf("Saindo... \n\n");
            break;
        case 1:
            /* code */
            printf("\n\n:::Inserindo Dados ao Fim da Fila:::\n");
            printf("RA do aluno \n");

            scanf("%d", &infoaluno.ra);
            if (infoaluno.ra <= 0)
            {
                printf("RA NAO PODE SER IGUAL OU MENOR QUE 0\n\n");
                break;
            }

            printf("Nome do aluno \n");
            scanf("%s", infoaluno.nome);
            printf("Nota final do aluno \n");
            scanf("%f", &infoaluno.notafinal);

            if (infoaluno.notafinal >= 6.0)
            {
                snprintf(infoaluno.status, sizeof(infoaluno.status), "Aprovado");
            }
            else
            {
                snprintf(infoaluno.status, sizeof(infoaluno.status), "Reprovado");
            }

            printf("O aluno esta %s\n\n", infoaluno.status);

            if (!inserir(lista, inicioArranjo, fimArranjo, &inicioLista, &finalLista, infoaluno))
            {
                /* Sucesso */
                printf("Inserido com sucesso ao fim da lista \n\n");
            }
            else
            {
                printf("Houve um erro de lista !!!\n\n");
            }

            break;
        case 2:
            /* Remover primeiro da Fila */
            printf("\n\n:::Removendo Dados da Fila:::\n");
            if (!remover(lista, inicioArranjo, fimArranjo, &inicioLista, &finalLista))
            {
                /* Sucesso */
                printf("Removido com sucesso ao inicio da lista \n\n");
            }
            else
            {
                printf("Houve um erro de remocao !!!\n\n");
            }
            break;
        case 3:
            /* Quant */
            printf("\n\n:::Mostrando Quantidadade Dados da Fila:::\n");
            printf("A quantidade de elemento da lista e %d\n\n", quant(inicioLista, finalLista, lista));
            break;
        case 4:
            /* Primeiro */
            printf("\n\n:::Mostrando O Primeiro Dado da Fila:::\n");
            primeiro(lista, inicioLista);
            break;
        case 5:
            /* Ultimo */
            printf("\n\n:::Mostrando O Primeiro Dado da Fila:::\n");
            ultimo(lista, finalLista);
            break;
        case 6:
            /* Mostrar Fila */
            printf("\n\n:::Mostrando Dados da Fila:::\n");
            fila(lista, inicioArranjo, fimArranjo, inicioLista, finalLista);
            break;
        case 7:
            /* Limpar console*/
            system("cls");
            break;

        default:
            printf("Opcao Invalida digite um numero valido \n\n");
            break;
        }

    } while (opcoes != 0);

    return 0;
}

int menu()
{
    int opcao;
    printf("::::::::: M E N U :::::::::\n");
    printf("[1] Inserir no Fim da Lista\n");
    printf("[2] Remover no Inicio da Lista\n");
    printf("[3] Mostar Quantidade de Elementos da Lista\n");
    printf("[4] Mostar o Primeiro Elemento da Lista\n");
    printf("[5] Mostar o Ultimo Elemento da Lista\n");
    printf("[6] Mostrar a Fila\n");
    printf("[7] Limpar o console Windows\n");
    printf("[0] Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int inserir(aluno Lista[], int inicioArranjo, int fimArranjo, int *inicioLista, int *finalLista, aluno infoAluno)
{
    if (inicioArranjo == *inicioLista && fimArranjo == *finalLista)
    {
        /* Lista cheia */
        return 1;
    }
    else
    {
        if (*inicioLista == -1)
        {
            /* A Lista esta vazia */
            *inicioLista = *finalLista = inicioArranjo;
        }
        else if (*finalLista < fimArranjo)
        {
            /* Se tiver espaco no inicio da lista */
            *finalLista = *finalLista + 1;
        }
        else
        {
            for (int i = *inicioLista; i < *finalLista; i++)
            {
                /* Inserir */
                Lista[i - 1] = Lista[i];
            }
            *inicioLista = *inicioLista - 1;
        }
        Lista[*finalLista] = infoAluno;
        return 0;
    }
}

int remover(aluno lista[], int inicioArranjo, int finalArranjo, int *inicioLista, int *finalLista)
{

    if (lista->ra == 0)
    {

        /* Se tem elemnto na lista */
        return 1;
    }
    else
    {
        for (int i = *inicioLista; i <= *finalLista; i++)
        {
            // desloco elementos
            lista[i - 1] = lista[i];
        }
        *finalLista = *finalLista - 1; // Tira o elemento

        if (*finalLista == *inicioLista - 1)
        {
            /* Se conter 1 elemento na lista reinicia a lista*/
            for (int i = 0; i < N; i++)
            {
                lista[i].ra = 0;
                strcpy(lista[i].nome, "Insira os dados");
                lista[i].notafinal = 0;
                strcpy(lista[i].status, "Insira os dados");
            }
        }

        return 0;
    }
}

int quant(int inicioLista, int finalLista, aluno lista[])
{
    if (!lista->ra == 0)
    {
        return (finalLista - inicioLista) + 1;
    }
    else
    {
        return 0;
    }
}

int primeiro(aluno lista[], int inicioLista)
{
    if (!lista->ra == 0)
    {
        printf("%d - %s - %2.f - %s\n\n", lista[inicioLista].ra, lista[inicioLista].nome, lista[inicioLista].notafinal, lista[inicioLista].status);
        return 0;
    }
    else
    {
        printf("Nao possui elementos na listas\n\n");
        return 0;
    }
}

int ultimo(aluno lista[], int finalLista)
{
    if (!lista->ra == 0)
    {
        printf("%d - %s - %2.f - %s\n\n", lista[finalLista].ra, lista[finalLista].nome, lista[finalLista].notafinal, lista[finalLista].status);
        return 0;
    }
    else
    {
        printf("Nao possui elementos na listas\n\n");
        return 0;
    }
}

int fila(aluno lista[], int inicioArranjo, int finalArranjo, int inicioLista, int finalLista)
{
    for (int i = inicioArranjo; i < finalArranjo; i++)
    {
        if (i >= inicioLista && i <= finalLista)
        {
            /* Mostrar os dados */
            printf("%d - %s - %2.f - %s\n", lista[i].ra, lista[i].nome, lista[i].notafinal, lista[i].status);
        }
        else
        {
            printf("---\n");
        }
    }
    printf("\n\n");
    return 0;
}