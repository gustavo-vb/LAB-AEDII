#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


main()
{
    setlocale(LC_ALL, "Portuguese");

    int v1, v2, v3, *pv;

    printf("Tamanho, em Bytes, da variável v1 = %d\n\n", sizeof(v1));
    printf("Tamanho, em Bytes, da variável pv = %d\n\n", sizeof(pv));

    printf("Endereço da variável v1 = %X %d\n\n", &v1, &v1);
    printf("Endereço da variável v2 = %X %d\n\n", &v2, &v2);
    printf("Endereço da variável v3 = %X %d\n\n", &v3, &v3);
    printf("Endereço da variável pv = %X %d\n\n", &pv, &pv);

    v1 = 100; //vai no endereço onde v1 está e coloque o valor 100.
    v2 = 200; //vai no endereço onde v2 está e coloque o valor 200.
    pv = &v2; //pv aponta para o endereço de v2.

    printf("Endereço para onde pv aponta = %X %d\n\n", pv, pv);

    v3 = v1 * (*pv); //(*pv) conteúdo de memória para onde pv aponta. está entre parênteses pois há o asterisco da multiplicação e do ponteiro.

    printf("Resultado de v1 x o conteúdo de *pv = %d\n\n", v3);

    //em uma mesma linha de código, não usamos "*" e "&" simultaneamente.
}
