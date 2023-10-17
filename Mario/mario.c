#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int j = 1;
    do
    {
        j = get_int("Height:");
        for (int i = 0; i<j; i++)
        {
            for(int l= j-i-1; l>0; l--)
            {
                printf(" ");
            }
            for(int k = 0; k<=i; k++)
            {
                printf("#");
            }
            printf(" ");
            for(int d = 0; d<=i; d++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    while(!(j>0));
}