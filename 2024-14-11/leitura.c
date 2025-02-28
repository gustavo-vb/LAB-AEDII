#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char cor[15];
    float coordX, coordY;
}Ponto;

int lePonto(FILE *f, Ponto *p);

Ponto cadastraPonto();
int escrevePonto(FILE *f);


main()
{

    Ponto p;
    int n;

    FILE *f = fopen("file_color.txt", "a+");

    if(f==NULL)
    {
        printf("Erro ao abrir o arquivo...\n");
        exit(0);
    }

    printf("pontos registrados no arquivo: \n");
    while(lePonto(f, &p) > 0)
    {
        printf("%d %s %0.1f %0.1f\n", p.id, p.cor, p.coordX, p.coordY);
    }

    printf("---------------Registrando pontos------------------\n");
    printf("Deseja registrar quantos pontos? = ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        escrevePonto(f);
    }

    fclose(f);

    return 0;
}

int lePonto(FILE *f, Ponto *p)
{
    return fscanf(f, "%d %s %f %f", &p->id, p->cor, &p->coordX, &p->coordY);
}

Ponto cadastraPonto()
{
    Ponto p;

    printf("Digite as informacoes do ponto: \n");
    printf("Id: ");
    scanf("%d", &p.id);

    getchar();

    printf("Cor: ");
    scanf("%s", p.cor);


    printf("Coord. X: ");
    scanf("%f", &p.coordX);


    printf("Coord. Y: ");
    scanf("%f", &p.coordY);


    return p;
}

int escrevePonto(FILE *f)
{
    Ponto p = cadastraPonto();

    return fprintf(f, "%d %s %f %f\n", p.id, p.cor, p.coordX, p.coordY);
}
