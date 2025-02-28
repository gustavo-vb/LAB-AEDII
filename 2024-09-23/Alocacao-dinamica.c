#include<stdlib.h>
#include<stdio.h>

typedef struct No
{
    int dado;
    struct No *ligacao;
}no;

main()
{
   no *p1 = NULL, *p2 = NULL; //Aponta para o codigo zero da tabela ASCII que e NULL.

   printf("Endereco do ponteiro p1 = %d\n", &p1);
   printf("Endereco do ponteiro p2 = %d\n", &p2);
   printf("======================================\n\n");

   printf("Endereco para onde p1 aponta = %d\n", p1);
   printf("Endereco para onde p2 aponta = %d\n", p2);
   printf("======================================\n\n");

   printf("Alocando os nos na area de heap...\n\n");

   p1 = (no*) malloc(sizeof(no));
   if(p1 == NULL)
   {
       printf("Sem Memoria!");
       exit(1);
   }

   printf("Endereco para onde p1 aponta apos malloc = %d\n", p1);
   p1->dado = 10;
   p1->ligacao = NULL;

   p2 = (no*) malloc(sizeof(no));
   if(p2 == NULL)
   {
       printf("Sem Memoria!");
       exit(1);
   }

   printf("Endereco para onde p2 aponta apos malloc = %d\n", p2);
   p2->dado = 20;
   p2->ligacao = NULL;

   printf("=========================================================\n\n");

   printf("Ligando os dois nos...\n\n");
   p1->ligacao = p2;
   p2->ligacao = p1;

   printf("Apresentando os dados dos nos...\n\n");
   printf("%d esta em primeiro no, e %d esta em segundo no. Se esse numero aqui --> %d <-- for 10, tudo deu certo e prova que e circular.\n", p1->dado, p1->ligacao->dado, p1->ligacao->ligacao->dado);




}
