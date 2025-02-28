#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
    FILE *f;

    char filename[50] = "teste.txt";
    //ou char filename[50] = ".\\files\\teste.txt"; para guardar os arquivos em uma pasta qualquer.

    char texto[100], letra;

    int tam, count = 0;

    f = fopen(filename, "r"); //"w" cria um arquivo se não houver e, se houver, ele sobrescreve (apaga o existente e cria um novo vazio)

    while(1)
    {
        letra = fgetc(f);

        if(feof(f))
            break;

        texto[count] = letra;
        count++;
    }
    texto[count] = '\0';

    printf("O conteudo do arquivo e: %s", texto);

    rewind(f);


    count = 1;
    while(fgets(texto, 100, f) != NULL)
    {
        printf("A mensagem %d e %s", count, texto);
        count++;
    }

    fclose(f);

}
