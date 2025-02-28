#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    int x; //o offset de y � zero.
    int y; //o offset de y � quatro.
    char nome [30]; //o offset de nome � oito.
} ponto;

int deseja = 0, r, i;

void alteraDados(ponto g[], int posicao);
int buscaPonto(ponto g[], char n[30]);

main()
{
    setlocale(LC_ALL, "Portuguese");
    ponto s, v[3], *p; //A ordem de declara��o, n�o garante a mesma ordem de aloca��o quando se trata de vari�veis soltas. No caso de um struct, isso ja � diferente , pois isso ir� ser alocado em ordem de declara��o.

    printf("Endere�os:\n");
    printf("========================================\n");
    printf("Endere�o da vari�vel s = %X ou %d\n", &s, &s);
    printf("Endere�o da vari�vel v = %X ou %d\n", v, v); //n�o se coloca "&" antes das vari�veis aqui e nem em VETORES e MATRIZES, j� que o S.O. guarda o endere�o da primeira posi��o desses tipos.
    printf("Endere�o da vari�vel p = %X ou %d\n\n", &p, &s);


    printf("Alimentando o vetor com dados.......\n\n");
    v[0].x = 100;
    v[0].y = 150;
    strcpy(v[0].nome, "Igreja Matriz");

    v[1].x = 300;
    v[1].y = 450;
    strcpy(v[1].nome, "Cristo Redentor");

    v[2].x = 500;
    v[2].y = 750;
    strcpy(v[2].nome, "Rodovi�ria");


    printf("Percorrendo e apresentando os dados armazenados no vetor....\n");
        printf("========================================\n");
    for(i=0; i<3; i++)
    {
        printf("%-5d %-5d %-30s\n", v[i].x, v[i].y, v[i].nome);
    }

    printf("\n\nAlterando dados da posi��o 1 no vetor...\n\n");
    alteraDados(v,1);

    printf("\n\nPercorrendo o vetor com um ponteiro...\n");
    printf("=========================================\n");
    p = v; //se eu for partir de uma posi��o espec�fica do vetor ou matriz, a� sim preciso colocar "&v[3];" por exemplo.
    printf("%-5d %-5d %-30s\n", p->x, p->y, p->nome);
    p++;
    printf("%-5d %-5d %-30s\n", p->x, p->y, p->nome);
    p++;
    printf("%-5d %-5d %-30s\n", p->x, p->y, p->nome);

    printf("Deseja buscar algum ponto?(0 - n�o , 1 - sim)");
    scanf("%d", &deseja);
    if(deseja == 1)
    {
        r = buscaPonto(v, "Fonte das Rosas");
        printf("O resultado da sua busca � %d", r);
    }
    else
        printf("Saindo do Programa...");

}

void alteraDados(ponto g[], int posicao)
{
    if(posicao >= 0 && posicao <= 2)
    {
        printf("Digite um novo nome para o ponto 1:");
        gets(g[posicao].nome);
    }
}

int buscaPonto(ponto g[], char n[30])
{
    for(i = 0; i < 3; i++)
    {
        if(strcmp(g[i].nome, n) == 0)
            return 1;
    }
    return 0;
}
