#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void)
{
    string s[4];
    for(int m = 0; m<5; m++)
    {
        s[m] = get_string("x");
    }
    s[2] = " ";
    for(int m = 0; m<5; m++)
    {
        printf("%i.%s\n", m ,s[m]);
    }
}
