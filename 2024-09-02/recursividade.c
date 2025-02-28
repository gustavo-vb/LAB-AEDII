#include<stdio.h>
#include<stdlib.h>

int multiplicacaoSomaRecursiva(int n1, int n2);

main()
{
    int x, y, p;


    printf("Multiplicacao usando soma recursiva\n");
    printf("===================================\n\n");
    printf("Digite o primeiro numero = ");
    scanf("%d", &x);
    printf("Digite o segundo numero = ");
    scanf("%d", &y);


    p = multiplicacaoSomaRecursiva(x,y);
    printf("Resultado = %d\n\n", p);

}

int multiplicacaoSomaRecursiva(int n1, int n2)
{

    if(n2 == 0)
        return 0;

    return (n1 + multiplicacaoSomaRecursiva(n1, n2 - 1));

}
