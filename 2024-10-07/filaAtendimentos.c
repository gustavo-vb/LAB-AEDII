#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct no
{
    int dado;
    struct no *prox;
} No;

// Fila contem ponteiros para o primeiro e o ultimo elemento (No)
typedef struct
{
    No *inicio;
    No *fim;
    int tamFila;
} Fila;

// funcoes de manipulacao
void cria(Fila *q);
int  insere(Fila *q, int dado);
int  retira(Fila *q, int *dado);

// funcoes de checagem / visualizacao
int  estaVazia(Fila q);
int  getInicio(Fila q);
int  getFim(Fila q);
int  getTamanho(Fila q);
void mostra(Fila q);

//outras funçoes
void carregarFila(Fila *usarFila);

int main()
{
    Fila atendimentos;
    srand(time(NULL));

    cria(&atendimentos);
    if (estaVazia(atendimentos))
        printf("Fila esta vazia!\n\n");
    else
        printf("Fila nao esta vazia!\n");

    printf("============================================================================================\n");
    printf("Voce ira carregar a fila com numeros aleatorios agora. (PRESSIONE ENTER PARA CONTINUAR)\n");
    getchar();

    carregarFila(&atendimentos);

    printf("============================================================================================\n");
    printf("Verificando se sobraram valores na fila...\n\n");

    if(estaVazia(atendimentos))
    {
        printf("A fila esta vazia! Nao ha valores para serem mostrados.\n\n");
        return 1;
    }

    if(!estaVazia(atendimentos))
    {
        printf("Ha conteudo na fila! Mostrando a fila...\n\n");
        mostra(atendimentos);
    }




}

/*
    A funcao 'cria' inicializa a Fila apontando o inicio e o fim para NULL.
*/
void cria(Fila *q)
{
    q->inicio = NULL;
    q->fim = NULL;
    q->tamFila = 0;
}

/*
    A funcao 'insere' insere um No sempre ao final da fila.
    - Se Fila eh vazia, inicio e fim apontam pra esse no.
    - Se Fila nao eh vazia, insere ao final, fazendo:
        - o ponteiro de proximo do fim atual apontar para o novo no
        - o ponteiro de fim passa a apontar para o novo no
*/
int insere(Fila *q, int dado)
{
    No *aux;
    aux = (No *) malloc(sizeof(No)); //aloca na heap
    if (aux == NULL) //checa se deu certo
        return 0;

    //inicializa o no
    aux->dado = dado;
    aux->prox = NULL;

    q->tamFila++; //incrementa o tamanho da fila

    //se for o primeiro elemento, tanto inicio quanto fim apontam pra ele
    if (q->inicio == NULL)
    {
        q->inicio = aux;
        q->fim = aux;
        return 1;
    }

    //se nao, prox do antigo fim aponta pro novo no e fim passa a apontar pro novo no
    q->fim->prox = aux;
    q->fim = aux;
    return 1;
}

/*
    A funcao 'retira' remove sempre o dado do comeco da Fila.
    - O inicio passa a apontar para o proximo do inicio.
    - se a fila nao tem mais elementos, tanto inicio quanto fim irao apontar para NULL.
*/
int retira(Fila *q, int *dado)
{
    No *aux;
    aux = q->inicio;
    if (aux == NULL) // checa se fila esta vazia
        return 0;

    *dado = aux->dado; //recupera o dado
    q->tamFila--; //diminui o tamanho da fila
    q->inicio = aux->prox; //inicio aponta para o segundo elemento

    //se fila esta vazia agora, fim deve apontar para null tambem
    if (q->inicio == NULL) //
        q->fim = NULL;

    free(aux); //libera a memoria
    return 1;
}

/*
    Verifica se esta vazio (1) ou nao (0)
*/
int estaVazia(Fila q)
{
    if (q.inicio == NULL)
        return 1;
    return 0;
}

/*
    Retorna o dado do No apontado por inicio.
*/
int getInicio(Fila q)
{
    return q.inicio->dado;
}


/*
    Retorna o dado do No apontado por fim.
*/
int getFim(Fila q)
{
    return q.fim->dado;
}


/*
    Retorna o tamanho da Fila.
*/
int getTamanho(Fila q)
{
    return q.tamFila;
}

/*
    Imprime os elementos da Fila, se ela nao estiver vazia.
    Imprime do inicio para o fim.
*/
void mostra(Fila q){

    No *aux;
    aux = q.inicio;
    if (aux == NULL)
    {
        printf("Fila vazia!\n");
    }

    while (aux != NULL)
    {
        printf("Dado enfileirado: %d\n", aux->dado);
        aux = aux->prox;
    }
}

carregarFila(Fila *usarFila)
{
    int auxiliar = 0;

    for(int i = 0; i < 20; i++)
    {
        auxiliar = rand() %100;

        printf("Numero gerado = %d\n", auxiliar);

        if(auxiliar < 60)
        {
            insere(usarFila, auxiliar);
            printf("O valor %d foi inserido na fila.\n\n", auxiliar);
        }

        if(auxiliar >= 60)
        {
            if(estaVazia(*usarFila))
            {
                printf("A fila ja esta vazia, nao ha dado para retirar!\n\n");
            }

            if(!estaVazia(*usarFila))
            {
                retira(usarFila, &auxiliar);
                printf("O dado %d foi retirado da fila!\n\n", auxiliar);
            }

        }

    }
}
