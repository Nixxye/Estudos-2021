#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long valor = 0;
    while(valor <=0)
    {
        valor = get_long("Enter credit card number:");
    }

    long x = 10000000000000000;
    int n = 17;
    int s = 0;
    int o = 0;
    long m = 0;
    while (m==0)
    {
        m = valor % x;
        x = x / 10;
        m = m / x;
        n=n-1;
    }

    printf("número de dígitos:%i \n", n);
    int s15 = valor % 1000000000000000 / 10000000000000;
    if ((n == 15) && (s15 == 37 || s15 == 34))
    {
         printf("AMEX\n");
    }
    int s16 = valor % 10000000000000000 / 100000000000000;
    if ((n == 16) && (s16 <= 55 && s16 >= 51))
    {
        printf("MASTERCARD\n");
    }
    int s13 = valor % 10000000000000 / 1000000000000;
    int s161 = valor % 10000000000000000 / 1000000000000000;
    if (((n == 16) && (s161 == 4))|| ((n == 13)&&(s13 == 4)))
    {
        printf("VISA\n");
    }

    long u = 100;
    long t = 10;

    for(int y=n; y>0;y=y-2)
    {
        long l = (valor % t)/(t/10);
        t = t*100;
        o = o+l;
        printf("casas ímpares:%li\n", l);
        printf("o=%i\n", o);
    }

    n = n / 2;
    for (int i=0;i<n;i++)
    {
        long p = valor % u;
        p = p /(u/10);
        u = u*100;
        printf("%li \n", p);
        if(p<5)
        {
            p=p*2;
            s = s+p;
        }
        else
        {
            p=p*2;
            p=(p%10);
            printf("segunda casa de p:%li\n", p);
            s = s+p+1;
        }
        printf("sum %i \n", s);
    }
    int v = s+o;
    printf("soma final:%i\n", v);
    int r = 5;
    int e = 10000;
    int b = 0;
    while (b==0)
    {
        b = v % e;
        e = e / 10;
        b = b / e;
        r=r-1;
    }
    printf("r=%i\n", r);
    int ç = 1;
    for(r--;r>0;r--)
    {
        ç = ç*10;
    }
    v = v%ç;
    printf("vapo:%i\n", v);
    if(v==0)
    {
        printf("valid\n");
    }
    else
    {
        printf("invalid\n");
    }
}