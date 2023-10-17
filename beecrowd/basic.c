#include <stdio.h>
#include <math.h>

int main(void)
{
    double A;
    double B;
    double C;
    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);
    double delta = (B*B)-4*A*C;
    printf("%lf\n", delta);
    if((delta<0)||(A==0))
    {
        printf("Impossivel calcular\n");
        return 0;
    }
    double r1 = (-B+(sqrt(delta)))/(2*A);
    double r2 = (-B-(sqrt(delta)))/(2*A);
    printf("R1 = %.5f\n", r1);
    printf("R2 = %.5f\n", r2);
}