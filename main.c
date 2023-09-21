#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;

typedef struct Lista
{
    No *inicio;
    int tam;
} Lista;

void inserirFim(Lista *lista, int valor)
{
    No *novo =(No*) malloc(sizeof(No));
    No *no =(No*) malloc(sizeof(No));
    novo-> valor= valor;
    novo-> proximo= NULL;
    if(lista->inicio == NULL)
    {
        lista->inicio= novo;
    }
    else
    {
        no = lista->inicio;
        while(no->proximo!= NULL)
            no= no->proximo;
        no->proximo = novo;
    }
    lista->tam++;
}






void inserirInicio(Lista *lista, int valor )
{
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
}
void remover(Lista *lista, int valor)
{
    No *inicio = lista ->inicio;
    No *noARemover = NULL;

    if(inicio != NULL && inicio->valor == valor)
    {
        noARemover= inicio;
        lista ->inicio= noARemover->proximo;
    }
    else
    {
        while(inicio!= NULL && inicio ->proximo != NULL && inicio->proximo->valor!= valor)
        {
            inicio = inicio->proximo;
        }
        if(inicio!= NULL && inicio-> proximo != NULL)
        {
            noARemover = inicio->proximo;
            inicio->proximo= noARemover->proximo;
        }
    }
    if(noARemover)
    {
        free(noARemover);
        lista->tam--;
    }
}

void imprimeLista(Lista *lista)
{
    No *inicio = lista ->inicio;
    while(inicio!= NULL)
    {
        printf("%d", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}

int main()
{
    Lista list;
    list.inicio = NULL;
    list.tam= 0;
    int valor;
    int opcao;
    do
    {
        printf("digite 1 para inserir um numero no inicio\ndigite 2 para imprimir\ndigite 3 para inserir um numero no fim\ndigite 4 para remover\ndigite 5 para sair");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            printf("digite o numero a ser inserido\n");
            scanf("%d", &valor);
            inserirInicio(&list, valor);
            break;
        case 2:
            imprimeLista(&list);
            break;
        case 3:
            printf("digite o numero a ser inserido\n");
            scanf("%d", &valor);
            inserirFim(&list, valor);
            break;
        case 4:
            printf("digite o numero a ser removido\n");
            scanf("%d", &valor);
            remover(&list, valor);
            break;
        case 5:
            printf("finalizando...\n");
            break;
        default:
            printf("opção inválida\n");



        }
    }
    while(opcao != 5);

    return 0;
}



