#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct no
{
    char   dado[30];
    struct no *ant;
    struct no *prox;
} No;

typedef struct
{
    No *inicio;
    No *fim;
    int tam;
} ListaCDE;

void cria(ListaCDE *l);
int  insereOrdenado(ListaCDE *l, char d[30]);
void mostra(ListaCDE, int sentido);


main()
{
    FILE *arquivo;
    char caractere, nome[30];
    int  i = 0;
    ListaCDE lista;

    setlocale(LC_ALL, "Portuguese");

    printf("--|Código de avaliação feito pelo grupo integrado por: Danilo, Diana e Gustavo (D&D/G).|--\n");

    printf("Criando a lista...\n");

    cria(&lista);

    printf("Abrindo o arquivo para leitura...\n");
    arquivo = fopen("nomes.txt", "r");
    if (arquivo == NULL)
    {
        printf("Arquivo nao encontrado...\n");
        exit(1);
    }

    printf("Processando o arquivo textual...\n");

    while(fgets(nome, sizeof(nome), arquivo))
    {
        nome[strcspn(nome, "\n")] = '\0';
        insereOrdenado(&lista, nome);
    }

    fclose(arquivo);

    mostra(lista, 1);
}

void cria(ListaCDE *l)
{
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

int insereOrdenado(ListaCDE *l, char d[30])
{
    No *anterior, *atual;
    No *aux = (No *) malloc(sizeof(No));

    if (aux == NULL)
        return 0;

    strcpy(aux->dado, d);
    l->tam++;

    if (l->inicio == NULL)
    {
        l->inicio = aux;
        l->fim = aux;
        aux->ant = l->fim;
        aux->prox = l->inicio;
        return 1;
    }

    if (strcmp(d, l->inicio->dado) < 0)
    {
        aux->ant = l->fim;
        aux->prox = l->inicio;
        l->inicio->ant = aux;
        l->inicio = aux;
        l->fim->prox = l->inicio;
        return 1;
    }

    if (strcmp(d, l->fim->dado) > 0)
    {
        aux->ant = l->fim;
        aux->prox = l->inicio;
        l->fim->prox = aux;
        l->fim = aux;
        l->inicio->ant = l->fim;
        return 1;
    }

    anterior = l->inicio;
    atual = anterior->prox;

    while (strcmp(d, atual->dado) > 0)
    {
        anterior = atual;
        atual = atual->prox;
    }

    aux->ant = anterior;
    aux->prox = atual;
    anterior->prox = aux;
    atual->ant = aux;
    return 1;
}

void mostra(ListaCDE l, int sentido)
{
    No *aux;

    if (l.inicio == NULL)
        printf("Lista vazia!\n");
    else
    {
        if(sentido == 1)
        {
            printf("\nExibindo lista do inicio ao fim\n\n");
            aux = l.inicio;
            do
            {
                printf("Dado: %s\n", aux->dado);
                aux = aux->prox;
            } while(aux != l.inicio);
        }
        else
        {
            printf("\nExibindo lista do fim ao inicio\n\n");
            aux = l.fim;
            do
            {
                printf("Dado: %s\n", aux->dado);
                aux = aux->ant;
            } while(aux != l.fim);
        }
    }
}
