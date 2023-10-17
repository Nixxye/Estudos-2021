#include <cs50.h>
#include <string.h>
#include <stdio.h>

int count_letters(string text);//funções
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string s = get_string("Text:\n");
    int w = count_words(s);//criando variável para não ter que chamar a função duas vezes
    float index = 5.88 * count_letters(s) / w - (29.6 * count_sentences(s)) / w - 15.8;
    int r = index;//processo de arredondar para o inteiro mais próximo-precisão de duas casas
    int l = index * 100;
    if(l % 100 >= 50)
    {
        r++;
    }
    if(r < 1)//printar resultado
    {
        printf("Before Grade 1\n");
    }
    else
    {
        if(r >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", r);
        }
    }
}
int count_letters(string text)//função de contagem de letras
{
    int n = strlen(text);
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            c++;
        }
    }
    return c;
}
int count_words(string text)//função de contagem de palavras
{
    int n = strlen(text);
    int c = 1;//o texto sempre vai ter uma palavra - conta os próximos espaços para determinar a quantidade - 1 espaço = duas palavras
    for(int i = 0; i < n; i++)
    {
        if(text[i] == 32)
        {
            c++;
        }
    }
    return c;
}
int count_sentences(string text)//função de contagem de sentenças - por meio da pontuação
{
    int n = strlen(text);
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        if(text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            c++;
        }
    }
    return c;
}