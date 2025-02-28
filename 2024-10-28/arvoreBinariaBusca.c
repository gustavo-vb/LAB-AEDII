#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq;
    struct no *dir;
} No;

//funcoes de manipulacao
void cria(No **t);
int  insere(No **t, int dado);

//funcoes de visualizacao
void preOrdem(No *t);
void emOrdem(No *t);
void posOrdem(No *t);

int  contaNosArvore(No *t);

int quantNos = 0;

main()
{
    No *arvore;
    int sucesso;

    cria(&arvore);

    sucesso = insere(&arvore, 12);
    sucesso = insere(&arvore, 5);
    sucesso = insere(&arvore, 4);
    sucesso = insere(&arvore, 3);
    sucesso = insere(&arvore, 9);
    sucesso = insere(&arvore, 1);
    sucesso = insere(&arvore, 6);
    sucesso = insere(&arvore, 11);
    sucesso = insere(&arvore, 8);
    sucesso = insere(&arvore, 7);
    sucesso = insere(&arvore, 15);
    sucesso = insere(&arvore, 20);

    printf("PRE ORDEM: ");
    preOrdem(arvore);

    printf("\n\nEM ORDEM: ");
    emOrdem(arvore);

    printf("\n\nPOS ORDEM: ");
    posOrdem(arvore);

    contaNosArvore(arvore);

    printf("\n\nA quantidade de NOS da arvore e %d\n", quantNos);

}


void cria(No **t)
{
    *t = NULL;
}


int insere(No **t, int dado)
{
    if (*t == NULL)
    { //cheguei na posicao certa, devo inserir
        *t = (No *) malloc(sizeof(No)); //aloco um No na memoria e devolvo seu endereco para o conteudo de t
        if (*t == NULL) //falha na alocacao
            return 0;

        (*t)->dado = dado; //atribuo o dado ao novo No
        (*t)->esq = NULL; // esq do meu novo No eh NULL
        (*t)->dir = NULL; // dir do meu novo No eh NULL

        return 1;
    }

    //se (*t) aponta para um No, recursivamente procuro a posicao certa para inserir

    if (dado < (*t)->dado) //se o dado eh menor que o dado do No corrente
        return insere(&(*t)->esq, dado); // chamo a funcao recursivamente para o No da esquerda

    return insere(&(*t)->dir, dado); // senao, chamo recursivamente para o No da direita
}

void preOrdem(No *t)
{
    if (t != NULL)
    {
        printf("%d ", t->dado);
        preOrdem(t->esq);
        preOrdem(t->dir);
    }
}

void emOrdem(No *t)
{
    if (t != NULL)
    {
        emOrdem(t->esq);
        printf("%d ", t->dado);
        emOrdem(t->dir);
    }
}

void posOrdem(No *t)
{
    if (t != NULL)
    {
        posOrdem(t->esq);
        posOrdem(t->dir);
        printf("%d ", t->dado);
    }
}

int contaNosArvore(No *t)
{
    if (t != NULL)
    {
        contaNosArvore(t->esq);
        contaNosArvore(t->dir);
        quantNos++;
    }

    return 1;
}

