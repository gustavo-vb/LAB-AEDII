#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


main()
{
    setlocale(LC_ALL, "Portuguese");

    int v1, v2, v3, *pv;

    printf("Tamanho, em Bytes, da vari�vel v1 = %d\n\n", sizeof(v1));
    printf("Tamanho, em Bytes, da vari�vel pv = %d\n\n", sizeof(pv));

    printf("Endere�o da vari�vel v1 = %X %d\n\n", &v1, &v1);
    printf("Endere�o da vari�vel v2 = %X %d\n\n", &v2, &v2);
    printf("Endere�o da vari�vel v3 = %X %d\n\n", &v3, &v3);
    printf("Endere�o da vari�vel pv = %X %d\n\n", &pv, &pv);

    v1 = 100; //vai no endere�o onde v1 est� e coloque o valor 100.
    v2 = 200; //vai no endere�o onde v2 est� e coloque o valor 200.
    pv = &v2; //pv aponta para o endere�o de v2.

    printf("Endere�o para onde pv aponta = %X %d\n\n", pv, pv);

    v3 = v1 * (*pv); //(*pv) conte�do de mem�ria para onde pv aponta. est� entre par�nteses pois h� o asterisco da multiplica��o e do ponteiro.

    printf("Resultado de v1 x o conte�do de *pv = %d\n\n", v3);

    //em uma mesma linha de c�digo, n�o usamos "*" e "&" simultaneamente.
}
