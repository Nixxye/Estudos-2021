#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    n = n%2;
    if(n==0)
    {
        printf("0\n");
    }
    else
    {
        printf("1\n");
    }
}