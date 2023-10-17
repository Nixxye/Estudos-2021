#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned char buffer[512];
    FILE *input_file;//cria input_file
    FILE *output_file = NULL;//cria output_file
    input_file = fopen("card.raw", "r"); // abre o arquivo no modo de leitura
    int n = 0;//number of jpegs
    char *filename = malloc(8 * sizeof(char));//aloca memória o suficiente para
    if(input_file==NULL)
    {
        printf("ERRORRRR\n");
        return 1;
    }
    while(fread(buffer, sizeof(char), 512, input_file) == 512)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg",n);//cria o arquivo jpeg
            output_file = fopen(filename, "w");//abre o arquivo jpeg em modo de escrita
            n++;//contagem de jpeg + 1
        }
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);//copia os elementos do buffer para o arquivo jpeg
        }

    }
    fclose(input_file);
    free(filename);
    fclose(output_file);
}
