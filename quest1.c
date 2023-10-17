#include <stdio.h>
#include <math.h>
int main()
    {
    double a = 0.0;
    double b, a1, b1, d;
    while(a>=0)
    {
    printf("Entre com valores:\n");
    printf("(Par 1) ");
    scanf("%lf", &a);
    if(a<0)
    {
        printf("Fim do programa\n");
        return 1;
    }
    scanf("%lf", &b);
    printf("(Par 1) ");
    scanf("%lf %lf", &a1,&b1);
    d = sqrt(((a-a1)*(a-a1))+((b-b1)*(b-b1)));
    printf("Distância = %.1lf\n", d);
    }
    return 0;
}