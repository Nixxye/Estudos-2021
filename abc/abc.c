#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf ("./abc ABC\n");
        return 1
    }
    printf("%i\n", argc);
    string k = argv[1];
    int j = 0;
    while(k[j]!='\0')
    {
        j++;
    }
    if(j!=25)
    {
        printf("Key must contain 26 characters.\n");
        return 1
    }
    int l[j];
    for(j = 0;k[j]!='\0';j++)
    {
        l[j] = k[j];
        if ((l[j]>=65 && l[j]<=90)||(l[j]>=97 && l[j]<=122))
        {
            if(l[j]>=65 && l[j]<=90)//maiúsculas
            {
                l[j] = l[j] - 65;
            }
            if(l[j]>=97 && l[j]<=122)//maiúsculas
            {
                l[j] = l[j] - 97;
            }
        }
        else
        {
            //símbolos
        }
    }

    string t = get_string("Text: ");

    j=0;
    while(t[j]!='\0')
    {
        j++;
    }
    int n[j];
    char f[j];

    for (int m = 0; t[m]!='\0'; m++)
    {
        n[m] = t[m];
        if((n[m]>=65 && n[m]<=90)||(n[m]>=97 && n[m]<=122))
        {
            if(n[m]>=65 && n[m]<=90)
            {
                n[m] = 65 + l[n[m]-65];
            }
            if(n[m]>=97 && n[m]<=122)
            {
                n[m] = 97 + l[n[m]-97];
            }
        f[m]=n[m];
        }
        else
        {
            f[m] = t[m];
        }
        printf("%c", f[m]);
    }
    printf("\n");


}