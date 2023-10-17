#include <stdio.h>
int main(void)
{
    int a = 0;
    int b = 0;
    while(a!=-1)
    {
        scanf("%d", &a);
        if(a==-1)
        {
            return 0;
        }
        scanf("%d", &b);
        if(a==b)
        {
            printf("Quadrado");
            printf("\n");
        }
        else
        {
            printf("Retangulo");
            printf("\n");
        }
        printf("Area:%i.0", a*b);
        printf("\n");
    }
}