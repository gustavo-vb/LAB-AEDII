#include <stdio.h>
#include <stdlib.h>

main()
{
    FILE *arquivo;
    char caractere;
    int contador = 0, linhas = 0;;

    printf("Abrindo o arquivo para leitura...\n\n");
    arquivo = fopen("nomes.txt", "rt");

    if(arquivo == NULL)
    {
        printf("Erro na funcao FOPEN (Arquivo nao encontrado)\n\n");
        exit(0);
    }

    printf("Processando o arquivo textual...\n\n");

    while(!feof(arquivo))
    {
        caractere = fgetc(arquivo);

        if(caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u')
        {
            contador++;
        }

        if(caractere == '\n')
        {
            linhas++;
        }

        printf("%c", caractere);
    }

    printf("\n\nha %d vogais no arquivo lido.\n", contador);
    printf("ha %d linhas no arquivo lido.\n", linhas+1); //"+1" pois no ultimo nome do arquivo nao foi dado enter, sendo assim, a linha nao existe e nao é contada por nao ter '\n'

    fclose(arquivo);
}
