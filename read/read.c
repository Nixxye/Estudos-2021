#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string t = get_string("Text: ");
    int j = 0;
    float w = 1;
    float l = 0;
    int x = 0;
    float s = 0;
    while (t[j]!='\0')
    {
        x = t[j];
        if ((x>=65 && x<=90)||(x>=97 && x<=122))
        {
            l++;//counting letters
        }
        if (x==32)
        {
            w++;//counting words
        }
        if (x==33|| x==46||x==63)
        {
            s++;//counting sentences
        }
        j++;
    }

    float L = (l/w)*100;
    float S = (s/w)*100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int h = index*100;
    int g = index;
    if (h%100>=50)
    {
        g++;
    }
    if (g>=1 && g<16)
    {
        printf("Grade %i\n", g);
    }
    if (g>=16)
    {
        printf("Grade 16+\n");
    }
    if (g<1)
    {
        printf ("Before grade 1\n");
    }
    //0.0588 * L - 0.296 * S - 15.8
}