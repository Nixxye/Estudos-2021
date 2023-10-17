#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    string f = argv[1];
    int g = 0;
    int j = 0;

    while (f[j]!='\0')
    {
        g = f[j];

        if (((g>57 ||(g<48 && g>45)) ||(g<45)) || ((argv[1] ==NULL) || (argv[2]!=NULL)))
        {
            printf ("Usage: ./caesar key\n");
            return 1;
        }
        j++;
    }
    int c = (atoi(argv[1]))%26;
    printf("C=%i\n", c);



            j = 0;

            string t = get_string("plaintext:: ");
            while(t[j]!='\0')
            {
                j++;
            }
            char l[j];
            j = 0;
            for (j = 0;t[j]!='\0';j++)
            {
                int i = t[j];
                if ((i<=122 && i>=97)||(i<=90 && i>=65))
                {
                    if(i<=122 && i>=97)//minúsculas
                    {
                        i = i + c;
                        if(i>122)
                        {
                            i = ((i % 122)+96);
                        }
                        if(i<97)
                        {
                            i = (123-(97-i));
                        }
                        l[j]=i;
                    }
                    if(i<=90 && i>=65)//maiúsculas
                    {
                        i = i + c;
                        if(i>90)
                        {
                            i = ((i % 90)+64);
                        }
                        if(i<65)
                        {
                            i = (91-(65-i));
                        }
                        l[j]=i;
                    }
                }
                else//outros símbolos
                {
                    l[j]=t[j];
                }
            }


            int k = 0;
            printf("ciphertext: ");
            for(k=0; k<j;k++)
            {
                printf("%c",l[k]);
            }
            printf("\n");

}
