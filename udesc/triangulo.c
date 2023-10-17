#include <stdio.h>
int main (void)
{
    float a, b, c;
    printf("lado a: ");
    scanf ("%f", &a);
    printf("lado b: ");
    scanf ("%f", &b);
    printf("lado c: ");
    scanf ("%f", &c);
    if(((a<b+c)&&(b<a+c))&&(c<a+b))
    {
        if((a==b)&&(b==c))
        {
            printf("equilátero\n");
            return 1;
        }
        if(((a!=b)&&(b!=c))&&(c!=a))
        {
            printf("escaleno\n");
            return 1;
        }
        printf("isósceles\n");
        return 1;
    }
    else
    {
        printf("não é triangulo\n");
        return 1;
    }
}