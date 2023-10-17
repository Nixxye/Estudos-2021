#include <stdio.h>
int main (void)
{
    float c;
    printf("Escreva o valor na escala farenheit:\n");
    scanf("%f", &c);
    c = (c-32)*5/9;
    printf("Valor em celsius: %.2f\n", c);
    return 1;
}