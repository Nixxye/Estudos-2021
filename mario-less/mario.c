#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int j = 1;
    do
    {
        j = get_int("Height:");
    }
    while (!(j>0));
            for (int i = 0; i<j; i++)
            {
                for(int l = j-i-1; l>0; l--)
                {
                    printf(" ");
                }
                for (int n = 0; n<=i; n++)
                {
                    printf("#");
                }
            printf("\n");
            }
}